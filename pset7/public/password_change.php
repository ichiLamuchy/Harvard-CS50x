<?php

    // configuration
    require("../includes/config.php");
        // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("password_change_form.php", ["title" => "Change Password"]);
    }
    // if user reached page via POST 
    if ($_SERVER["REQUEST_METHOD"] == "POST")  
    {

        // password and confirmation is not empty or
        //password confirmations are == then error
        if (empty($_POST["new_password"]))
        {
            apologize("You must provide your new password.");
        }
        elseif (empty($_POST["new_pw_confirmation"]))
        {
            apologize("You must confirm your new password.");
        }
        elseif ($_POST ["new_password"] != $_POST ["new_pw_confirmation"])
        {
            apologize ("Your new password and confirmation password doesn't match");
        }
        elseif ($_POST ["new_password"] == $_POST ["new_pw_confirmation"])
        { 
            $result = CS50::query("UPDATE users SET hash = ? WHERE id =?", password_hash($_POST["new_password"], PASSWORD_DEFAULT), $_SESSION ["id"]);
 
            if ($result == false)
            {
                apologize ("errors on resetting password" );
            }
            else
            {
                render("pw_change_success.php", ["title" => "Changed Password"]);
            }
        }
        
    }
?>