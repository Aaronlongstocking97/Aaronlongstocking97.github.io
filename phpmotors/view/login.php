<!DOCTYPE html>
<html lang="en-us">

<head>
    <meta charset="UTF-8">
    <title id="page-title">Account Login | PHP Motors</title>
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="PHP Motors template page">
    <meta name="author" content="Aaron Jones">
    <link rel="stylesheet" type="text/css" href="/phpmotors/css/screen.css" media="screen">
</head>

<body>
    <div id="wrapper">
        <header>
            <?php include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/header.php'; ?>
        </header>
        <nav id="page_nav">
            <?php //include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/navigation.php'; 
            echo $navList; ?>
        </nav>
        <main id="main-content">
            <h1 id="content">Sign in</h1>
            <form action="../accounts/index.php" method="post">
                <label for="email">Email</label>
                <input name="email" id="email" type="email">
                <label for="password">Password</label>
                <input name="password" id="password" type="password">
                <input type="submit" value="Sign-in">
            </form>
            <div>
                <a href="/phpmotors/view/registration.php" id="rgstr">Not a member yet?</a>
            </div>
            <hr id="line-break">
        </main>
        <footer>
            <?php include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/footer.php'; ?>
        </footer>
    </div>
</body>

</html>