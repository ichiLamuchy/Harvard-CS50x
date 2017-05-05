<?php
    // configuration //
    require("../includes/config.php");

     //if user reached page via GET (as by clicking a link or via redirect) //
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("quote_form.php", ["title" => "Quote"]);
    }

    // else if user reached page via POST (as by submitting a form via POST) //
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
       // validate submission //
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide symbol for quote.");
        }
        
        $stock = lookup($_POST["symbol"]);
        if ($stock === false)
        {
            apologize ("it is not valid symbol");
        }
        
        render("quote_result.php", ["title" => "Quote", "name" => $stock ["name"], "symbol" => $stock ["symbol"], "price" => $stock["price"]]);
        

    }
    render ("quote_form.php", ["title" => "Quote"]);

?>