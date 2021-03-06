<!DOCTYPE html>
<html lang="en-us">

<head>
    <meta charset="UTF-8">
    <title> <?php echo $vehiclesDetail['invMake'] . " " .  $vehiclesDetail['invModel'] ?> Details | PHP Motors, Inc.</title>
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="PHP Motors vehicle details page">
    <meta name="author" content="Aaron Jones">
    <link rel="stylesheet" type="text/css" href="/phpmotors/css/vehicle-detail.css" media="screen">
</head>

<body>
    <div id="wrapper">
        <header>
            <?php include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/header.php'; ?>
        </header>
        <nav id="page_nav">
            <?php echo $navList; ?>
        </nav>
        <main>
            <h1 id="content"><?php echo $vehiclesDetail['invMake'] . " " .  $vehiclesDetail['invModel'] ?></h1>
            <?php
            if (isset($message)) {
                echo $message;
            }
            ?>
            <?php
            if (isset($details)) {
                echo $details;
            }
            ?>
        </main>
        <hr id="line-break">
        <footer>
            <?php include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/footer.php'; ?>
        </footer>
    </div>
</body>

</html>