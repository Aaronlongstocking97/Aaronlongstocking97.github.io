<?php
/*
* Vehicles Controller
*/

// Get the database connection file
require_once '../library/connections.php';
// Get the phpmotors model for use as needed
require_once '../model/main-model.php';
// Get the vehicles model
require_once '../model/vehicles-model.php';
// Get the functions library
require_once '../library/functions.php';

// Get the array of classifications
$classifications = getClassifications();
// Build a navigation bar using the $classifications array
$navList = buildNavigation($classifications);

// Build the select list
$classifList = '<select name="classificationId">';
foreach ($classifications as $classification) {
    $classifList .= "<option value='
        '$classification[classificationId]'>
        $classification[classificationName]</option>";
}
$classifList .= '</select>';



// $carClassifications = "<select name='classificationId' id='carClassifications'>";
// $carClassifications .= '<option>Choose Car Classification</option>';
// foreach ($classifications as $classification) {
//     $carClassifications .= "<option value="
//         . $classification['classificationId'] . ">"
//         . $classification['classificationName'] . "</option>";
// }
// $carClassifications .= '</select>';

// Get the value from the action name - value pair
$action = filter_input(INPUT_POST, 'action');
if ($action == NULL) {
    $action = filter_input(INPUT_GET, 'action');
}

switch ($action) {
        // Code to deliver the views will be here

    case 'addClass':
        $classificationName = filter_input(INPUT_POST, 'classificationName');
        // Check for missing data
        if (empty($classificationName)) {
            $message = '<p>Please provide information for all empty 
            form fields.</p>';
            include '../view/add-classification.php';
            exit;
        }

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
    case 'addVehicle':
        // Filter and store the data
        $invMake = filter_input(INPUT_POST, 'invMake');
        $invModel = filter_input(INPUT_POST, 'invModel');
        $invDescription = filter_input(INPUT_POST, 'invDescription');
        $invImage = filter_input(INPUT_POST, 'invImage');
        $invThumbnail = filter_input(INPUT_POST, 'invThumbnail');
        $invPrice = filter_input(INPUT_POST, 'invPrice');
        $invStock = filter_input(INPUT_POST, 'invStock');
        $invColor = filter_input(INPUT_POST, 'invColor');
        $classificationId = filter_input(INPUT_POST, 'classificationId');

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

    case 'classification':
        include '../view/add-classification.php';
        break;
    case 'vehicle':
        include '../view/add-vehicle.php';
        break;
    case 'home':
        include '../view/home.php';
        break;
    default:
        include '../view/vehicle-man.php';
}
