<?php
/*
* Accounts Controller
*/

// Create or access a Session
session_start();

require_once '../initialize.php';

// Get the array of classifications
$classifications = getClassifications();
// Build a navigation bar using the $classifications array
$navList = buildNavigation($classifications);

// Get the value from the action name - value pair
$action = filter_input(INPUT_POST, 'action');
if ($action == NULL) {
    $action = filter_input(INPUT_GET, 'action');
}

switch ($action) {
        // Code to deliver the views will be here

    case 'register':
        // Filter and store the data
        $clientFirstname = trim(filter_input(
            INPUT_POST,
            'clientFirstname',
            FILTER_SANITIZE_STRING
        ));
        $clientLastname = trim(filter_input(
            INPUT_POST,
            'clientLastname',
            FILTER_SANITIZE_STRING
        ));
        $clientEmail = trim(filter_input(
            INPUT_POST,
            'clientEmail',
            FILTER_SANITIZE_EMAIL
        ));
        $clientPassword = trim(filter_input(
            INPUT_POST,
            'clientPassword',
            FILTER_SANITIZE_STRING
        ));

        $clientEmail = checkEmail($clientEmail);
        $checkPassword = checkPassword($clientPassword);

        // Check for existing email
        $existingEmail = checkExistingEmail($clientEmail);

        // deal with existing email during registration
        if ($existingEmail) {
            $message = '<p class="notice">That email address 
            already exists. Do you want to login instead?</p>';
            include '../view/login.php';
            exit;
        }

        // Check for missing data
        if (
            empty($clientFirstname) || empty($clientLastname)
            || empty($clientEmail) || empty($checkPassword)
        ) {
            $message = '<p>Please provide information for all 
            empty form fields.</p>';
            include '../view/registration.php';
            exit;
        }

        // Hash the checked password
        $hashedPassword = password_hash($clientPassword, PASSWORD_DEFAULT);

        // Send the data to the model
        $regOutcome = regClient(
            $clientFirstname,
            $clientLastname,
            $clientEmail,
            $hashedPassword
        );

        // Check and report the result
        if ($regOutcome === 1) {
            $_SESSION['message'] = "Thanks for registering $clientFirstname. 
            Please use your email and password to login.";
            header('Location: /phpmotors/accounts/?action=login');
            exit;
        } else {
            $message = "<p>Sorry $clientFirstname, but the registration 
            failed. Please try again.</p>";
            include '../view/registration.php';
            exit;
        }
        break;

    case 'Sign-in':
        // Filter and store the data
        $clientEmail = trim(filter_input(
            INPUT_POST,
            'clientEmail',
            FILTER_SANITIZE_EMAIL
        ));
        $clientEmail = checkEmail($clientEmail);

        $clientPassword = trim(filter_input(
            INPUT_POST,
            'clientPassword',
            FILTER_SANITIZE_STRING
        ));
        $checkPassword = checkPassword($clientPassword);

        // Run basic checks, return if errors
        if (empty($clientEmail) || empty($checkPassword)) {
            $message = '<p class="notice">Please provide a 
            valid email address and password.</p>';
            include '../view/login.php';
            exit;
        }

        // A valid password exists, proceed with the login process
        // Query the client data based on the email address
        $clientData = getClient($clientEmail);
        // Compare the password just submitted against
        // the hashed password for the matching client
        $hashCheck = password_verify($clientPassword, $clientData['clientPassword']);
        // If the hashes don't match create an error
        // and return to the login view
        if (!$hashCheck) {
            $message = '<p class="notice">Please check your password and try again.</p>';
            include '../view/login.php';
            exit;
        }
        // A valid user exists, log them in
        $_SESSION['loggedin'] = TRUE;
        // Remove the password from the array
        // the array_pop function removes the last
        // element from an array
        array_pop($clientData);
        // Store the array into the session
        $_SESSION['clientData'] = $clientData;
        // Send them to the admin view
        include '../view/admin.php';
        exit;
        break;

    case 'login':
        include '../view/login.php';
        break;
    case 'registration':
        include '../view/registration.php';
        break;
    case 'client-update':
        $clientId = filter_input(INPUT_GET, 'clientId', FILTER_VALIDATE_INT);
        $clientInfo = getClientInfo($clientId);
        if (count($clientInfo) < 1) {
            $message = 'Sorry, no account information could be found.';
        }
        include '../view/client-update.php';
        exit;
        break;
    case 'updateClient':
        $clientFirstname = filter_input(INPUT_POST, 'clientFirstname', FILTER_SANITIZE_STRING);
        $clientLastname = filter_input(INPUT_POST, 'clientLastname', FILTER_SANITIZE_STRING);
        $clientEmail = filter_input(INPUT_POST, 'clientEmail', FILTER_SANITIZE_EMAIL);
        $clientId = filter_input(INPUT_POST, 'clientId', FILTER_SANITIZE_NUMBER_INT);

        $clientEmail = checkEmail($clientEmail);

        // Check for existing email
        $existingEmail = checkExistingEmail($clientEmail);



        if (
            empty($clientFirstname) || empty($clientLastname) || empty($existingEmail)
            || empty($clientId)
        ) {
            $message = '<p>Please provide information for all empty form fields.</p>';
            include '../view/client-update.php';
            exit;
        }

        // deal with existing email during registration
        if ($existingEmail) {
            $message = '<p class="notice">That email address 
            already exists. Do you want to login instead?</p>';
            include '../view/client-update.php';
            exit;
        }

        $updateClientResult = updateClient($clientFirstname, $clientLastname, $clientEmail, $clientId);
        $clientData = getClientInfo($clientId);
        array_pop($clientData);
        $_SESSION['clientData'] = $clientData;
        if ($updateClientResult) {
            $message = "<p class='notice'>Administrator, your information has been updated.</p>";
            $_SESSION['message'] = $message;
            header('location: /phpmotors/accounts/');
            exit;
        } else {
            $message = "<p class='notice'>Sorry Administrator, we could not update your account information. Please try agin.</p>";
            include '../view/client-update.php';
            exit;
        }
        break;
    case 'home':
        include '../view/home.php';
        break;
    case 'Logout':
        session_unset();
        session_destroy();
        header('Location: /phpmotors/');
        break;
    default:
        include '../view/admin.php';
}
