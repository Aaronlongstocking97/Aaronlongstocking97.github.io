<!DOCTYPE html>
<html lang="en-us">

<head>
    <meta charset="UTF-8">
    <title id="page-title">Add Classsification | PHP Motors</title>
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="PHP Motors add car classsification page">
    <meta name="author" content="Aaron Jones">
    <link rel="stylesheet" type="text/css" href="/phpmotors/css/add-classification.css" media="screen">
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
            <h1 id="content">Add Car Classsification</h1>
            <?php
            if (isset($message)) {
                echo $message;
            }
            ?>
            <form action="/phpmotors/vehicles/index.php" id="align" method="post">
                <label for="classificationName">Classification Name</label>
                <span>Classification Names are limited to 30 characters per entry.</span>
                <input type="text" id="classificationName" name="classificationName" size="13" <?php if (isset($classificationName)) {
                                                                                                    echo "value='$classificationName'";
                                                                                                }
                                                                                                ?> required>
                <input type="submit" name="submit" id="addClassBtn" value="Add Classification">
                <input type="hidden" name="action" value="addClass">
            </form>
            <hr id="line-break">
        </main>
        <footer>
            <?php include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/footer.php'; ?>
        </footer>
    </div>
</body>

</html>