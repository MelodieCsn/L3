#include <iostream>
#include "compteBancaire.h"

// ne jamais manipuler les objets directment, toujours utiliser les adresses
// pointeurs partout, virtual partout

using namespace std;

CompteBancaire::CompteBancaire() : solde(0) {}

CompteBancaire::CompteBancaire(float s) : solde(s) {}

CompteBancaire::~CompteBancaire() {
	cout << "La banque vous doit " << solde << endl;
}
void CompteBancaire::deposer(int montant) {
	this.solde+=montant;
}

CompteRemunere::CompteRemunere() : CompteBancaire() {}

CompteRemunere::CompteRemunere(float s) : CompteBancaire(s) {}

CompteRemunere::~CompteRemunere() { 
	solde *= 1.10;
} 

void CompteRemunere::deposer(int montant) {
	this.solde+=montant+montant*1.1;
}

CompteDepot::CompteDepot() : CompteBancaire() {}

CompteDepot::CompteDepot(float s) : CompteBancaire(s) {}

CompteDepot::~CompteDepot() { 
	solde -= 100;
}

void CompteBancaire::deposer(int montant) {
	this.solde+=montant-1;
	if(solde<=1000){
		solde+=10;
	}
}

CompteDepotRemunere::CompteDepotRemunere() : CompteDepot(), CompteRemunere() {} 

CompteDepotRemunere::CompteDepotRemunere(float s) : CompteDepot(s), CompteRemunere(s) {}

CompteDepotRemunere::~CompteDepotRemunere() {}