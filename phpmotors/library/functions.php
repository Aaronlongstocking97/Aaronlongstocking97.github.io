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
    $navList .= "<li><a href='/phpmotors/' title='View 
                the PHP Motors home page'>Home</a></li>";
    foreach ($classifications as $classification) {
        $navList .= "<li><a href='/phpmotors/vehicles?
        action=classification&classificationName="
            . urlencode($classification['classificationName'])
            . "' title='View our $classification[classificationName] lineup
            of vehicles'>$classification[classificationName]</a></li>";
    }
    $navList .= '</ul>';
    // Returns a string variable holding 
    // the HTML navigation list
    return $navList;
}

function buildVehiclesDisplay($vehicles)
{
    $dv = '<ul id="inv-display">';
    foreach ($vehicles as $vehicle) {
        $dv .= '<li>';
        $dv .= "<img src='$vehicle[invThumbnail]' alt='Image of $vehicle[invMake] $vehicle[invModel] on phpmotors.com'>";
        $dv .= '<div class="namePrice">';
        $dv .= '<hr>';
        $dv .= "<a href='/phpmotors/vehicles/index.php?action=detailVehicle&invMake=" . $_SESSION['vehicles'] . "'>";
        $dv . "'$vehicle[invMake] $vehicle[invModel]'</a>";
        $dv .= "<span>$vehicle[invPrice]</span>";
        $dv .= '</div>';
        $dv .= '</li>';
    }
    $dv .= '</ul>';
    return $dv;
}
// <a href="/phpmotors/accounts/?action=client-update&clientId= 
// <a href="/phpmotors/accounts/?action=client-update&clientId=  <?php echo $_SESSION['clientData']['clientId']
//>">Update Account Information</a>
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

// Build the classifications select list 
function buildClassificationList($classifications)
{
    $classificationList = '<select name="classificationId" id="classificationList">';
    $classificationList .= "<option>Choose a Classification</option>";
    foreach ($classifications as $classification) {
        $classificationList .= "<option value='$classification[classificationId]'>$classification[classificationName]</option>";
    }
    $classificationList .= '</select>';
    return $classificationList;
}

function buildVehiclesDetailPage($vehiclesDetail)
{
    $dv = '<ul id="inv-display">';
    foreach ($vehiclesDetail as $vehiclesDetails) {
        $dv .= '<li>';
        $dv .= "<img src='$vehiclesDetails[invThumbnail]' alt='Image of $vehiclesDetails[invMake] $vehiclesDetails[invModel] on phpmotors.com'>";
        $dv .= '<div class="namePrice">';
        $dv .= '<hr>';
        $dv .= "<h2>$vehiclesDetails[invMake] $vehiclesDetails[invModel]</h2>";
        $dv .= "<span>$vehiclesDetails[invPrice]</span>";
        $dv .= '</div>';
        $dv .= '</li>';
    }
    $dv .= '</ul>';
    return $dv;
}

// General Message function
function message($msg = '')
{
    if (!empty($msg)) {
        // set message to session
        $_SESSION['message'] = $msg;
    } else {
        // get the message
        return $_SESSION['message'];
    }
}

// clear a session message
function clearMessage()
{
    unset($_SESSION['message']);
}
