<?php

    // configuration
    require("../includes/config.php"); 
    

    // check if user using method POST
    if ($_SERVER["REQUEST_METHOD"] != "POST")
    {
        // else render form
       render("buy_form.php", ["title" => "Buy"]);
    }
    else
    {
        //check if they filled both sections on form
        if (empty ($_POST ["stock_name"]|| $_POST ["shares"]))
        {
            apologize ("You need to enter Symbol and Shares to buy.");
        }
        
        $shares_check = preg_match("/^\d+$/", $_POST["shares"]);
        
        if ($shares_check==false)
        {
            apologize ("You must enter a number for Shares");
        }
        
        else
        {
            $stock_name = strtoupper ($_POST ["stock_name"]);  
            $stock = lookup($stock_name);
        
            // check if the stock exists 
            if ($stock ["symbol"] == false)
            {
                apologize("Entere varied stock symbol, please.");
            }
        
            $id = $_SESSION["id"];                  
            $shares = $_POST ["shares"];

            $price = $stock ["price"];
            $cost = $shares * $price;
        
            $rows = CS50::query("SELECT * FROM users WHERE id = $id");
            $cash = $rows [0]["cash"];
        
            // check if they can afford 
            if ($cost > $cash)
            {
                apologize ("You have not got sufficiant funds to buy the shares.");
            }
            // add stock to portfolio
            $update_stock = CS50::query ("INSERT INTO portfolio (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES (shares)",$id, $stock_name, $shares);
       
            //take cash out 
            if ($update_stock == false)
            {
                apologize ("Errors on updating your portfolio.");
            }
            
            $update_cash = CS50::query ("UPDATE users SET cash = cash - $cost WHERE id = $id");
            if ($update_cash == false)
            {
                apologize ("Errors on updating your funds.");
            }
            //for history
            $buy = "BUY";
            $update_BUY_history = CS50::query ("INSERT INTO history (user_id, transaction, symbol, price, shares) VALUES (?, ?, ?, ?, ?)", $id, $buy, $stock_name, $price, $shares);
            if ($update_BUY_history == false)
            {
                apolpgize ("Errors on updatingyour history of buying");
            }
            
            
            redirect ("index.php");
        }
    }
    
?>