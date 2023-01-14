#pragma once
#include"Bilet.h"

class PrelucrareFisier
{
	virtual  void citesteBilet(ifstream&)=0;

	virtual  void citesteEveniment(ifstream&) = 0;

	virtual  void citesteLocatie(ifstream&) = 0;

	virtual void scrie(Bilet)=0;

	virtual void scrie(Eveniment) = 0;
	
	virtual void scrie(Locatie) = 0;
};

