<?php
// PARTIE CONNEXION AU SERVEUR PHP
    session_start(); 
    ini_set('display_errors', 1); error_reporting(E_ALL); 

// PARTIE CONNEXION A SQL
    $dns = "mysql:host=mysql.etu.umontpellier.fr;dbname=e20160001412;charset=UTF8";
    include "pass.php";
    try{
        $dbh = new PDO( $dns, $login, $pass );
    }
    catch ( PDOException $e ){
        echo $e->getMessage();
    }
?>

<!DOCTYPE html>
<html>
    <head>
        <title> Trombinoscope </title>
        <meta charset="utf-8">
    </head>
    <body>
        <h1>Le plus beau trombinoscope del Mundo</h1>
 <!-- PARTIE FORMULAIRE -->
        <form>
            <select name="options[]" multiple>
                <?php
                $query_option = "
                SELECT nom 
                FROM options ;"; //requete
                $res_option = $dbh->query($query_option);  
                foreach($res_option as $enr){
                    echo "<option>".$enr["nom"]."</option>";
                }
                ?>
            </select>

            <label>order</label>
            <select name="order" >
                <option value="nom"> Nom </option>
                <option value="prenom"> Prenom </option>
                <option value="statut"> Status </option>
                <option value="groupe"> Groupe </option>
                <option value="option"> Option </option>
            </select>

            <input type="submit" value="Valider"/>
        </form>

        <?php
        if(isset($_GET["options"])){
            for($i=0; $i<sizeof($_GET["options"]); $i++){
                echo $_GET["options"][$i];
            }
        }
        if(isset($_GET["order"])){
            echo $_GET["order"];
        }
        ?>
<!-- PARTE SQL-->
<?php 
    $req = "SELECT e.nom,prenom,statut,groupe,e.email,o.nom as optnom,e.numStageA "; //requete de base 
    $req.= "FROM etudiant e; 
    // LEFT JOIN options o ON e.opt=o.code ";

    // Si $options[] est vide (debut ou tout deselectionne : on select tous)
    if (!empty($_POST['options']) && $nbopt=count($_POST['options'])){  // au moins 1 option selectionnée
        $ensemble="('{$_POST['options'][0]}'" ; // 1ere option
        for ($i=1;$i<$nbopt;$i++){
            $ensemble.=",'{$_POST['options'][$i]}'"; // ajouter les autres options
        }
        $req.= "WHERE e.opt IN $ensemble) "; //on rajoute les options dans la requete
    }
    if (!empty($_POST['order'])){ // si un ordre est sélectionné
        switch ($_POST['order']){	 
            case "option" : $req.= "ORDER BY optnom, nom, prenom;";break;//on rajoute à la requête un ordre changé
            case "groupe" : $req.= "ORDER BY groupe, nom, prenom;";break;
            case "statut" : $req.= "ORDER BY statut, nom, prenom;";break;
            default : $req.= "ORDER BY nom, prenom;";break;
        }
    }
    else{ $req.= "ORDER BY nom, prenom;";
        //echo "coucou";
    }
    echo $req;
    $res = $dbh->query($req) or die("Requête $req impossible");
    
    // Début de l'affichage
    echo "<table> <br> <br>";
    foreach( $res as $key ){
        echo "<tr> 
        <td> {$key['nom']} </td>
        <td> {$key['prenom']} </td>
        <td> {$key['numStageA']} </td>
        <td> {$key['opt']} </td>
        <td> {$key['opt.name']} </td>
        <tr>";
    }
    echo "</table>";
?>
    </body>
</html>