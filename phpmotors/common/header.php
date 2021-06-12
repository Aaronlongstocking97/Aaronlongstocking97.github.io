    <div id="top-header">
        <img src="/phpmotors/images/site/logo.png" alt="PHP Motors Logo" id="logo">
        <?php if (isset($_SESSION['sessionFirstname'])) {
            echo $_SESSION['sessionFirstname'];
        }
        ?>
        <a href="/phpmotors/accounts/index.php?action=login" title="Login or 
        Register with PHP Motors" id="login">My Account</a>
    </div>