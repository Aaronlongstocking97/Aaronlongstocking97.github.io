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
            <form action="/phpmotors/vehicles/index.php" id="align" method="post">
                <label for="chooseCClass"></label>
                <!-- <select name="carClassifications" id="chooseCClass">
                    <option value="Choose Car Classification"></option>
                </select> -->
                <?php if (isset($carClassifications)) {
                    echo $carClassifications;
                }
                ?>
                <label for="make">Make</label>
                <input type="text" id="make" name="invMake" size="5">
                <label for="model">Model</label>
                <input type="text" id="model" name="invModel" size="5">
                <label for="specify">Description</label>
                <textarea name="invDescription" id="specify" cols="20" rows="2"></textarea>
                <label for="imgPath">Image Path</label>
                <input type="text" id="imgPath" name="invImage" size="5">
                <label for="thumbPath">Thumbnail Path</label>
                <input type="text" id="thumbPath" name="invThumbnail" size="5">
                <label for="price">Price</label>
                <input type="number" step="any" id="price" name="invPrice" size="5">
                <label for="quantity"># In Stock</label>
                <input type="number" id="quantity" name="invStock" size="5">
                <label for="color">Color</label>
                <input type="text" id="color" name="invColor" size="5">
                <input type="submit" name="submit" id="addVehicleBtn" value="Add Vehicle">
                <input type="hidden" name="action" value="addVehicle">
            </form>


            <hr id="line-break">
        </main>
        <footer>
            <?php include $_SERVER['DOCUMENT_ROOT'] . '/phpmotors/common/footer.php'; ?>
        </footer>
    </div>
</body>

</html>