#pragma once
#include<iostream>
using namespace std;
#include"Eveniment.h"
using namespace std;

class Bilet {
private:
	static int nrBilete;
	const int idBilet;
	bool validat;
	string tipBilet;
	int loc;
	Eveniment* eveniment;
	int pret;

	int genereazaIdRandom();
public:
	Bilet();

	Bilet(string, int, Eveniment&);

	Bilet(const Bilet&);
	
	static int getNrBilete();

	int getPret();
	
	int getIdBilet();

	bool getValidat();

	string getTipBilet();

	int getLoc();

	Eveniment getEveniment();

	void setLoc(int,string);

	void setEveniment(Eveniment&);

	void valideaza();

	bool esteInvalid();

	Bilet& operator=(const Bilet& );

	bool operator!();

	bool operator>=(Bilet);

	friend istream& operator>>(istream& , Bilet& );

	friend ostream& operator<<(ostream& , Bilet );
};
