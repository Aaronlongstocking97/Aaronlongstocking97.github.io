    <div id="top-header">
        <img src="/phpmotors/images/site/logo.png" alt="PHP Motors Logo" id="logo">
        <?php
        if (isset($_SESSION['loggedin'])) {
            $clientFirstName = $_SESSION['clientData']['clientFirstname'];
            echo '<a href="/phpmotors/accounts/index.php?action=User" title="PHP Motors Admin View" id="User">'
                . $clientFirstName
                . '   |   </a>'
                . '<a href="/phpmotors/accounts/index.php?action=Logout" title="Logout of PHP Motors" id="logout">Logout</a>';
        } else {
            echo '<a href="/phpmotors/accounts/index.php?action=login" title="Login or Register with PHP Motors" id="login">My Account</a>';
        }
        ?>
    </div>