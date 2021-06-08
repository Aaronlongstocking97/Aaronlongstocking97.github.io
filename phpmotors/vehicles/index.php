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

// Get the array of classifications
$classifications = getClassifications();

// Build a navigation bar using the $classifications array
$navList = '<ul>';
$navList .= "<li><a href='/phpmotors/index.php' title='View 
the PHP Motors home page'>Home</a></li>";
foreach ($classifications as $classification) {
    $navList .= "<li><a href='/phpmotors/index.php?action="
        . urlencode($classification['classificationName'])
        . "' title='View our $classification[classificationName] 
    product line'>$classification[classificationName]</a></li>";
}
$navList .= '</ul>';

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
            $message = '<p>Please provide information for all empty form fields.</p>';
            include '../view/add-classification.php';
            exit;
        }

        $addClassOutcome = addClassification($classificationName);

        // Check and report the result
        if ($addClassOutcome === 1) {
            header('Location: /phpmotors/view/vehicle-man.php');
            exit;
        } else {
            $message = "<p>Please provide information for all empty form fields.</p>";
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

        // Check for missing data
        if (empty($invMake) || empty($invModel) || empty($invDescription) || empty($invImage) || empty($invThumbnail) || empty($invPrice) || empty($invStock) || empty($invColor)) {
            $message = '<p>Please provide information for all empty form fields.</p>';
            include '../view/add-vehicle.php';
            exit;
        }

        // Send the data to the model
        $addVehicleOutcome = addVehicle($invMake, $invModel, $invDescription, $invImage, $invThumbnail, $invPrice, $invStock, $invColor);

        // Check and report the result
        if ($addVehicleOutcome === 1) {
            $message = "<p>The $invMake $invModel was added successfully!</p>";
            include '../view/add-vehicle.php';
            exit;
        } else {
            $message = "<p>Please provide information for all empty form fields.</p>";
            include '../view/add-vehicle.php';
            exit;
        }
        break;
    case 'vehiclesMan':
        include '../view/vehicle-man.php';
        break;
    case 'home':
        include '../view/home.php';
        break;
    default:
        include '../view/vehicle-man.php';
}
