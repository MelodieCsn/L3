class CompteBancaire
{
protected:
	float solde;
public:
	CompteBancaire();
	CompteBancaire(float s);
	virtual ~CompteBancaire();
	virtual void deposer(int);
};

class CompteRemunere : public CompteBancaire
{
public:
	CompteRemunere();
	CompteRemunere(float s);
	virtual ~CompteRemunere();
	virtual void deposer(int);
};

class CompteDepot : public CompteBancaire
{
public:
	CompteDepot();
	CompteDepot(float s);
	virtual ~CompteDepot();
	virtual void deposer(int);
};

class CompteDepotRemunere : virtual public CompteDepot, virtual public CompteRemunere
{
public:
	CompteDepotRemunere();
	CompteDepotRemunere(float s);
	virtual ~CompteDepotRemunere();
};

//si héritage pas virtuel, chaque instance de compte dépot rémunéré a deux attributs solde, 
//un pour le comptedépot l'autre pour le compte rémunéré car cdr hérite des deux

//avec virtual, pas d'attribut répété
