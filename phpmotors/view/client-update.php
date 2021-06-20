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
    <title id="page-title">Client Update Page | PHP Motors</title>
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="PHP Motors client update page">
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
            <h1>Manage Account</h1>
            <h2>Update Account</h2>
            <form action="/phpmotors/accounts/index.php" method="post">
                <fieldset id="align">
                    <label for="clientFirstname">First Name</label>
                    <label>&nbsp;</label>
                    <input type="text" id="clientFirstname" name="clientFirstname" required <?php if (isset($clientFirstname)) {
                                                                                                echo "value='$clientFirstname'";
                                                                                            } elseif (isset($clientInfo['clientFirstname'])) {
                                                                                                echo "value='$clientInfo[clientFirstname]'";
                                                                                            } ?>>
                    <label for="clientLastname">Last Name</label>
                    <label>&nbsp;</label>
                    <input type="text" id="clientLastname" name="clientLastname" required <?php if (isset($clientLastname)) {
                                                                                                echo "value='$clientLastname'";
                                                                                            } elseif (isset($clientInfo['clientLastname'])) {
                                                                                                echo "value='$clientInfo[clientLastname]'";
                                                                                            } ?>>
                    <label for="clientEmail">Email</label>
                    <label>&nbsp;</label>
                    <input type="email" id="clientEmail" name="clientEmail" required <?php if (isset($clientEmail)) {
                                                                                            echo "value='$clientEmail'";
                                                                                        } elseif (isset($clientInfo['clientEmail'])) {
                                                                                            echo "value='$clientInfo[clientEmail]'";
                                                                                        } ?>>

                    <label>&nbsp;</label>
                    <input type="submit" name="submit" id="regbtn" value="Update Info">
                    <input type="hidden" name="action" value="">
                    <input type="hidden" name="clientId" value="<?php if (isset($clientInfo['clientId'])) {
                                                                    echo $clientInfo['clientId'];
                                                                } elseif (isset($clientId)) {
                                                                    echo $clientId;
                                                                } ?>">
                </fieldset>
            </form>
            <h2>Update Password</h2>
            <form action="/phpmotors/accounts/index.php" method="post">
                <fieldset id="align">
                    <span>Passwords must be at least 8 characters and contain at least 1
                        number, 1 capital letter and 1 special character</span>
                    <label>&nbsp;</label>
                    <span>*note your original password will be changed.</span>
                    <label>&nbsp;</label>
                    <label for="clientPassword">Password</label>
                    <label>&nbsp;</label>
                    <input type="password" id="clientPassword" name="clientPassword" required pattern="(?=^.{8,}$)(?=.*\d)(?=.*\W+)(?![.\n]?=.*[A-Z])(?=.*[a-z]).*$">
                    )(
                </fieldset>
            </form>
            <hr id="line-break">
        </main>
        <footer>
            <?php include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/footer.php'; ?>
        </footer>
    </div>
</body>

</html>
<?php
unset($_SESSION['message']);
?>