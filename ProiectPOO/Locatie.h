#pragma once
#include<iostream>
#include<list>
using namespace std;

class Locatie {
private:
	static list<Locatie>* locatiiCreate;
	string denumire;
	const int numarMaximLocuri;
	string* zone;
	int* nrLocuriPerZona;
	int nrZone;
	float* preturiPerZona;
public:
	Locatie();

	Locatie(int , string* , int* , int ,float*, string);

	Locatie(const Locatie& );

	Locatie& operator=(const Locatie& );

	string operator[](int );

	Locatie& operator--();

	Locatie operator--(int);

	bool operator!=(Locatie&);

	~Locatie();
	
	static list<Locatie> getLocatiiCreate();
	
	string getDenumire();

	long getNumarMaximLocuri();

	string* getZone();

	int* getNrLocuriPerZona();

	int getNrZone();

	float* getPreturiPerZona();

	void setZone(string* , int* , int ,float *);
	
	void setDenumire(string);

	virtual int numarLocuriNeutilizate();
	
	int sumaLocuriUtilizate();

	virtual bool esteInvalida();
	
	static void afiseazaLocatiiCreate();
	
	static bool contineLocatia(string, bool);
	
	static Locatie contineLocatia(string);

	static string ceaMaiMareCapacitate(list<Locatie>);

	friend istream& operator>>(istream& , Locatie& );
	
	friend ostream& operator<<(ostream& , Locatie );
};

