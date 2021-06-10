<?php
/*
* Usable funtions for multiple files
*/

function checkEmail($clientEmail)
{
    $valEmail = filter_var($clientEmail, FILTER_VALIDATE_EMAIL);
    return $valEmail;
}
