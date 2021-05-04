<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <meta name="description" content="PHP Motors home page">
    <meta name="author" content="Aaron Jones">
    <title>Home | PHP Motors</title>
    <link href="../css/home.css" rel="stylesheet">
    <!--<link href="https://fonts.googleapis.com/css2?family=Quantico&display=swap" rel="stylesheet">-->
</head>
<body>
<header>
    <img src="../images/site/logo.png" alt="PHP Motors Logo">
    <p><a href="#" title="Link to your account with PHP Motors">My Account</a></p>
    <nav>
    <ul>
        <li><a href="#" title="Link to the PHP Motors Home Page">Home</a></li>
        <li><a href="#" title="Link to the PHP Motors Classic Cars">Classic</a></li>
        <li><a href="#" title="Link to the PHP Motors Sports Cars">Sports</a></li>
        <li><a href="#" title="Link to the PHP Motors SUVs">SUV</a></li>
        <li><a href="#" title="Link to the PHP Motors Trucks">Trucks</a></li>
        <li><a href="#" title="Link to the PHP Motors Used Cars">Used</a></li>
    </ul>    
    </nav>
</header>
<main>
    <h1>Welcome to PHP Motors!</h1>
    <div class="topdiv">
        <h2>DMC Delorean</h2>
        <p>3 Cup holders</p>
        <p>Superman doors</p>
        <p>Fuzzy dice!</p>
        <button class="button1">Own Today</button>
    </div>
    <img class="delorean" src="../images/delorean.jpg" alt="image of a delorean car">
    <button class="button2">Own Today</button>
    <div class="reviews">
    <h2>DMC Delorean Reviews</h2>
    <ul>
        <li>"So fast its almost like traveling in time." (4/5)</li>
        <li>"Coolest ride on the road." (4/5)</li>
        <li>"I'm feeling like Marty McFly!" (5/5)</li>
        <li>"The most futuristic ride of our day." (4.5/5)</li>
        <li>"80's livin and I love it!" (5/5)</li>
    </ul>
    </div>
    <h2>Delorean Upgrades</h2>
    <div id="upgrades">

        <div class="col">
            <img src="../images/upgrades/flux-cap.png" alt=" Image of Flux Capacitor">
            <p><a href="#" title="Link to Flux Capacitor Page">Flux Capacitor</a></p>
        </div>
        <div class="col">
            <img src="../images/upgrades/flame.jpg" alt=" Image of Flames">
            <p><a href="#" title="Link to Flame Decals Page">Flame Decals</a></p>
        </div>
        <div class="col">
            <img src="../images/upgrades/bumper_sticker.jpg" alt=" Image of Bumper Sticker">
            <p><a href="#" title="Link to Bumper Stickers Page">Bumper Stickers</a></p>
        </div>
        <div class="col">
            <img src="../images/upgrades/hub-cap.jpg" alt=" Image of Hub Cap">
            <p><a href="#" title="Link to Hub Caps Page">Hub Caps</a></p>
        </div>
    </div>
</main>
<footer>  
<?php require $_SERVER['DOCUMENT_ROOT'].'/phpmotors/snippets/footer.php'; ?>  
</footer>
</body>

</html>