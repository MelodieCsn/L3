#include<iostream>
#include<string>
using namespace std;
#include"vers.h"

Vers::Vers(){} //constructeur par défaut
Vers::Vers(string sm){suiteMots=sm;} //constructeur paramétré
Vers::Vers(string sm, string r){suiteMots=sm;rime=r;} //constructeur paramétré redéfini pour avoir une rime en + des mots
Vers::~Vers(){}string //destructeur

Vers::getSuiteMots()const //getters et setters
{return suiteMots;}
void Vers::setSuiteMots(string sm)
{suiteMots=sm;}
string Vers::getRime()const
{return rime;}
void Vers::setRime(string r)
{rime=r;}

void Vers::saisie(istream& is) //fonction qui prend la saisie du vers puis de la rime
{cout <<"vers puis rime" <<endl;is>>suiteMots>>rime;}
void Vers::affiche(ostream& os)const //
{os<<"<<"<<suiteMots<<">>";}