#pragma once
#include<iostream>
#include<list>
#include"Locatie.h"
using namespace std;

class Eveniment {
private:
	static list<Eveniment>* evenimenteCreate;
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

	static list<Eveniment> getEvenimenteCreate();

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

	virtual bool esteInvalid();

	bool verificareEvenimentIncheiat();

	bool contineZona(string);

	bool contineLocInZona(int , string );

	bool validareLocDuplicat(int );

	virtual void adaugaLoc(int, string);
	
	void stergeLoc(int , string );

	static void afiseazaEvenimenteCreate();

	static Eveniment& contineEveniment(string);
	
	static bool contineEveniment(string, bool);

	Eveniment& operator=( Eveniment&);

	explicit operator char* ();

	bool operator==(Eveniment&);

	bool operator<(Eveniment );

	friend ostream& operator<<(ostream& , Eveniment );

	friend istream& operator>>(istream& , Eveniment& );
};