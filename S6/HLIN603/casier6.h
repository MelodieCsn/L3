#ifndef Casier6_h
#define Casier6_h

template<typename produit>
Class Casier6{
    public:
        Casier6();
        virtual ~Casier6();
        virtual void range(produit* p, int numeroCase);
};

#endif