/*
 Insert a client into the clients table
 */
INSERT INTO clients (
        clientFirstname,
        clientLastname,
        clientEmail,
        clientPassword,
        clientLevel,
        comment
    )
Values (
        'Tony',
        'Stark',
        'tony@starkent.com',
        'Iam1ronm@n',
        1,
        'I am the real Ironman'
    );
/*
 Modify the Tony Stark record to change the clientLevel to 3
 */
UPDATE clients
SET clientLevel = '3'
WHERE clientFirstname = 'Tony';
/*
 Modify the "GM Hummer" record to read "spacious interior" 
 rather than "small interior"
 */
UPDATE inventory
SET invDescription = REPLACE(invDescription, 'small', 'spacious')
WHERE invId = 12;
/*
 inner join the invModel column from the inventory table 
 and the classificationName column from the carclassification 
 table for inventory items that belong to the "SUV" category. 
 The result will display four records as a result of the query.
 */
SELECT inventory.invModel,
    carclassification.classificationName
FROM inventory
    INNER JOIN carclassification ON inventory.classificationId = carclassification.classificationId
WHERE classificationName = 'SUV';
/*
 Deleting the Jeep Wrangler from the database.
 */
DELETE FROM inventory
WHERE invMake = 'Jeep';
/*
 Updating all records in the Inventory table to add "/phpmotors" 
 to the beginning of the file path in the invImage and invThumbnail 
 columns using a single query
 */
UPDATE inventory
SET invImage = CONCAT('/phpmotors', invImage),
    invThumbnail = CONCAT('/phpmotors', invThumbnail);