#pragma once
#include<iostream>
using namespace std;

class Locatie {
private:
	const int numarMaximLocuri;
	string* zone;
	int* nrLocuriPerZona;
	int nrZone;
	float* preturiPerZona;
public:
	Locatie();

	Locatie(int , string* , int* , int ,float*);

	Locatie(const Locatie& );

	Locatie& operator=(const Locatie& );

	string operator[](int );

	Locatie& operator--();

	Locatie operator--(int);

	~Locatie();

	long getNumarMaximLocuri();

	string* getZone();

	int* getNrLocuriPerZona();

	int getNrZone();

	float* getPreturiPerZona();

	void setZone(string* , int* , int ,float *);

	int numarLocuriNeutilizate();
	
	int sumaLocuriUtilizate();

	bool esteInvalida();

	static Locatie ceaMaiMareCapacitate(Locatie* , int );

	friend istream& operator>>(istream& , Locatie& );
	
	friend ostream& operator<<(ostream& , Locatie );
};

