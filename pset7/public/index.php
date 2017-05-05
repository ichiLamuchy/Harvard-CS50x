<?php

    //pass value of name, price, symbol, preferbly on table and also show how much cash they still have
    // lookup pass value onto $stock
    // query function

    // configuration
    require("../includes/config.php"); 
    $id  = $_SESSION["id"];             // when login $_SESSION["id"] = $row["id"];user's now logged in by storing user's ID in session
    //
    $rows = CS50::query("SELECT * FROM portfolio WHERE user_id = $id");  
    
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);   
        if ($stock !== false)
        {
            $positions[] = [                    
                "name" => $stock["name"],       
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];
        }
    }
    
    //this return to
    $cash = CS50::query("SELECT username, cash FROM users WHERE id = $id"); 
    
    // render portfolio
    render("portfolio.php", ["title" => "Positions", "positions" => $positions, "cash" => $cash]); 


?>
