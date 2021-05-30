<!DOCTYPE html>
<html lang="en-us">

<head>
    <meta charset="UTF-8">
    <title id="page-title">Account Registration | PHP Motors</title>
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="PHP Motors template page">
    <meta name="author" content="Aaron Jones">
    <link rel="stylesheet" type="text/css" href="/phpmotors/css/registration.css" media="screen">
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
            <h1 id="content">Register</h1>
            <form action="/phpmotors/accounts/index.php" id="align" method="post">
                <label for="fName">First Name</label>
                <input type="text" id="fName" name="clientFirstname">
                <label for="lName">Last Name</label>
                <input type="text" id="lName" name="clientLastname">
                <label for="email">Email</label>
                <input type="email" id="email" name="clientEmail">
                <div id="passLimits">Passwords must be at least 8 characters and
                    contain at least 1 number, 1 capital letter and 1 special character</div>
                <label for="password">Password</label>
                <input type="password" id="password" name="clientPassword">
                <input type="button" name="showPass" id="showPass" value="Show Password">
                <input type="submit" name="submit" id="regbtn" value="Register">
            </form>
            <hr id="line-break">
        </main>
        <footer>
            <?php include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/footer.php'; ?>
        </footer>
    </div>
</body>

</html>