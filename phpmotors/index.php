<?php
// This is the main controller

require_once './library/connections.php';
// Get the main model for use as needed
require_once './model/main-model.php';

// Get the array of classifications from DB using model
$classifications = getClassifications();

// Build a navigation bar using the $classifications array
$navList = '<ul>';
$navList .= "<li><a href='/phpmotors/index.php' title='View 
the PHP Motors home page'>Home</a></li>";
foreach ($classifications as $classification) {
    $navList .= "<li><a href='/phpmotors/index.php
    action=" . urlencode($classification['classificationName'])
        . "' title='View our $classification[classificationName] 
    product line'>$classification[classificationName]</a></li>";
}
$navList .= '</ul>';

$action = filter_input(INPUT_GET, 'action');
if ($action == NULL) {
    $action = filter_input(INPUT_POST, 'action');
}

switch ($action) {
    case 'template':
        include './view/template.php';
        break;
    default:
        include './view/home.php';
}
