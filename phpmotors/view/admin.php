<?php
// This is a redirect statment
if (!isset($_SESSION['loggedin'])) {
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
            $level = $_SESSION['clientData']['clientLevel'];
            if ($level == 1) {
                echo "<h1 id='displayName'>" . $_SESSION['clientData']['clientFirstname'] . "    " . $_SESSION['clientData']['clientLastname'] . "</h1>"
                    . "<section>"
                    . "<span>You are logged in.</span>"
                    . "<ul>"
                    . "<li>First name:  " . $_SESSION['clientData']['clientFirstname'] . "</li>"
                    . "<li>Last name:   " . $_SESSION['clientData']['clientLastname'] . "</li>"
                    . "<li>Email:   " . $_SESSION['clientData']['clientEmail'] . "</li>"
                    . "</ul>"
                    . "</section>";
                if ('<a href="/phpmotors/vehicles/></a>' == TRUE) {
                    header("location: /phpmotors/accounts/");
                }
            } elseif ($level > 1) {
                echo "<h2 id='adminInvManage'>Inventory Management</h2>"
                    . "<span>Use this link to manage the inventory.</span>"
                    . "<br>"
                    . "<div>&nbsp;</div>"
                    . '<a href="/phpmotors/vehicles/" id="adminVehicleManage">Vehicle Management</a>'
                    . "<div>&nbsp;</div>";
            } else {
                header("location: /phpmotors/");
            }
            ?>
            <hr id="line-break">
        </main>
        <footer>
            <?php include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/footer.php'; ?>
        </footer>
    </div>
</body>

</html>