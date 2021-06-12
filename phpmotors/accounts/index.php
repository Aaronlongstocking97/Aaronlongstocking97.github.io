<?php
/*
* Accounts Controller
*/

// Create or access a Session
session_start();

// Get the database connection file
require_once '../library/connections.php';
// Get the phpmotors model for use as needed
require_once '../model/main-model.php';
// Get the accounts model
require_once '../model/accounts-model.php';
// Get the functions library
require_once '../library/functions.php';

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
            setcookie('firstname', $clientFirstname, strtotime('+1 year'), '/');
            $message = "<p>Thanks for registering $clientFirstname. 
            Please use your email and password to login.</p>";
            include '../view/login.php';
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
        $clientEmail = filter_input(
            INPUT_POST,
            'clientEmail',
            FILTER_SANITIZE_EMAIL
        );
        $clientPassword = filter_input(
            INPUT_POST,
            'clientPassword',
            FILTER_SANITIZE_STRING
        );

        $clientEmail = checkEmail($clientEmail);

        // Check for missing data
        if (empty($clientEmail) || empty($clientPassword)) {
            $message = '<p>Please provide information for all 
            empty form fields.</p>';
            include '../view/login.php';
            exit;
        }
        break;

    case 'login':
        include '../view/login.php';
        break;
    case 'registration':
        include '../view/registration.php';
        break;
    case 'home':
        include '../view/home.php';
        break;
    default:
        include '../view/login.php';
}
