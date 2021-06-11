<?php
// Build the select list
$classifList = '<select name="classificationId">';
foreach ($classifications as $classification) {
    $classifList .= "<option value='$classification[classificationId]'";
    if (isset($classificationId)) {
        if ($classification['classificationId'] === $classificationId) {
            $classifList .= ' selected ';
        }
    }
    $classifList .= ">$classification[classificationName]</option>";
}
$classifList .= '</select>';
?>
<!DOCTYPE html>
<html lang="en-us">

<head>
    <meta charset="UTF-8">
    <title id="page-title">Add Vehicle | PHP Motors</title>
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="PHP Motors add vehicle page">
    <meta name="author" content="Aaron Jones">
    <link rel="stylesheet" type="text/css" href="/phpmotors/css/add-vehicle.css" media="screen">
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
            <h1 id="content">Add Vehicle</h1>
            <?php
            if (isset($message)) {
                echo $message;
            }
            ?>
            <h2 id="warning">*Note all Fields are Required</h2>
            <form action="/phpmotors/vehicles/index.php" method="post">
                <fieldset id="align">
                    <?php echo $classifList; ?>
                    <label for="invMake">Make</label>
                    <input type="text" id="invMake" name="invMake">
                    <label for="invModel">Model</label>
                    <input type="text" id="invModel" name="invModel">
                    <label for="invDescription">Description</label>
                    <textarea name="invDescription" id="invDescription" cols="20" rows="2"></textarea>
                    <label for="invImage">Image Path</label>
                    <input type="text" id="invImage" name="invImage" value="/phpmotors/images/no-image.png">
                    <label for="invThumbnail">Thumbnail Path</label>
                    <input type="text" id="invThumbnail" name="invThumbnail" value="/phpmotors/images/no-image.png">
                    <label for="invPrice">Price</label>
                    <input type="number" step="any" id="invPrice" name="invPrice">
                    <label for="invStock"># In Stock</label>
                    <input type="number" id="invStock" name="invStock">
                    <label for="invColor">Color</label>
                    <input type="text" id="invColor" name="invColor">
                    <input type="submit" name="submit" id="addVehicleBtn" value="Add Vehicle">
                    <input type="hidden" name="action" value="addVehicle">
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