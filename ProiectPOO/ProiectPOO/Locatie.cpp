#include<iostream>
#include<string>
using namespace std;
#include"Locatie.h"
#include"MetodeUtile.h"

	Locatie::Locatie() :numarMaximLocuri(0) {
		zone = nullptr;
		nrLocuriPerZona = nullptr;
		nrZone = 0;
		preturiPerZona = nullptr;
	}

	Locatie::Locatie(int numarMaximLocuri, string* zone, int* nrLocuriPerZona, int nrZone,float* preturi) :numarMaximLocuri(numarMaximLocuri) {
		if (zone != nullptr && nrLocuriPerZona != nullptr && nrZone > 0 && preturi!=nullptr) {
			this->zone = new string[nrZone];
			this->nrLocuriPerZona = new int[nrZone];
			this->preturiPerZona = new float[nrZone];
			this->nrZone = nrZone;
			int sumaLocuri = 0;
			for (int i = 0; i < nrZone; i++)
			{
				this->nrLocuriPerZona[i] = nrLocuriPerZona[i];
				this->zone[i] = zone[i];
				this->preturiPerZona[i] = preturi[i];
				sumaLocuri += nrLocuriPerZona[i];
				
			}

			if(sumaLocuri>numarMaximLocuri){
				throw  exception("Datele introduse pentru locatie sunt invalide");
			}
		}
		else {
			throw  exception("Datele introduse pentru locatie sunt invalide");
		}
	}

	Locatie::Locatie(const Locatie& l): numarMaximLocuri(l.numarMaximLocuri) {
		if(l.zone != nullptr && l.nrLocuriPerZona != nullptr && l.nrZone > 0 && l.preturiPerZona != nullptr){
			zone = new string[l.nrZone];
			nrLocuriPerZona = new int[l.nrZone];
			preturiPerZona = new float[l.nrZone];
			nrZone = l.nrZone;
			for (int i = 0; i < l.nrZone; i++)
			{
				preturiPerZona[i] = l.preturiPerZona[i];
				nrLocuriPerZona[i] = l.nrLocuriPerZona[i];
				zone[i] = l.zone[i];
			}
		}
		else {
			zone = nullptr;
			nrLocuriPerZona = nullptr;
			nrZone = 0;
			preturiPerZona = nullptr;
		}
		
	}

	Locatie& Locatie::operator=(const Locatie& l) {
		int sumaLocuri = 0;
		for (int i = 0; i < l.nrZone; i++)
		{
			sumaLocuri += l.nrLocuriPerZona[i];
		}
		if (sumaLocuri <= numarMaximLocuri) {

			if (this->zone != nullptr) {
				delete[] this->zone;
			}
			if (this->nrLocuriPerZona != nullptr) {
				delete[] this->nrLocuriPerZona;
			}
			if (preturiPerZona != nullptr) {
				delete[] preturiPerZona;
			}
			this->preturiPerZona = new float[l.nrZone];
			this->zone = new string[l.nrZone];
			this->nrLocuriPerZona = new int[l.nrZone];
			this->nrZone = l.nrZone;
			for (int i = 0; i < l.nrZone; i++)
			{
				preturiPerZona[i] = l.preturiPerZona[i];
				this->nrLocuriPerZona[i] = l.nrLocuriPerZona[i];
				this->zone[i] = l.zone[i];
			}
		}
		return *this;
	}

	string Locatie::operator[](int index) {
		if (index >= 0 && index < nrZone) {
			return zone[index];
		}
		else {
			throw exception("Index invalid");
		}
	}

	Locatie& Locatie::operator--() {
		for (int i = 0; i < nrZone; i++)
		{
			if (preturiPerZona[i] > 0) {
				preturiPerZona[i]--;
			}
		}
		return *this;
	}

	Locatie Locatie::operator--(int) {
		Locatie copie = *this;
		for (int i = 0; i < nrZone; i++)
		{
			if (preturiPerZona[i] > 0) {
				preturiPerZona[i]--;
			}
		}
		return copie;
	}

	Locatie::~Locatie() {
		if (this->zone != nullptr) {
			delete[] this->zone;
		}
		if (this->nrLocuriPerZona != nullptr) {
			delete[] this->nrLocuriPerZona;
		}
		if (preturiPerZona != nullptr) {
			delete[] preturiPerZona;
		}
	}

	long Locatie::getNumarMaximLocuri() {
		return numarMaximLocuri;
	}

	string* Locatie::getZone() {
		if (zone != nullptr && nrZone>0) {
			string* copie = new string[nrZone];
			for (int i = 0; i < nrZone; i++)
			{
				copie[i] = zone[i];
			}
			return copie;
		}
		return nullptr;
	}

	float* Locatie::getPreturiPerZona() {
		if (preturiPerZona != nullptr && nrZone > 0) {
			float* copie = new float[nrZone];
			for (int i = 0; i < nrZone; i++)
			{
				copie[i] = preturiPerZona[i];
			}
			return copie;
		}
		return nullptr;
	}

	int* Locatie::getNrLocuriPerZona() {
		if (nrLocuriPerZona != nullptr && nrZone > 0) {
			int* copie = new int[nrZone];
			for (int i = 0; i < nrZone; i++)
			{
				copie[i] = nrLocuriPerZona[i];
			}
			return copie;
		}
		return nullptr;

	}

	int Locatie::getNrZone() {
		return nrZone;
	}

	void Locatie::setZone(string* zone,int* nrLocuriPerZona,int nrZone,float* preturi) {
		
				
		if (zone != nullptr && nrLocuriPerZona != nullptr && nrZone > 0 && preturi!=nullptr) {
			int sumaLocuri = 0;
			for (int i = 0; i < nrZone; i++)
			{
					sumaLocuri += nrLocuriPerZona[i];
		
			}
			if (sumaLocuri <= numarMaximLocuri ) {

				if (this->zone != nullptr) {
					delete[] this->zone;
				}
				if (this->nrLocuriPerZona != nullptr) {
					delete[] this->nrLocuriPerZona;
				}
				if (preturiPerZona != nullptr) {
					delete[] preturiPerZona;
				}
				preturiPerZona = new float[nrZone];
				this->zone = new string[nrZone];
				this->nrLocuriPerZona = new int[nrZone];
				this->nrZone = nrZone;
				for (int i = 0; i < nrZone; i++)
				{
					preturiPerZona[i] = preturi[i];
					this->nrLocuriPerZona[i] = nrLocuriPerZona[i];
					this->zone[i] = zone[i];
				}
			}
			
		}

		

	}

	//Locurile care nu au fost alocate niciunei zone
	int Locatie::numarLocuriNeutilizate() {
		if (nrLocuriPerZona != nullptr) {
			return numarMaximLocuri - sumaLocuriUtilizate();
		}
		return -1;
	}

	//Suma locurilor alocate pentru toate zonele
	int Locatie:: sumaLocuriUtilizate() {

		if (nrLocuriPerZona != nullptr) {
			int sumaLocuriUtilizate = 0;
			for (int i = 0; i < nrZone; i++)
			{
				sumaLocuriUtilizate += nrLocuriPerZona[i];
			}
			return sumaLocuriUtilizate;
		}
		return -1;
	}

	bool Locatie::esteInvalida() {
		if (numarMaximLocuri == 0 || nrZone == 0 || nrLocuriPerZona==nullptr || zone==nullptr || preturiPerZona == nullptr) {
			return true;
		}
		return false;
	}

	Locatie Locatie::ceaMaiMareCapacitate(Locatie* locatii, int nrLocatii) {
		if (locatii != nullptr && nrLocatii > 0) {
			int max = 0,poz = 0;
			
			for (int i = 0; i < nrLocatii; i++)
			{
				if (locatii[i].numarMaximLocuri > max) {
					max = locatii[i].numarMaximLocuri;
					poz = i;
				}
			}
			return locatii[poz];
		}
	 }

istream& operator>>(istream& in, Locatie& l) {
	cout << "Numar de zone: ";
	int nrZone;
	in >> nrZone;
	if (nrZone > 0) {
		l.nrZone = nrZone;
		cout << "Zone: "<<endl;
		string zona;
		if (l.zone != nullptr) {
			delete[]l.zone;
		}
		l.zone = new string[nrZone];
		for (int i = 0; i < nrZone; i++)
		{
			cout << "Zona " << (i + 1) << ": ";
			in >> zona;
			if (zona != "") {
				l.zone[i] = zona;
			}
			else {
				cout << "Zona introdusa este invalida!"<<endl;
				i--;
			}
		}
		string nrLocuriZona;
		if (l.nrLocuriPerZona != nullptr) {
			delete[]l.nrLocuriPerZona;
		}
		l.nrLocuriPerZona = new int[l.nrZone];
		int sumaNrLocuri = 0;

		for (int i = 0; i < nrZone; i++)
		{
			cout << "Numar de locuri pentru zona " << (i + 1) << ": ";
			in >> nrLocuriZona;
			if (MetodeUtile::contineDoarCifre(nrLocuriZona)) {
				sumaNrLocuri += stoi(nrLocuriZona);
					if (sumaNrLocuri <= l.numarMaximLocuri) {

						l.nrLocuriPerZona[i] = stoi(nrLocuriZona);
					}
					else {
						cout << "Numar de locuri nu poate sa depaseasca numarul maxim alocat!(maxim "<<l.numarMaximLocuri<<")" << endl;
						i--;
						sumaNrLocuri -= stoi(nrLocuriZona);

					}
			}
			else {
				cout << "Numarul de locuri pentru aceasta zona este invalid!" << endl;
				i--;

			}
		}
		string pret;
		if (l.preturiPerZona != nullptr) {
			delete[] l.preturiPerZona;
		}
		l.preturiPerZona = new float[l.nrZone];
		for (int i = 0; i < nrZone; i++)
		{
			cout << "Pretul pentru zona " << (i + 1) << ": ";
			in >> pret;
			if (MetodeUtile::contineDoarCifre(pret) && stoi(pret)>=0) {
				l.preturiPerZona[i] = stoi(pret);
			}
			else {
				cout << "Pretul introdus pentru aceasta zona este invalid!" << endl;
				i--;
			}
		}

	}
	else {
		cout << "Numarul de zone introdus este invalid!"<<endl;
	}
	return in;
}

ostream& operator<<(ostream& out, Locatie l) {
	out << "Numar maxim de locuri: " << l.numarMaximLocuri<<endl;
	out << "Numar de zone: " << l.nrZone<<endl;
	if (l.zone != nullptr && l.nrZone>0) {
		out << "--Zone--" << endl;
		for (int i = 0; i < l.nrZone; i++)
		{
			out << "Zona " << (i + 1) << ": " << l.zone[i]<<endl;
		}
	}
	if (l.nrLocuriPerZona != nullptr && l.nrZone > 0) {
		out << "--Numar de locuri pentru fiecare zona--" << endl;
		for (int i = 0; i < l.nrZone; i++)
		{
			out << "Numar de locuri pentru  zona " << (i + 1) << ": " << l.nrLocuriPerZona[i]<<endl;
		}
	}
	if (l.preturiPerZona != nullptr && l.nrZone > 0) {
		out << "--Preturi pentru fiecare zona--" << endl;
		for (int i = 0; i < l.nrZone; i++)
		{
			out << "Pretul pentru  zona " << (i + 1) << ": " << l.preturiPerZona[i] << " RON" << endl;
		}
	}
	return out;
}