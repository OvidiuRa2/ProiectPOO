#include<iostream>
#include<string>
#include"Locatie.h"	
#include"MetodeUtile.h"
using namespace std;

list<Locatie>* Locatie::locatiiCreate = new list<Locatie>();

	Locatie::Locatie() :numarMaximLocuri(0) {
		zone = nullptr;
		nrLocuriPerZona = nullptr;
		nrZone = 0;
		preturiPerZona = nullptr;
		denumire = "anonim";
		 locatiiCreate->push_back(*this);
	}

	Locatie::Locatie(int numarMaximLocuri, string* zone, int* nrLocuriPerZona, int nrZone,float* preturi,string denumire) :numarMaximLocuri(numarMaximLocuri) {
		if (zone != nullptr && nrLocuriPerZona != nullptr && nrZone > 0 && preturi!=nullptr
			&& denumire!="" && MetodeUtile::contineDoarLitere(denumire)) {
			this->zone = new string[nrZone];
			this->nrLocuriPerZona = new int[nrZone];
			this->preturiPerZona = new float[nrZone];
			this->nrZone = nrZone;
			this->denumire = denumire;
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
		locatiiCreate->push_back(*this);
		}
		else {
			throw  exception("Datele introduse pentru locatie sunt invalide");
		}
	}
	
	Locatie::Locatie(const Locatie& l): numarMaximLocuri(l.numarMaximLocuri) {
		if(l.zone != nullptr && l.nrLocuriPerZona != nullptr && l.nrZone > 0 && l.preturiPerZona != nullptr 
			&& l.denumire != "" && MetodeUtile::contineDoarLitere(denumire)) {
			zone = new string[l.nrZone];
			nrLocuriPerZona = new int[l.nrZone];
			preturiPerZona = new float[l.nrZone];
			nrZone = l.nrZone;
			denumire = l.denumire;
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
			denumire = "";
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
			denumire = l.denumire;
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

	bool Locatie::operator!=(Locatie& l) {
		if (denumire == l.denumire) {
			return false;
		}
		if (numarMaximLocuri == l.numarMaximLocuri) {
			return false;
		}
		if (nrZone == l.nrZone) {
			return false;
		}
		for (int i = 0; i < nrZone; i++)
		{
			if (zone[i] == l.zone[i]) {
				return false;
			}
			if (nrLocuriPerZona[i] == l.nrLocuriPerZona[i]) {
				return false;
			}
			if (preturiPerZona[i] == l.preturiPerZona[i]) {
				return false;
			}
		}
		return true;
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

	list<Locatie> Locatie::getLocatiiCreate() {
		return *locatiiCreate;
	}

	string Locatie::getDenumire() {
		return denumire;
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
	void Locatie::setDenumire(string denumire) {
		if(denumire!="" && MetodeUtile::contineDoarLitere(denumire)){
			this->denumire = denumire;
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
		if (numarMaximLocuri == 0 || nrZone == 0 || nrLocuriPerZona==nullptr || zone==nullptr || preturiPerZona == nullptr || denumire == "") {
			return true;
		}
		return false;
	}

	string Locatie::ceaMaiMareCapacitate(list<Locatie> locatii) {
		list<Locatie>::iterator it;
		string loc="";
		int max = 0;
		for (it = locatiiCreate->begin(); it != locatiiCreate->end(); ++it)
		{
			if (it->getNumarMaximLocuri() > max) {
				max = it->getNumarMaximLocuri();
				loc = it->getDenumire();
			}
		}
		return loc;
		
	}

	void Locatie::afiseazaLocatiiCreate() {
		list<Locatie>::iterator it;
		for (it = locatiiCreate->begin(); it != locatiiCreate->end(); ++it)
			cout << * it << endl;
	}

	Locatie Locatie::contineLocatia(string nume) {
		list<Locatie>::iterator it;
		for (it = locatiiCreate->begin(); it != locatiiCreate->end(); ++it)
		{
			if (it->getDenumire() == nume) {
				return *it;
			}
		}
		throw  exception("Locatia introdusa nu exista");

	}

	bool Locatie::contineLocatia(string nume, bool) {
		list<Locatie>::iterator it;
		for (it = locatiiCreate->begin(); it != locatiiCreate->end(); ++it)
		{
			if (it->getDenumire() == nume) {
				return true;
			}
		}
		return false;
	}

istream& operator>>(istream& in, Locatie& l) {
	bool valid = false;
	while (valid == false) {

		cout << "Denumire:";
		string den;
		in >> ws;
		getline(in, den);
		if (den != "" && MetodeUtile::contineDoarLitere(den)) {
			l.denumire = den;
			valid = true;
		}
	}
	valid = false;
	int nrZone;
	while (valid == false) {
		string nr;
		cout << "Numar de zone: ";
		in >> nr;
			if (MetodeUtile::contineDoarCifre(nr)) {
			l.nrZone = stoi(nr);
			nrZone = stoi(nr);
			valid = true;
		}
		else {
			cout << "Numarul de zone introdus este invalid!" << endl;
		}
	}
		cout << "Zone: "<<endl;
		string zona;
		if (l.zone != nullptr) {
			delete[]l.zone;
		}
		l.zone = new string[nrZone];
		for (int i = 0; i < nrZone; i++)
		{
			cout << "Zona " << (i + 1) << ": ";
			in >> ws;
			getline(in,zona);
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


	return in;
}

ostream& operator<<(ostream& out, Locatie l) {
	out << "Denumire: " << l.denumire << endl;
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