<?php
/*
* Vehicles Controller
*/

// Create or access a Session
session_start();

require_once '../initialize.php';

// Get the array of classifications
$classifications = getClassifications();
// Build a navigation bar using the $classifications array
$navList = buildNavigation($classifications);

// Build the select list
// $classifList = '<select name="classificationId">';
// foreach ($classifications as $classification) {
//     $classifList .= "<option value='
//         '$classification[classificationId]'>
//         $classification[classificationName]</option>";
// }
// $classifList .= '</select>';

// Get the value from the action name - value pair
$action = filter_input(INPUT_POST, 'action');
if ($action == NULL) {
    $action = filter_input(INPUT_GET, 'action');
}

switch ($action) {
        // Code to deliver the views will be here

    case 'class-page':
    case 'add-Class':
        $classificationName = trim(filter_input(
            INPUT_POST,
            'classificationName',
            FILTER_SANITIZE_STRING
        ));

        $classifCount = checkClassificationName($classificationName);

        // Check for missing data
        if (empty($classifCount)) {
            $message = '<p>Please provide information for all empty 
            form fields.</p>';
            include '../view/add-classification.php';
            exit;
        }

        // Send the data to the model
        $addClassOutcome = addClassification($classificationName);

        // Check and report the result
        if ($addClassOutcome === 1) {
            header('Location: /phpmotors/vehicles/index.php');
            exit;
        } else {
            $message = "<p>Please provide information for all empty 
            form fields.</p>";
            include '../view/add-classification.php';
            exit;
        }

        break;
    case 'add-Vehicle':
        // Filter and store the data
        $invMake = trim(filter_input(
            INPUT_POST,
            'invMake',
            FILTER_SANITIZE_STRING
        ));
        $invModel = trim(filter_input(
            INPUT_POST,
            'invModel',
            FILTER_SANITIZE_STRING
        ));
        $invDescription = trim(filter_input(
            INPUT_POST,
            'invDescription',
            FILTER_SANITIZE_STRING
        ));
        $invImage = trim(filter_input(
            INPUT_POST,
            'invImage',
            FILTER_SANITIZE_STRING
        ));
        $invThumbnail = trim(filter_input(
            INPUT_POST,
            'invThumbnail',
            FILTER_SANITIZE_STRING
        ));
        $invPrice = trim(filter_input(
            INPUT_POST,
            'invPrice',
            FILTER_SANITIZE_NUMBER_FLOAT,
            FILTER_FLAG_ALLOW_FRACTION
        ));
        $invStock = trim(filter_input(
            INPUT_POST,
            'invStock',
            FILTER_SANITIZE_NUMBER_INT
        ));
        $invColor = trim(filter_input(
            INPUT_POST,
            'invColor',
            FILTER_SANITIZE_STRING
        ));
        $classificationId = trim(filter_input(
            INPUT_POST,
            'classificationId',
            FILTER_SANITIZE_NUMBER_INT
        ));

        // Check for missing data
        if (
            empty($invMake) || empty($invModel) || empty($invDescription)
            || empty($invImage) || empty($invThumbnail) || empty($invPrice)
            || empty($invStock) || empty($invColor) || empty($classificationId)
        ) {
            $message = '<p>Please provide information for all empty 
            form fields.</p>';
            include '../view/add-vehicle.php';
            exit;
        }

        // Send the data to the model
        $addVehicleOutcome = addVehicle(
            $invMake,
            $invModel,
            $invDescription,
            $invImage,
            $invThumbnail,
            $invPrice,
            $invStock,
            $invColor,
            $classificationId
        );

        // Check and report the result
        if ($addVehicleOutcome === 1) {
            $message = "<p>The $invMake $invModel was added successfully!</p>";
            include '../view/add-vehicle.php';
            exit;
        } else {
            $message = "<p>Please provide information for all empty 
            form fields.</p>";
            include '../view/add-vehicle.php';
            exit;
        }

        include '../view/add-classification.php';
        break;
    case 'vehicle-page':
        include '../view/add-vehicle.php';
        break;
    case 'home':
        include '../view/home.php';
        break;
    case 'getInventoryItems':
        /* * ********************************** 
        * Get vehicles by classificationId 
        * Used for starting Update & Delete process 
        * ********************************** */

        // Get the classificationId 
        $classificationId = filter_input(INPUT_GET, 'classificationId', FILTER_SANITIZE_NUMBER_INT);
        // Fetch the vehicles by classificationId from the DB 
        $inventoryArray = getInventoryByClassification($classificationId);
        // Convert the array to a JSON object and send it back 
        echo json_encode($inventoryArray);
        break;
    case 'mod':
        $invId = filter_input(INPUT_GET, 'invId', FILTER_VALIDATE_INT);
        $invInfo = getInvItemInfo($invId);
        if (count($invInfo) < 1) {
            $message = 'Sorry, no vehicle information could be found.';
        }
        include '../view/vehicle-update.php';
        exit;
        break;
    case 'updateVehicle':
        $classificationId = filter_input(INPUT_POST, 'classificationId', FILTER_SANITIZE_NUMBER_INT);
        $invMake = filter_input(INPUT_POST, 'invMake', FILTER_SANITIZE_STRING);
        $invModel = filter_input(INPUT_POST, 'invModel', FILTER_SANITIZE_STRING);
        $invDescription = filter_input(INPUT_POST, 'invDescription', FILTER_SANITIZE_STRING);
        $invImage = filter_input(INPUT_POST, 'invImage', FILTER_SANITIZE_STRING);
        $invThumbnail = filter_input(INPUT_POST, 'invThumbnail', FILTER_SANITIZE_STRING);
        $invPrice = filter_input(INPUT_POST, 'invPrice', FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);
        $invStock = filter_input(INPUT_POST, 'invStock', FILTER_SANITIZE_NUMBER_INT);
        $invColor = filter_input(INPUT_POST, 'invColor', FILTER_SANITIZE_STRING);
        $invId = filter_input(INPUT_POST, 'invId', FILTER_SANITIZE_NUMBER_INT);

        if (
            empty($classificationId) || empty($invMake) || empty($invModel)
            || empty($invDescription) || empty($invImage) || empty($invThumbnail)
            || empty($invPrice) || empty($invStock) || empty($invColor)
        ) {
            $message = '<p>Please complete all information for the item! Double check the classification of the item.</p>';
            include '../view/vehicle-update.php';
            exit;
        }

        $updateResult = updateVehicle($invMake, $invModel, $invDescription, $invImage, $invThumbnail, $invPrice, $invStock, $invColor, $classificationId, $invId);
        if ($updateResult) {
            $message = "<p class='notice'>Congratulations, the $invMake $invModel was successfully updated.</p>";
            $_SESSION['message'] = $message;
            header('location: /phpmotors/vehicles/');
            exit;
        } else {
            $message = "<p class='notice'>Error. the $invMake $invModel was not updated.</p>";
            include '../view/vehicle-update.php';
            exit;
        }
        break;
    case 'del':
        $invId = filter_input(INPUT_GET, 'invId', FILTER_VALIDATE_INT);
        $invInfo = getInvItemInfo($invId);
        if (count($invInfo) < 1) {
            $message = 'Sorry, no vehicle information could be found.';
        }
        include '../view/vehicle-delete.php';
        exit;
        break;
    case 'deleteVehicle':
        $invMake = filter_input(INPUT_POST, 'invMake', FILTER_SANITIZE_STRING);
        $invModel = filter_input(INPUT_POST, 'invModel', FILTER_SANITIZE_STRING);
        $invId = filter_input(INPUT_POST, 'invId', FILTER_SANITIZE_NUMBER_INT);

        $deleteResult = deleteVehicle($invId);
        if ($deleteResult) {
            $message = "<p class='notice'>Congratulations the, $invMake $invModel was	successfully deleted.</p>";
            $_SESSION['message'] = $message;
            header('location: /phpmotors/vehicles/');
            exit;
        } else {
            $message = "<p class='notice'>Error: $invMake $invModel was not
                    deleted.</p>";
            $_SESSION['message'] = $message;
            header('location: /phpmotors/vehicles/');
            exit;
        }
        break;
    default:
        $classificationList = buildClassificationList($classifications);
        include '../view/vehicle-man.php';
        exit;
        break;
}
