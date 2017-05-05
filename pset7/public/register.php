<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")  // if else if can be used with : after if syntax then ; at the end without {} nut do not mix these two
    {
        // TODO 
        // user and password is not empty or
        //password confirmations are == then error
        if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
        elseif (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
        elseif ($_POST ["confirmation"] != $_POST ["password"])
        {
            apologize ("Your password and confirmation password doesn't match");
        }
        elseif ($_POST ["confirmation"] == $_POST ["password"])
        { 
            $result = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
            
            if ($result == 0)
            {
                apologize ("Your user name is taken, create a new one");
            }
            else
            {
                $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
                $id = $rows[0]["id"];
                redirect("index.php");
            }
        }
        apologize("Invalid username and/or password.");
    }
?>