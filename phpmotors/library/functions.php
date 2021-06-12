<?php
/*
* Usable funtions for multiple files
*/

// Receives the $carclassifications array as a parameter 
// and builds the navigation list HTML around the values 
// found in the $carclassifications array.
function buildNavigation($classifications)
{
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
    // Returns a string variable holding 
    // the HTML navigation list
    return $navList;
}

// Check the value of the $clientEmail variable, after having been
// sanitized, to see if it "looks" like a valid email address.
function checkEmail($clientEmail)
{
    $valEmail = filter_var($clientEmail, FILTER_VALIDATE_EMAIL);
    return $valEmail;
}

// Check the password for a minimum of 8 characters,
// at least one 1 capital letter, at least 1 number and
// at least 1 special character
function checkPassword($clientPassword)
{
    $pattern = '/^(?=.*[[:digit:]])(?=.*[[:punct:]\s])(?=.*[A-Z])(?=.*[a-z])(?:.{8,})$/';
    return preg_match($pattern, $clientPassword);
}

// Limits the users input to no more than 30 characters
// and returns a string within that limitation.
function checkClassificationName($classificationName)
{
    if (strlen($classificationName) > 30)
        $classificationName = substr($classificationName, 0, 30);
    return $classificationName;
}
