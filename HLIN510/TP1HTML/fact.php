<!DOCTYPE html>
<html>
<head>
        <meta charset="utf-8" />
</head>
    <body>
        <?php
        function fact($n){
            if($n<2)return 1; return $n*fact($n-1);
        }
        if(isset($_GET['n'])){
            $r= fact($_GET['n']);
            echo $_GET['n']."!=".$r;
        }
        ?>
        <form action="">
            n=<input type="text" name="n"/> <br/>
            <input type="submit"/>
    </form>
    </body>
</html>
