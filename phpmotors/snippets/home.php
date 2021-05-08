<!DOCTYPE html>
<html lang="en-us">

<head>
    <meta charset="UTF-8">
    <title>Home | PHP Motors</title>
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="PHP Motors home page">
    <meta name="author" content="Aaron Jones">
    <link rel="stylesheet" type="text/css" href="../css/home.css" media="screen">
</head>

<body>
    <div id="wrapper">
        <header>
            <?php require_once $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/snippets/header.php'; ?>
        </header>
        <nav id="page_nav">
            <?php require_once $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/snippets/navigation.php'; ?>
        </nav>
        <main>
            <h1 class="title">Welcome to PHP Motors!</h1>
            <div class="topdiv">
                <h2>DMC Delorean</h2>
                <p>3 Cup holders</p>
                <p>Superman doors</p>
                <p>Fuzzy dice!</p>
                <button class="button1">Own Today</button>
            </div>
            <img class="delorean" src="../images/delorean.jpg" alt="image of a delorean car">
            <button class="button2">Own Today</button>
            <div id="split">
                <section id="reviews">
                    <h2>DMC Delorean Reviews</h2>
                    <ul>
                        <li>"So fast its almost like traveling in time." (4/5)</li>
                        <li>"Coolest ride on the road." (4/5)</li>
                        <li>"I'm feeling like Marty McFly!" (5/5)</li>
                        <li>"The most futuristic ride of our day." (4.5/5)</li>
                        <li>"80's livin and I love it!" (5/5)</li>
                    </ul>
                </section>

                <section id="upgrades">
                    <h2>Delorean Upgrades</h2>
                    <ul>
                        <li><a href="#" title="Link to Flux Capacitor Page"><img id="fluxCap" alt=" Image of Flux Capacitor" src="../images/upgrades/flux-cap.png"></a>
                        </li>
                        <li><a href="#" title="Link to Flame Decals Page"><img id="flames" alt=" Image of Flames" src="../images/upgrades/flame.jpg"></a>
                        </li>
                        <li>
                            <div id="flux">Flux Capacitor</div>
                        </li>
                        <li>
                            <div id="fire">Flame Decals</div>
                        </li>
                        <li><a href="#" title="Link to Bumper Stickers Page"><img id="sticker" alt=" Image of Bumper Sticker" src="../images/upgrades/bumper_sticker.jpg"></a>
                        </li>
                        <li><a href="#" title="Link to Hub Caps Page"><img id="hubCap" alt=" Image of Hub Cap" src="../images/upgrades/hub-cap.jpg"></a>
                        </li>
                        <li>
                            <div>Bumper Stickers</div>
                        </li>
                        <li>
                            <div id="hub">Hub Caps</div>
                        </li>
                    </ul>
                </section>
            </div>
        </main>
        <hr id="line-break">
        <footer>
            <?php require_once $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/snippets/footer.php'; ?>
        </footer>
    </div>
</body>

</html>