#pragma once
#include<iostream>
#include<vector>
#include"Eveniment.h"
using namespace std;


class Bilet {
private:
	static vector<Bilet>* bileteCreate;
	static int nrBilete;
	const int idBilet;
	bool validat;
	string tipBilet;
	int loc;
	Eveniment* eveniment;
	int pret;

public:
	Bilet();

	Bilet(string, int, Eveniment&,int);

	Bilet(const Bilet&);
	
	static int genereazaIdRandom();

	static int getNrBilete();

	static vector<Bilet> getBileteCreate();

	int getPret();
	
	int getIdBilet();

	bool getValidat();

	string getTipBilet();

	int getLoc();

	Eveniment getEveniment();

	void setLoc(int,string);

	void setEveniment(Eveniment&);

	virtual void valideaza();

	static void valideazaBiletulSpecificat(int bilet);

	static void valideazaUltimulElement();

	virtual bool esteInvalid();

	static void afiseazaBileteCreate();

	static Bilet& contineBilet(int idBilet);

	static bool contineBilet(int idBilet, bool);

	Bilet& operator=(const Bilet& );

	bool operator!();

	bool operator>=(Bilet);

	friend istream& operator>>(istream& , Bilet& );

	friend ostream& operator<<(ostream& , Bilet );
};
