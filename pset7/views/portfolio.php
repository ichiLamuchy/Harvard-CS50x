
    <div>
        <table class = "table">
                <tr>
		          <th class="text-center">Company</th>
		          <th class="text-center">Shares</th>
		          <th class="text-center">Price</th>
	            </tr>
            <?php foreach ($positions as $position): ?>
                <tr>
                    <td><?= $position["symbol"] ?></td>
                    <td><?= $position["shares"] ?></td>
                    <td><?= $position["price"] ?></td>
                </tr>
            <?php endforeach ?>
        </Table>
    </div>
    
    <div>
        <?php
            print (number_format($cash[0]["cash"],2) . " is your current balance"); //got it from w3 school
        ?>
    </div>
    <div>
    <a href="password_change.php"> Change </a> your password?
    </div>



