<!DOCTYPE html>
<html lang="en-us">

<head>
    <meta charset="UTF-8">
    <title id="page-title">Server Error | PHP Motors</title>
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="PHP Motors error page">
    <meta name="author" content="Aaron Jones">
    <link rel="stylesheet" type="text/css" href="/phpmotors/css/error_screen.css" media="screen">
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
            <h1 id="content">Server Error</h1>
            <div id="errorM">Sorry our server seems to be experiencing some technical difficulties</div>
            <hr id="line-break">
        </main>
        <footer>
            <?php include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/footer.php'; ?>
        </footer>
    </div>
</body>

</html>