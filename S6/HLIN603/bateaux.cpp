#include <iostream>
#include "bateaux.h"
#include <string>

// ne jamais manipuler les objets directement, toujours utiliser les adresses
// pointeurs partout, virtual partout

using namespace std;

Bateau::Bateau() : navZone(0) {}
Bateau::Bateau(int n) : navZone(n) {}
Bateau::~Bateau() {}

BateauAaubes::BateauAaubes() : Bateau(), ModeleEntrainementAubes(0) {navZone=100;}
BateauAaubes::~BateauAaubes() {}

BateauPlage::BateauPlage() : Bateau(), DureeLocation(0) {navZone=1;}
BateauPlage::~BateauPlage() {}

PetitMultiCoques::PetitMultiCoques() : BateauPlage(), nbrCoques(0) {}
PetitMultiCoques::~PetitMultiCoques() {}

BPSansMoteur::BPSansMoteur() : BateauPlage(), ModePropulsion(0) {}
BPSansMoteur::~BPSansMoteur() {}

BateauAaubeEtPedales::BateauAaubeEtPedales() : BateauAaubes(), BPSansMoteur(), NbrePedales(0) {cout<<"navZone AUBEPEDALES: "<<navZone<<endl;}
BateauAaubeEtPedales::~BateauAaubeEtPedales() {}

PetitCatamaran::PetitCatamaran() : PetitMultiCoques() {cout<<"navZone PETITCAT: "<<navZone<<endl;}
PetitCatamaran::~PetitCatamaran() {}

Pedalo::Pedalo() : PetitCatamaran(), BateauAaubeEtPedales() {cout<<"navZone PEDALO: "<<navZone<<endl;}
Pedalo::~Pedalo() {}