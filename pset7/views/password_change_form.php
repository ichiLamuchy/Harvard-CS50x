<div>
    Please type your new password twice for confirmation.
</div>

<form action="password_change.php" method="post">
    <fieldset>
        <div class="form-group">
            <input class="form-control" name="new_password" placeholder="New Password" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="new_pw_confirmation" placeholder="Type New Password Again" type="password"/>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                Change
            </button>
        </div>
    </fieldset>
</form>
