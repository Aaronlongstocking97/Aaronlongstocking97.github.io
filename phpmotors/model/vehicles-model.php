<?php

/*
*   Vehicle Model
*/

// Register a new car classification
function addClassification($classificationName)
{
    // Create a connection object using the phpmotors connection function
    $db = phpmotorsConnect();

    // The SQL statement
    $sql = 'INSERT INTO carclassification (classificationName)
    VALUES (:classificationName)';

    // Create the prepared statement using the phpmotors connection
    $stmt = $db->prepare($sql);

    // The next four lines replace the placeholders in the SQL
    // statement with the actual values in the variables
    // and tells the database the type of data it is
    $stmt->bindValue(
        ':classificationName',
        $classificationName,
        PDO::PARAM_STR
    );

    // Insert the data
    $stmt->execute();

    // Ask how many rows changed as a result of our insert
    $rowsChanged = $stmt->rowCount();

    // Close the database interaction
    $stmt->closeCursor();

    // Return the indication of success (rows changed)
    return $rowsChanged;
}

// Register a new vehicle
function addVehicle(
    $invMake,
    $invModel,
    $invDescription,
    $invImage,
    $invThumbnail,
    $invPrice,
    $invStock,
    $invColor,
    $classificationId
) {
    // Create a connection object using the phpmotors connection function
    $db = phpmotorsConnect();

    // The SQL statement
    $sql = 'INSERT INTO inventory (invMake, invModel, 
    invDescription, invImage, invThumbnail, invPrice, 
    invStock, invColor, classificationId)
    VALUES (:invMake, :invModel, :invDescription, :invImage, 
    :invThumbnail, :invPrice, :invStock, :invColor, :classificationId)';

    // Create the prepared statement using the phpmotors connection
    $stmt = $db->prepare($sql);

    // The next four lines replace the placeholders in the SQL
    // statement with the actual values in the variables
    // and tells the database the type of data it is
    $stmt->bindValue(':invMake', $invMake, PDO::PARAM_STR);
    $stmt->bindValue(':invModel', $invModel, PDO::PARAM_STR);
    $stmt->bindValue(':invDescription', $invDescription, PDO::PARAM_STR);
    $stmt->bindValue(':invImage', $invImage, PDO::PARAM_STR);
    $stmt->bindValue(':invThumbnail', $invThumbnail, PDO::PARAM_STR);
    $stmt->bindValue(':invPrice', $invPrice, PDO::PARAM_INT);
    $stmt->bindValue(':invStock', $invStock, PDO::PARAM_INT);
    $stmt->bindValue(':invColor', $invColor, PDO::PARAM_STR);
    $stmt->bindValue(':classificationId', $classificationId, PDO::PARAM_INT);

    // Insert the data
    $stmt->execute();

    // Ask how many rows changed as a result of our insert
    $rowsChanged = $stmt->rowCount();

    // Close the database interaction
    $stmt->closeCursor();

    // Return the indication of success (rows changed)
    return $rowsChanged;
}

// Get vehicles by classificationId 
function getInventoryByClassification($classificationId)
{
    $db = phpmotorsConnect();
    $sql = ' SELECT * FROM inventory WHERE invMake = :classificationId';
    $stmt = $db->prepare($sql);
    $stmt->bindValue(':classificationId', $classificationId, PDO::PARAM_INT);
    $stmt->execute();
    $inventory = $stmt->fetchAll(PDO::FETCH_ASSOC);
    $stmt->closeCursor();
    return $inventory;
}

// Get vehicle information by invId
function getInvItemInfo($invId)
{
    $db = phpmotorsConnect();
    $sql = 'SELECT * FROM inventory WHERE invId = :invId';
    $stmt = $db->prepare($sql);
    $stmt->bindValue(':invId', $invId, PDO::PARAM_INT);
    $stmt->execute();
    $invInfo = $stmt->fetch(PDO::FETCH_ASSOC);
    $stmt->closeCursor();
    return $invInfo;
}

// Update a vehicle
function updateVehicle(
    $invMake,
    $invModel,
    $invDescription,
    $invImage,
    $invThumbnail,
    $invPrice,
    $invStock,
    $invColor,
    $classificationId,
    $invId
) {
    $db = phpmotorsConnect();
    $sql = 'UPDATE inventory SET invMake = :invMake, invModel = :invModel, invDescription = :invDescription, invImage = :invImage, invThumbnail = :invThumbnail, invPrice = :invPrice, invStock = :invStock, invColor = :invColor, classificationId = :classificationId WHERE invId = :invId';
    $stmt = $db->prepare($sql);
    $stmt->bindValue(':classificationId', $classificationId, PDO::PARAM_INT);
    $stmt->bindValue(':invMake', $invMake, PDO::PARAM_STR);
    $stmt->bindValue(':invModel', $invModel, PDO::PARAM_STR);
    $stmt->bindValue(':invDescription', $invDescription, PDO::PARAM_STR);
    $stmt->bindValue(':invImage', $invImage, PDO::PARAM_STR);
    $stmt->bindValue(':invThumbnail', $invThumbnail, PDO::PARAM_STR);
    $stmt->bindValue(':invPrice', $invPrice, PDO::PARAM_STR);
    $stmt->bindValue(':invStock', $invStock, PDO::PARAM_INT);
    $stmt->bindValue(':invColor', $invColor, PDO::PARAM_STR);
    $stmt->bindValue(':invId', $invId, PDO::PARAM_INT);
    $stmt->execute();
    $rowsChanged = $stmt->rowCount();
    $stmt->closeCursor();
    return $rowsChanged;
}

// Delete a vehicle form inventory
function deleteVehicle($invId)
{
    $db = phpmotorsConnect();
    $sql = 'DELETE FROM inventory WHERE invId = :invId';
    $stmt = $db->prepare($sql);
    $stmt->bindValue(':invId', $invId, PDO::PARAM_INT);
    $stmt->execute();
    $rowsChanged = $stmt->rowCount();
    $stmt->closeCursor();
    return $rowsChanged;
}

// Get the list of vehicles by classification name
// Pulling the primary thumbnail image from the images table
// This pull of information will display through the classification view
// REQUIRED - imgPrimary and thumbnails('TN') and NAVIGATION NAME
// CONNECTING - inventory AND images THROUGH invId
//// CONNECTING - inventory AND carclassification THROUGH classificationId
// invId will be an ARRAY['information from both tables']
// Taking a number through and using it as an array (ex:vehicle-detail.php)
// Taking the NAVIGATION NAME through the getClassifications()
// function getVehiclesByClassification($imgPrimary, $imgPath)
// {
//     $db = phpmotorsConnect();
//     $sql = 'SELECT imgPath, inventory.invId, invMake, invModel, invPrice
//     FROM images JOIN inventory ON images.invId = inventory.invId';
//     $stmt = $db->prepare($sql);
//     $stmt->bindValue(':imgPrimary', $imgPrimary, PDO::PARAM_INT);
//     $stmt->bindValue(':imgPath', $imgPath, PDO::PARAM_STR);
//     $stmt->execute();
//     $primaryVehicles = $stmt->fetchAll(PDO::FETCH_ASSOC);
//     $stmt->closeCursor();
//     return $primaryVehicles;
// }

function getVehiclesByClassification($classificationName)
{
    $db = phpmotorsConnect();
    $sql = 'SELECT i.invId, invMake, invModel, img.imgPath as invThumbnail, invPrice, invStock, invColor, classificationId 
        FROM inventory i
                JOIN images img
	                ON i.invId = img.invId
        WHERE classificationId IN (SELECT classificationId FROM carclassification WHERE classificationName = :classificationName)
                AND img.imgPath LIKE "%-tn%"
                AND img.imgPrimary = 1';
    $stmt = $db->prepare($sql);
    $stmt->bindValue(':classificationName', $classificationName, PDO::PARAM_STR);
    $stmt->execute();
    $vehicles = $stmt->fetchAll(PDO::FETCH_ASSOC);
    $stmt->closeCursor();
    return $vehicles;
}

// Get the list of vehicles by classification name
// - The AS command is used to rename a column or table with an alias.
//      - An alias only exists for the duration of the query.
// - The IN operator allows you to specify multiple values in a WHERE clause.
//      - The IN operator is a shorthand for multiple OR conditions.
// - The WHERE clause can be combined with AND, OR, and NOT operators.
// - The AND and OR operators are used to filter records based on 
//   more than one condition:
//      - The AND operator displays a record if all the conditions 
//        separated by AND are TRUE.
//      - The OR operator displays a record if any of the conditions 
//        separated by OR is TRUE.
// - The NOT operator displays a record if the condition(s) is NOT TRUE.
// - The LIKE operator is used in a WHERE clause to search for a 
//   specified pattern in a column.
// - There are two wildcards often used in conjunction with the LIKE operator:
//      - The percent sign (%) represents zero, one, or multiple characters
//      - The underscore sign (_) represents one, single character
function getVehiclesById($invId)
{
    $db = phpmotorsConnect();
    $sql = 'SELECT i.invId, invMake, invModel, img.imgPath as invImage, invThumbnail, invPrice, invStock, invColor, invDescription
        FROM inventory i
                JOIN images img
	                ON i.invId = img.invId
        WHERE NOT img.imgPath = "%-tn%"';
    // $sql = 'SELECT * FROM inventory WHERE invId = :invId';
    $stmt = $db->prepare($sql);
    $stmt->bindValue(':invId', $invId, PDO::PARAM_INT);
    $stmt->execute();
    $vehiclesDetail = $stmt->fetch(PDO::FETCH_ASSOC);
    $stmt->closeCursor();
    return $vehiclesDetail;
}

// invId
// invMake
// invModel
// invPrice
// - imgPath
//      - invThumbnail, invImage
// invDescription
// invColor
// invStock

// Get information for all vehicles
function getVehicles()
{
    $db = phpmotorsConnect();
    $sql = 'SELECT invId, invMake, invModel FROM inventory';
    $stmt = $db->prepare($sql);
    $stmt->execute();
    $invInfo = $stmt->fetchAll(PDO::FETCH_ASSOC);
    $stmt->closeCursor();
    return $invInfo;
}
