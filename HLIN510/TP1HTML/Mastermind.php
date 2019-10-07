
<?php

class Mastermind{
    protected $code=""; //code secret
    protected $lessai=array(); //liste des essais pécédents
    public function __construct($taille=4){
        for($i=0;$i<$taille;$i++){
            $c=rand(0,9);// nouveau chiffre qu'on va concatener aux anciens
            $this->code.="$c";
        }
    }
    public function valide($code){
        if(!is_string($code) || strlen($code)!=strlen($this->code) 
           || !ctype_digit($code)){
          return false;
        }
        return true;
    }
    public function test($code){
        if(!$this->valide($code))
          return false;
        $res=array("bon"=>0, "mal"=>0);
        $tampon=$this->code;  
        $deja_vu=false;
        for($i=0;$i<strlen($code);$i++){ // boucle des mals placés
          $pos = strpos($tampon,$code[$i]);
          if (!($pos === false)) {
            $res["mal"]++;
            $deja_vu=true;
            $tampon[$pos]='Y';
          }
        } // fin de boucle des mals placés
        for($i=0;$i<strlen($code);$i++){ // boucle des biens placés
          if($tampon[$i]==$code[$i]){
            $tampon[$i]='Y'; // afin de ne plus le prendre en compte
              $res["bon"]++;
          }
        }// fin de la boucle des biens placés
        
        $this->lessai[$code]=$res;
        return $res;
    }
    public function getTaille(){
      return strlen($this->code);
    }
    public function getEssais(){
        return $this->lessai;
    }

}

?>
