#pragma once
#include<iostream>
#include"Locatie.h"
using namespace std;

class Eveniment {
private:
	Locatie* locatie;
	char* denumire;
	string data;
	string ora;
	int* nrLocuriOcupatePerZona;
	int* locuriOcupate;
	

public:
	
	Eveniment();

	Eveniment(Locatie ,const char* , string , string );

	Eveniment(const Eveniment& );

	~Eveniment();

	int* getNrLocuriOcupatePerZona();

	int* getLocuriOcupate();

	Locatie getLocatie();

	char* getDenumire();

	string getData();

	string getOra();

	int getIndexPentruZona(string );

	void setLocatie(Locatie );

	void setDenumire(const char* );

	void setData(string);

	void setOra(string );

	bool esteInvalid();

	bool verificareEvenimentIncheiat();

	bool contineZona(string);

	bool contineLocInZona(int , string );

	bool validareLocDuplicat(int );

	void adaugaLoc(int, string);
	
	void stergeLoc(int , string );

	Eveniment& operator=( Eveniment&);

	explicit operator char* ();

	bool operator<(Eveniment );

	friend ostream& operator<<(ostream& , Eveniment );

	friend istream& operator>>(istream& , Eveniment& );
};