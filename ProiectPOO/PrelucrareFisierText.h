#pragma once
#include "PrelucrareFisier.h"

class PrelucrareFisierText :
    public PrelucrareFisier
{

public:
    void citeste(string);
    virtual void citesteBilet(ifstream&) override;
    virtual void citesteEveniment(ifstream&) override;
    virtual void citesteLocatie(ifstream&) override;
    virtual void scrie( Bilet) override;
    virtual void scrie( Eveniment) override;
    virtual void scrie( Locatie) override;
};

