<?php
session_start(); 

if(isset($_POST["auth"])){
    $rep="SELECT * FROM UTILISATEUR WHERE LOGIN=".$_POST["LOGIN"].";";
    $res=$dbh->query($req);
    if(res->rowCount()==1){// un utilisateur a ce login
        $user=$res->fetch(); // permet de récup $user['login'] et password
        if(){
            echo "Authentification réussie !";
            $_SESSION['login']=$_POST['login'];
        }

    }
}

?>
<!doctype html>
<html lang="fr">
<head>
<meta charset="utf-8" /> 
<title>Site d'authentification inutile</title>
</head>
<body>
<h1 align="center">Authentifie toi !</h1>
<form method="post"> 
<label>Login</label>
<input type="text" name="login"/> <br/>
<label>Password</label>
<input type="password" name="password"/> <br/>
<input type="submit" name="auth" value="se connecter nulle part"/> <br/>

</form>
</body>
</html>
