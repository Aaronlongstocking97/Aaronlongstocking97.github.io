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
        'IamIronm@n',
        1,
        'I am the real Ironman'
    );