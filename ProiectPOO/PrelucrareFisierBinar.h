#pragma once
#include "PrelucrareFisier.h"
class PrelucrareFisierBinar :
    public PrelucrareFisier
{
 
public:
    virtual void citesteBilet(ifstream& ) override;
    virtual void citesteEveniment(ifstream&) override;
    virtual void citesteLocatie(ifstream& ) override;
    virtual void scrie( Bilet) override;
    virtual void scrie( Eveniment) override;
    virtual void scrie( Locatie) override;

    static void scrieNumeFisier(string);

    static void citesteNumeFisier();

    void citeste();
};

