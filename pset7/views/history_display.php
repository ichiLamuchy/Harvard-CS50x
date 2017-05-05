
    <div>
        <table class = "table">
                <tr>
		          <th class="text-center">Transaction</th>
		          <th class="text-center">Company</th>
		          <th class="text-center">Price</th>
		          <th class="text-center">Shares</th>
		          <th class="text-center">Time</th>
	            </tr>
            <?php foreach ($rows as $row): ?>
                <tr>
                    <td><?= $row["transaction"] ?></td>
                    <td><?= $row["symbol"] ?></td>
                    <td><?= $row["price"] ?></td>
                    <td><?= $row["shares"] ?></td>
                    <td><?= $row["time_stamp"] ?></td>
                </tr>
            <?php endforeach ?>
        </Table>
    </div>
    


