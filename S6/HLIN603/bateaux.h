class Bateau
{
protected:
	int navZone;
public:
	Bateau();
	Bateau(int n);
	virtual ~Bateau();
};

class BateauAaubes : public Bateau
{
protected:
	String ModeleEntrainementAubes;
public:
	BateauAaubes();
	BateauAaubes(String modeE);
	virtual ~BateauAaubes();
};

class BateauPlage : public Bateau
{
protected:
	int DureeLocation;
public:
	BateauPlage();
	BateauPlage(int d);
	virtual ~BateauPlage();
};

class PetitMultiCoques : public BateauPlage
{
protected:
	int nbrCoques;
public:
	PetitMultiCoques();
	PetitMultiCoques(int nbr);
	virtual ~PetitMultiCoques();
};

class BPSansMoteur : public BateauPlage
{
protected:
	String ModePropulsion;
public:
	BPSansMoteur();
	BPSansMoteur(String modeP);
	virtual ~BPSansMoteur();
};

class CompteDepotRemunere : virtual public CompteDepot, virtual public CompteRemunere
{
public:
	CompteDepotRemunere();
	CompteDepotRemunere(float s);
	virtual ~CompteDepotRemunere();
};