<?php
if (!$_SESSION['loggedin']) {
    header("location: /phpmotors/");
    exit;
}
?>
<!DOCTYPE html>
<html lang="en-us">

<head>
    <meta charset="UTF-8">
    <title id="page-title">Admin Page | PHP Motors</title>
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="PHP Motors admin page">
    <meta name="author" content="Aaron Jones">
    <link rel="stylesheet" type="text/css" href="/phpmotors/css/login.css" media="screen">
</head>

<body>
    <div id="wrapper">
        <header>
            <?php include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/header.php'; ?>
        </header>
        <nav id="page_nav">
            <?php echo $navList; ?>
        </nav>
        <main id="main-content">
            <?php
            echo $clientFirstname;


            ?>

            <hr id="line-break">
        </main>
        <footer>
            <?php include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/footer.php'; ?>
        </footer>
    </div>
</body>

</html>