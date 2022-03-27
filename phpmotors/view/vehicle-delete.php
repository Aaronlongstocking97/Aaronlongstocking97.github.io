<?php
if ($_SESSION['clientData']['clientLevel'] < 2) {
    header('location: /phpmotors/');
    exit;
}

// Build the classifications option list
$classifList = '<select name="classificationId" id="classificationId">';
$classifList .= "<option>Choose a Car Classification</option>";
foreach ($classifications as $classification) {
    $classifList .= "<option value='$classification[classificationId]'";
    if (isset($classificationId)) {
        if ($classification['classificationId'] === $classificationId) {
            $classifList .= ' selected ';
        }
    } elseif (isset($invInfo['classificationId'])) {
        if ($classification['classificationId'] === $invInfo['classificationId']) {
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
    <title id="page-title"><?php if (isset($invInfo['invMake'])) {
                                echo "Delete $invInfo[invMake] $invInfo[invModel]";
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
            <h1 id="content"><?php if (isset($invInfo['invMake'])) {
                                    echo "Delete $invInfo[invMake] $invInfo[invModel]";
                                } ?></h1>
            <?php
            if (isset($message)) {
                echo $message;
            }
            ?>
            <h2 id="warning">*Note all Fields are Required</h2>
            <form action="/phpmotors/vehicles/index.php" method="post">
                <form method="post" action="/phpmotors/vehicles/">
                    <fieldset id="align">
                        <label for="invMake">Vehicle Make</label>
                        <input type="text" readonly name="invMake" id="invMake" <?php
                                                                                if (isset($invInfo['invMake'])) {
                                                                                    echo "value='$invInfo[invMake]'";
                                                                                } ?>>

                        <label for="invModel">Vehicle Model</label>
                        <input type="text" readonly name="invModel" id="invModel" <?php
                                                                                    if (isset($invInfo['invModel'])) {
                                                                                        echo "value='$invInfo[invModel]'";
                                                                                    } ?>>

                        <label for="invDescription">Vehicle Description</label>
                        <textarea name="invDescription" readonly id="invDescription"><?php
                                                                                        if (isset($invInfo['invDescription'])) {
                                                                                            echo $invInfo['invDescription'];
                                                                                        }
                                                                                        ?></textarea>

                        <input type="submit" class="regbtn" name="submit" value="Delete Vehicle">

                        <input type="hidden" name="action" value="deleteVehicle">
                        <input type="hidden" name="invId" value="<?php if (isset($invInfo['invId'])) {
                                                                        echo $invInfo['invId'];
                                                                    } ?>">

                    </fieldset>
                </form>
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