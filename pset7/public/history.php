<?php

    // configuration
    require("../includes/config.php"); 
    $id = $_SESSION ["id"];    
    
    
    
    $rows = CS50::query ("SELECT * FROM history WHERE user_id = $id");
    // hang on here, i used many $id - shares etc, does it not get confused? it is logged on at the moment so $id =
    //however apart from gloval variable, all other ones are local so soud stay here not get confused i guess.
    
    
    render("history_display.php", ["title" => "History", "rows" => $rows]);
    
?>