<?php

    // configuration
    require("../includes/config.php"); 
    

    // if user reached not page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] != "POST")
    {
        // else render form
        render("sell_form.php", ["title" => "Sell"]);
    }
    else
    {
        if (empty ($_POST ["stock_name"]))
        {
            apologize ("you need to enter symbol of your stock name to sell.");
        }
        
        
        $id = $_SESSION["id"];                  
        $stock_name = strtoupper($_POST ["stock_name"]);
            
        $stock = lookup ($stock_name);
        $price = $stock ["price"];
        
        $rows = CS50::query("SELECT * FROM portfolio WHERE user_id = $id");
        $shares = $rows [0]["shares"];
        $credit = $price * $shares ;
        
        $selling_update = CS50::query ("DELETE FROM portfolio where user_id = '$id' AND symbol = '$stock_name'"); 
        if ($selling_update == false)
        {
            apologize ("Errors on selling while deleting from portfolio table on SQL.");
        }
        
        $cash_update = CS50::query ("UPDATE users set cash = cash + $credit WHERE id = $id");
        if ($cash_update == false)
        {
            appologize ("Errors on updating cash on users table on SQL");
        }
        
        //for history
        $update_SELL_history = CS50::query ("INSERT INTO history (user_id, transaction, symbol, price, shares) VALUES (?, ?, ?, ?, ?)", $id, "SELL", $stock_name, $price, $shares ) ;
        if ($update_SELL_history == false)
        {
            apologize ("Errors on updaring history for selling");
        }
      
        redirect ("index.php");
    }
    
?>