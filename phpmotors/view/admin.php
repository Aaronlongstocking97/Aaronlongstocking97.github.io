<?php
// This is a redirect statment
if (!$_SESSION['loggedin'] === 1) {
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
            echo "<h1>" . $_SESSION['clientData']['clientFirstname'] . $_SESSION['clientData']['clientLastname'] . "</h1>";
            echo "<section>";
            echo "<ul>";
            echo "<h2>You are logged in</h2>";
            echo "<li>First name:" . $_SESSION['clientData']['clientFirstname'] . "</li>";
            echo "<li>Last name:" . $_SESSION['clientData']['clientLastname'] . "</li>";
            echo "<li>Email:" . $_SESSION['clientData']['clientEmail'] . "</li>";
            echo "</ul>";
            echo "</section>";
            ?>
            <hr id="line-break">
        </main>
        <footer>
            <?php include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/footer.php'; ?>
        </footer>
    </div>
</body>

</html>