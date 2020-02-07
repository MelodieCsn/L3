#include<iostream>
#include<string>
using namespace std;
#include"compteBancaire.h"

int main(int argc, char const *argv[])
{
	// CompteBancaire* CB = new CompteBancaire(200);
	// CompteRemunere* CR = new CompteRemunere(200);
	// CompteDepot* CD = new CompteDepot(200);
	//CompteDepotRemunere* CDR = new CompteDepotRemunere(200);

	// delete CB;
	// delete CR;
	// delete CD;
	//delete CDR;

	CompteBancaire* comptes[3];
	comptes[0]=new CompteDepot();
	comptes[1]=new CompteRemunere();
	comptes[2]=new CompteBancaire();

	for(int i=0; i<3; i++){
		comptes[i]->deposer(200);
	}


	return 0;
}
