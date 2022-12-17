#include<iostream>
#include<string>
#include"Eveniment.h"
#include"Locatie.h"
#include"MetodeUtile.h"
using namespace std;

Eveniment::Eveniment() {
	locatie = new Locatie;
	denumire = nullptr;
	data = "";
	ora = "";
	nrLocuriOcupatePerZona = nullptr;	//vector in care salvez numarul total de bilete pentru fiecare zona pentru a nu putea crea mai multe bilete pentru o zona decat numarul maxim
	locuriOcupate = nullptr;	//vector in care salvez toate locurile pentru care am creat obiecte pt a nu crea bilete pe acelasi loc

}

Eveniment::Eveniment(Locatie locatie, const char* denumire, string data, string ora) {
	
	if (locatie.esteInvalida() == false  && denumire!=nullptr && MetodeUtile::contineDoarLitere(denumire) && MetodeUtile::valideazaData(data)
		&& MetodeUtile::valideazaOra(ora) ) {
		this->locatie = new Locatie(locatie);
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		this->data = data;
		this->ora = ora;
		nrLocuriOcupatePerZona = new int[this->locatie->getNrZone()+1];
		for (int i = 0; i < this->locatie->getNrZone(); i++)
		{
			nrLocuriOcupatePerZona[i] = 0;
		}
		locuriOcupate = new int[this->locatie->getNumarMaximLocuri()+1];
		
		for (int i = 0; i < this->locatie->getNumarMaximLocuri(); i++)
		{
			locuriOcupate[i] = 0;
		}
	
	}
	else {
		throw exception("Datele introduse pentru eveniment sunt invalide!");
	}
}

Eveniment::Eveniment(const Eveniment& e) {
	if (e.locatie->esteInvalida() == false && e.denumire != nullptr && MetodeUtile::contineDoarLitere(e.denumire) && MetodeUtile::valideazaData(e.data)
		&& MetodeUtile::valideazaOra(e.ora)) {
		locatie = new Locatie(*e.locatie);
		denumire = new char[strlen(e.denumire) + 1];
		strcpy_s(denumire, strlen(e.denumire) + 1, e.denumire);
		data = e.data;
		ora = e.ora;
		nrLocuriOcupatePerZona = new int[this->locatie->getNrZone() + 1];
		for (int i = 0; i < this->locatie->getNrZone(); i++)
		{
			nrLocuriOcupatePerZona[i] = e.nrLocuriOcupatePerZona[i];
		}
		locuriOcupate = new int[e.locatie->getNumarMaximLocuri() + 1];
		for (int i = 0; i < e.locatie->getNumarMaximLocuri() + 1; i++)
		{
			locuriOcupate[i] = e.locuriOcupate[i];
		}
		
	}
	else {
		this->locatie = new Locatie;
		this->denumire = nullptr;
		this->data = "";
		this->ora = "";
		this->nrLocuriOcupatePerZona = nullptr;
		this->locuriOcupate = nullptr;
		
	}
}


Eveniment::~Eveniment() {
	if (locatie != nullptr) {
		delete locatie;
	}
	if (denumire != nullptr) {
		delete[] denumire;
	}
	if (nrLocuriOcupatePerZona != nullptr) {
		delete[] nrLocuriOcupatePerZona;
	}
	if (locuriOcupate != nullptr) {
		delete[] locuriOcupate;
	}
	
}

int* Eveniment::getNrLocuriOcupatePerZona() {
	if (nrLocuriOcupatePerZona != nullptr) {
		int* copie = new int[this->locatie->getNrZone() + 1];
		for (int i = 0; i < this->locatie->getNrZone(); i++)
		{
			copie[i] = nrLocuriOcupatePerZona[i];
		}
		return copie;
	}
	return nullptr;
}

int* Eveniment::getLocuriOcupate() {
	if (locuriOcupate != nullptr) {
		int* copie = new int[this->locatie->getNumarMaximLocuri() + 1];
		for (int i = 0; i < this->locatie->getNumarMaximLocuri(); i++)
		{
			copie[i] = locuriOcupate[i];
		}
		return copie;
	}
	return nullptr;
}

Locatie Eveniment::getLocatie() {
	return *locatie;
}

char* Eveniment::getDenumire() {
	char* copie;
	if (denumire != nullptr) {
		 copie = new char[strlen(denumire) + 1];
		strcpy_s(copie, strlen(denumire) + 1, denumire);
		return copie;
	}
	copie = new char[1];
	strcpy_s(copie, 1, "");
	return copie;
}

string  Eveniment::getData() {
		return data;
}

string  Eveniment::getOra() {
		return ora;
}

void  Eveniment::setLocatie(Locatie l) {
	if(l.esteInvalida()==false){
		delete locatie;
		locatie = new Locatie(l);
		delete[]nrLocuriOcupatePerZona;
		nrLocuriOcupatePerZona = new int[locatie->getNrZone() + 1];
		for (int i = 0; i < locatie->getNrZone(); i++)
		{
			nrLocuriOcupatePerZona[i] = 0;
		}
	}
}

void  Eveniment::setDenumire(const char* denumire) {

	if(denumire!=nullptr && MetodeUtile::contineDoarLitere(denumire)){
		if (this->denumire != nullptr) {
			delete[] this->denumire;
		}
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
}

void  Eveniment::setData(string data) {
	if (MetodeUtile::valideazaData(data)) {
		this->data = data;
	}
}

void  Eveniment::setOra(string ora) {
	if (MetodeUtile::valideazaOra(ora)) {
		this->ora = ora;
	}
}



bool Eveniment::esteInvalid() {
	if (locatie->esteInvalida() == false && denumire != nullptr && MetodeUtile::contineDoarLitere(denumire) &&
		MetodeUtile::valideazaData(data) && MetodeUtile::valideazaOra(ora)) {
		return false;
	}
	return true;
}

bool Eveniment::verificareEvenimentIncheiat() {
	if(data!="" && MetodeUtile::verificareDataEsteInViitor(data)==false){
		return true;
	}
	return false;
}

//verificare ca locul se afla printre  locurile alocate zonei respective(fiecare zona are alocate locuri in ordinea in care se 
// afla in cei doi vectori: Ex. pt 2 zone A,B cu 10 locuri fiecare,locurile de la 1 la 10 sunt alocate zonei A si de la 11 la 20 zonei B)
bool Eveniment::contineLocInZona(int loc, string tipBilet) {

	if (loc <= 0 || loc > locatie->getNumarMaximLocuri()) {
		return false;
	}
	if (contineZona(tipBilet) && locatie->esteInvalida()==false) {
		int pozitieZona,limitaInf = 0,limitaSup = 0;
		pozitieZona = getIndexPentruZona(tipBilet);

		if (nrLocuriOcupatePerZona[pozitieZona] < locatie->getNrLocuriPerZona()[pozitieZona]) {
			for (int i = 0; i < pozitieZona + 1; i++)
			{
				limitaSup += locatie->getNrLocuriPerZona()[i];
			}

			if (pozitieZona == 0)
			{
			
				if (loc <= limitaSup) {
					return true;
				}
			}
			else {
				limitaInf = limitaSup - locatie->getNrLocuriPerZona()[pozitieZona];
				if (loc <= limitaSup && loc > limitaInf) {
					return true;
				}
			}
			return false;
		}
		return false;
	}
	return false;
}

//validare ca locul pentru care vreau sa creez bilet nu a mai fost deja dat
bool Eveniment::validareLocDuplicat(int loc) {
	for (int i = 0; i < locatie->getNumarMaximLocuri(); i++)
	{
		if (locuriOcupate[i] == loc) {
			return false;
		}
	}
	return true;
}

//metoda prin care returnez pozitia unei anumite zone din vectorul de zone
int Eveniment::getIndexPentruZona(string tipBilet) {
	int pozitieZona = -1;
	for (int i = 0; i < locatie->getNrZone(); i++)
	{
		if (tipBilet == locatie->getZone()[i]) {
			pozitieZona = i;
		}
	}
	return pozitieZona;
}

//metode prin care salvez locul creat in bilet
void Eveniment::adaugaLoc(int loc , string tipBilet) {
	locuriOcupate[loc - 1] = loc;
	int pozitieZona = getIndexPentruZona(tipBilet);
	nrLocuriOcupatePerZona[pozitieZona]++;
	
}

void Eveniment::stergeLoc(int loc, string tipBilet) {
	locuriOcupate[loc - 1] = 0;
	int pozitieZona = getIndexPentruZona(tipBilet);
	nrLocuriOcupatePerZona[pozitieZona]--;

}

//Verificare ca zona introdusa ca parametru se afla in vectorul de zone
bool Eveniment::contineZona(string zona) {
	if (locatie->esteInvalida() == false) {
		for (int i = 0; i < locatie->getNrZone(); i++)
		{
			if (zona == locatie->getZone()[i]) {
				return true;
			}

		}
	}
	return false;
}

Eveniment& Eveniment::operator=( Eveniment& e) {
	
	if (e.esteInvalid()==false) {
		if (locatie != nullptr) {
			delete locatie;
		}
		if (denumire != nullptr) {
			delete[] denumire;
		}
		if (nrLocuriOcupatePerZona != nullptr) {
			delete[] nrLocuriOcupatePerZona;
		}
		if (locuriOcupate != nullptr) {
			delete[] locuriOcupate;
		}
		locatie = new Locatie(*e.locatie);
		denumire = new char[strlen(e.denumire) + 1];
		strcpy_s(denumire, strlen(e.denumire) + 1, e.denumire);
		data = e.data;
		ora = e.ora;
		nrLocuriOcupatePerZona = new int[e.locatie->getNrZone()+1];
		for (int i = 0; i < e.locatie->getNrZone(); i++)
		{
			nrLocuriOcupatePerZona[i] = e.nrLocuriOcupatePerZona[i];
		}
		locuriOcupate = new int[e.locatie->getNumarMaximLocuri() + 1];
		for (int i = 0; i < e.locatie->getNumarMaximLocuri() + 1; i++)
		{
			locuriOcupate[i] = e.locuriOcupate[i];
		}

	}
	
	return *this;
}

 Eveniment::operator char* () {
	 if (denumire != nullptr) {
		 return denumire;
	 }
	 char* copie = new char[1];
	 strcpy_s(copie, 1, "");
	 return copie;
}

bool  Eveniment::operator<(Eveniment e) {
	if (data != "" && e.data != "") {
		return MetodeUtile::verificarePrimaDataEsteInainte(data, e.data);
	}
	return false;
	
 }

ostream& operator<<(ostream& out, Eveniment e) {
	 
	out << endl;
	out << "Locatia evenimentului:" << endl;
	out << "-------------------------" << endl;	
	out << *e.locatie;
	out << "-------------------------" << endl;
	if(e.denumire!=nullptr){
		out << "Denumirea evenimentului: " << e.denumire << endl;
	}
	if (e.nrLocuriOcupatePerZona != nullptr) {
		out << "Numarul de locuri ocupate pentru fiecare zona: " << endl;
		for (int i = 0; i < e.locatie->getNrZone(); i++)
		{
			out << "Zona " << (i + 1) << ": " << e.nrLocuriOcupatePerZona[i] << endl;
		}
	}

	out << "Data evenimentului: " << e.data << endl;
	out << "Ora evenimentului: " << e.ora << endl;
	
	return out;
 }

istream& operator>>(istream& in, Eveniment& e) {
	in >> *e.locatie;

	bool valid = false;
	while(valid==false){
		string den;
		cout << "Denumirea evenimentului(un singur cuvant): ";
		in >> den;
		if (MetodeUtile::contineDoarLitere(den)) {
			delete[] e.denumire;
			e.denumire = new char[den.length() + 1];
			strcpy_s(e.denumire, den.length() + 1, den.c_str());
			valid = true;
		}
		else {
			cout << "Denumirea introdusa nu  contine doar litere" << endl;
		}
	}

	valid = false;
	while (valid == false) {
		string data;
		cout << "Data evenimentului(format dd.mm.yyyy): ";
		in >> data;
		if (MetodeUtile::valideazaData(data)) {
			e.data = data;
			valid = true;
		}
		
	}

	valid = false;
	while (valid == false) {
		string ora;
		cout << "Ora evenimentului(format hh:mm): ";
		in >> ora;
		if (MetodeUtile::valideazaOra(ora)) {
			e.ora = ora;
			valid = true;
		}
	
	}
	for (int i = 0; i < e.locatie->getNrZone(); i++)
	{
		e.nrLocuriOcupatePerZona[i] = 0;
	}
	return in;
 }

