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
    <title id="page-title"><?php if (isset($invInfo['invMake']) && isset($invInfo['invModel'])) {
                                echo "Modify $invInfo[invMake] $invInfo[invModel]";
                            } elseif (isset($invMake) && isset($invModel)) {
                                echo "Modify $invMake $invModel";
                            } ?> | PHP Motors</title>
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="PHP Motors Update vehicle page">
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
            <h1 id="content"><?php if (isset($invInfo['invMake']) && isset($invInfo['invModel'])) {
                                    echo "Modify $invInfo[invMake] $invInfo[invModel]";
                                } elseif (isset($invMake) && isset($invModel)) {
                                    echo "Modify$invMake $invModel";
                                } ?></h1>
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
                    <input type="text" name="invMake" id="invMake" required <?php if (isset($invMake)) {
                                                                                echo "value='$invMake'";
                                                                            } elseif (isset($invInfo['invMake'])) {
                                                                                echo "value='$invInfo[invMake]'";
                                                                            } ?>>
                    <label for="invModel">Model</label>
                    <input type="text" name="invModel" id="invModel" required <?php if (isset($invModel)) {
                                                                                    echo "value='$invModel'";
                                                                                } elseif (isset($invInfo['invModel'])) {
                                                                                    echo "value='$invInfo[invModel]'";
                                                                                } ?>>
                    <label for="invDescription">Description</label>
                    <textarea name="invDescription" id="invDescription" cols="20" rows="2" required><?php if (isset($invDescription)) {
                                                                                                        echo "$invDescription";
                                                                                                    }
                                                                                                    ?></textarea>
                    <label for="invImage">Image Path</label>
                    <input type="text" id="invImage" name="invImage" value="/phpmotors/images/no-image.png" <?php if (isset($invImage)) {
                                                                                                                echo "value='$invImage'";
                                                                                                            }
                                                                                                            ?> required>
                    <label for="invThumbnail">Thumbnail Path</label>
                    <input type="text" id="invThumbnail" name="invThumbnail" value="/phpmotors/images/no-image.png" <?php if (isset($invThumbnail)) {
                                                                                                                        echo "value='$invThumbnail'";
                                                                                                                    }
                                                                                                                    ?> required>
                    <label for="invPrice">Price</label>
                    <input type="number" step="any" id="invPrice" name="invPrice" <?php if (isset($invPrice)) {
                                                                                        echo "value='$invPrice'";
                                                                                    }
                                                                                    ?> required>
                    <label for="invStock"># In Stock</label>
                    <input type="number" id="invStock" name="invStock" <?php if (isset($invStock)) {
                                                                            echo "value='$invStock'";
                                                                        }
                                                                        ?> required>
                    <label for="invColor">Color</label>
                    <input type="text" id="invColor" name="invColor" <?php if (isset($invColor)) {
                                                                            echo "value='$invColor'";
                                                                        }
                                                                        ?> required>
                    <input type="submit" name="submit" id="addVehicleBtn" value="Update Vehicle">
                    <input type="hidden" name="action" value="updateVehicle">
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