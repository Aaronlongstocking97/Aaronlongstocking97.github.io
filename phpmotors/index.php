<?php
// This is the main controller

// Create or access a Session
session_start();

require_once 'initialize.php';

// Get the array of classifications from DB using model
$classifications = getClassifications();
// Build a navigation bar using the $classifications array
$navList = buildNavigation($classifications);

$action = filter_input(INPUT_POST, 'action');
if ($action == NULL) {
    $action = filter_input(INPUT_GET, 'action');
}

switch ($action) {
    case 'template':
        include './view/template.php';
        break;
    default:
        include './view/home.php';
}
