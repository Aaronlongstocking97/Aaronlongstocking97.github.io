<!DOCTYPE html>
<html lang="en-us">

<head>
    <meta charset="UTF-8">
    <title id="page-title">Account Login | PHP Motors</title>
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="PHP Motors login page">
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
            <h1 id="content">Sign in</h1>
            <?php
            if (isset($message)) {
                echo $message;
            }
            ?>
            <form action="/phpmotors/accounts/index.php" method="get">
                <fieldset id="align">
                    <label for="clientEmail">Email</label>
                    <input type="email" id="clientEmail" name="clientEmail" required placeholder="Enter a valid email address" <?php if (isset($clientEmail)) {
                                                                                                                                    echo "value='$clientEmail'";
                                                                                                                                }
                                                                                                                                ?> required>
                    <label for="clientPassword">Password</label>
                    <span>Passwords must be at least 8 characters and contain at least 1
                        number, 1 capital letter and 1 special character</span>
                    <input type="password" id="clientPassword" name="clientPassword" required pattern="(?=^.{8,}$)(?=.*\d)(?=.*\W+)(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$">
                    <label>&nbsp;</label>
                    <input type="submit" name="submit" id="regbtn" value="Sign-in">
                </fieldset>
            </form>
            <div id="signUp">
                <a href="/phpmotors/accounts/index.php?action=registration" id="registration">Not a member yet?</a>
            </div>
            <hr id="line-break">
        </main>
        <footer>
            <?php include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/footer.php'; ?>
        </footer>
    </div>
</body>

</html>