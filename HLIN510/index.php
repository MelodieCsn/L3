<?php
    $dns = "mysql:host=mysql.etu.umontpellier.fr;dbname=e20160001412;charset=UTF8";
    include "pass.php";
    try{
        $dbh = new PDO( $dns, $login, $pass );
    }
    catch ( PDOException $e ){
        echo $e->getMessage();
        die("erreur");
    }

    $query = "
    SELECT numStageA, sujet, respEnt, respPeda, nom  
    FROM etudiant, satgeA
    WHERE etudiant.numStageA= stage.numStageA;"; //requete
    $res = $dbh->query($query); 
?>   

<!DOCTYPE html>
<html>
    <head>
        <title> SQL </title>
        <meta charset="utf-8">
    </head>
<h1>MySQL</h1>
<h2>Etudiants participant au même stage</h2>

<table>

    <tr>
        <th> Numéro </th>
        <th> Sujet </th>
        <th> Responsable </th>
        <th> Tuteur </th>
        <th> Etudiants associés </th>
    </tr>
    <tr>
    <?php
        $query_stage = "
        SELECT * 
        FROM stageA
        WHERE sujet LIKE '%analyse%' ;"; //requete
        $res_stage = $dbh->query($query_stage);  
        foreach( $res_stage as $enr ){
            echo "<tr>
            <td> {$enr['numStageA']} </td>
            <td> {$enr['sujet']} </td>
            <td> {$enr['respEnt']} </td>
            <td> {$enr['respPeda']} </td> <td>";
            
            $query_etu="
            SELECT nom, prenom
            FROM etudiant
            WHERE numStageA=".$enr['numStageA'];
            $res_etu = $dbh->query($query_etu);
            foreach( $res_etu as $etu ){
                echo " {$etu['nom']} , {$etu['prenom']} <br/>";
            }
            echo "</td></tr>";
        }
        ?>

  
    

<?php   
    foreach( $res as $enr ){
        echo $enr['nom']; // ne pas oublier de mettre ce qu'on veut voir affiché
        echo "<br>";
    }
?>