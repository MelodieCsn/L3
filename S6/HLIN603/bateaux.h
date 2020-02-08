#include <string>
class Bateau
{
public:
	int navZone;
public:
	Bateau();
	Bateau(int n);
	virtual ~Bateau();
};

class BateauAaubes : public virtual Bateau
{
protected:
	int ModeleEntrainementAubes;
public:
	BateauAaubes();
	virtual ~BateauAaubes();
};

class BateauPlage : public virtual Bateau
{
protected:
	int DureeLocation;
public:
	BateauPlage();
	virtual ~BateauPlage();
};

class PetitMultiCoques : public virtual BateauPlage
{
protected:
	int nbrCoques;
public:
	PetitMultiCoques();
	virtual ~PetitMultiCoques();
};

class BPSansMoteur : public virtual BateauPlage
{
protected:
	int ModePropulsion;
public:
	BPSansMoteur();
	virtual ~BPSansMoteur();
};

class BateauAaubeEtPedales : public virtual BateauAaubes , public virtual BPSansMoteur
{
protected:
	int NbrePedales;
public:
	BateauAaubeEtPedales();
	virtual ~BateauAaubeEtPedales();
};

class PetitCatamaran : virtual public PetitMultiCoques
{
public:
	PetitCatamaran();
	virtual ~PetitCatamaran();
};

class Pedalo : virtual public PetitCatamaran, virtual public BateauAaubeEtPedales
{
public:
	Pedalo();
	virtual ~Pedalo();
};