/*
Remarque : sans enregistrement et sans contraintes les lignes suivantes sont suffisantes : 
*/
DROP TABLE EMPRUNT; 
DROP TABLE CARACTERISE; 
DROP TABLE MOT_CLEF; 
DROP TABLE EXEMPLAIRE; 
DROP TABLE ABONNE; 
DROP TABLE LIVRE; 


prompt --**********************************--;
prompt -- CREATION DES RELATIONS-- ;
prompt --**********************************--;

CREATE TABLE LIVRE (
	ISBN VARCHAR(20), 
	TITRE VARCHAR(50) CONSTRAINT LITITRE NOT NULL, 
	SIECLE NUMERIC(2,0) CHECK (SIECLE BETWEEN 0 and 21),
	CATEGORIE VARCHAR(10)
);

prompt -- LIVRE créé ;

CREATE TABLE ABONNE (
	NUM_AB  NUMERIC(6,0),  
	NOM VARCHAR(12)  CONSTRAINT ABNOM NOT NULL, 
	PRENOM VARCHAR(10), 
	VILLE VARCHAR(30), 
 	TARIF NUMERIC(3,2),
 	REDUC NUMERIC(3,0),
	AGE NUMERIC(3,0),
	CONSTRAINT DOM_AGE CHECK (AGE BETWEEN 0 AND 120));

ALTER TABLE ABONNE ADD(
	DATE_NAI DATE,
	TYPE_AB VARCHAR(30) CHECK(TYPE_AB IN('ADULTE','ENFANT')),
	CAT_AB VARCHAR(30) CHECK(CAT_AB IN('REGULIER','OCCASIONNEL','A PROBLEME','EXCLU'))
);

prompt -- ABONNE créé ;

CREATE TABLE EXEMPLAIRE (
	NUMERO NUMERIC(4,0), 
	DATE_ACHAT DATE, 
	PRIX NUMERIC(5,2), 
	CODE_PRET VARCHAR(12) ,
	ETAT VARCHAR(15) CHECK (ETAT IN ('BON','ABIME','EN_REPARATION')), 
	ISBN  VARCHAR(20), 
	CONSTRAINT DOM_CODE_PRET CHECK (CODE_PRET IN ('EXCLU','EMPRUNTABLE','CONSULTABLE')) 
);

prompt -- EXEMPLAIRE créé ;
CREATE TABLE MOT_CLEF (
	MOT VARCHAR(20)
);

ALTER TABLE MOT_CLEF ADD(
	MOT_GENE VARCHAR(20),
	CONSTRAINT PK_MOT_CLEF PRIMARY KEY (MOT),
	CONSTRAINT FK_MOT_CLEF FOREIGN KEY MOT_CLEF(PK_MOT_CLEF)
);

prompt -- MOT_CLEF créé ;

CREATE TABLE EMPRUNT (
	NUM_AB  NUMERIC(6,0),
	NUM_EX NUMERIC (4,0) ,
	D_EMPRUNT DATE, 
	D_RETOUR DATE, 
	D_RET_REEL DATE, 
	NB_RELANCE NUMERIC(1,0) CHECK (NB_RELANCE IN (1,2,3))
);

prompt -- EMPRUNT créé ;

CREATE TABLE CARACTERISE (
	ISBN VARCHAR(20), 
	MOT VARCHAR(20)
);

prompt -- CARACTERISE créé;
