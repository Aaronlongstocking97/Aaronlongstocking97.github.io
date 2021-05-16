<!DOCTYPE html>
<html lang="en-us">

<head>
    <meta charset="UTF-8">
    <title id="page-title">Content Title | PHP Motors</title>
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="PHP Motors error page">
    <meta name="author" content="Aaron Jones">
    <link rel="stylesheet" type="text/css" href="../css/screen.css" media="screen">
</head>

<body>
    <div id="wrapper">
        <header>
            <?php require_once $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/snippets/header.php'; ?>
        </header>
        <nav id="page_nav">
            <?php require_once $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/snippets/navigation.php'; ?>
        </nav>
        <main id="main-content">
            <h1 id="content">Server Error</h1>
            <p>Sorry our server seems to be experiencing some technical difficulties</p>
            <hr id="line-break">
        </main>
        <footer>
            <?php require_once $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/snippets/footer.php'; ?>
        </footer>
    </div>
</body>

</html>