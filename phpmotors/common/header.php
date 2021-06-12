    <div id="top-header">
        <img src="/phpmotors/images/site/logo.png" alt="PHP Motors Logo" id="logo">
        <?php if (isset($cookieFirstname)) {
            echo "<span>Welcome $cookieFirstname</span>";
        } ?>
        <a href="/phpmotors/accounts/index.php?action=login" title="Login or 
        Register with PHP Motors" id="login">My Account</a>
    </div>