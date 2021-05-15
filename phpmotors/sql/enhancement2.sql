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
UPDATE clients
SET clientLevel = '3'
WHERE clientFirstname = 'Tony';
UPDATE inventory
SET invDescription = REPLACE(invDescription, 'small', 'spacious')
WHERE invId = 12;