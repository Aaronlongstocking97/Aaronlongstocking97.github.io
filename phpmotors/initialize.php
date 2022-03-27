<?php
// Initialize file for phpmotors

//Site Constant
define('ROOT', $_SERVER['DOCUMENT_ROOT'] . '/phpmotors');
define('VIEWROOT', $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/view/');

// Require models
// Get the database connection file
require_once ROOT . '/library/connections.php';
require_once ROOT . '/model/main-model.php';
require_once ROOT . '/model/accounts-model.php';
require_once ROOT . '/model/vehicles-model.php';
require_once ROOT . '/model/uploads-model.php';
require_once ROOT . '/library/functions.php';
