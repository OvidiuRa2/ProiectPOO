#include "Meniu.h"
#include"PrelucrareFisierText.h"
#include"PrelucrareFisierBinar.h"
#include"MetodeUtile.h"
#include<string>
#include<iostream>
#include<fstream>
#include<cstdio>


using namespace std;

list<string>* Meniu::fisiereSalvate = new list<string>();
//salvare valid si refacere date fisier text
Meniu::Meniu() {
	restaureazaDate();
	cout << "\t\t\t\t\t--------- The Ticketing App ---------"<<endl;
	bool raspunsValid = false;
	while (raspunsValid == false) {
		cout << "Doriti sa cititi din fisier sau sa folositi meniul?(fisier/meniu)" << endl;
		string data;
		cin >> data;
		if (data == "fisier") {
			raspunsValid = true;
			citesteDinFisier();
			afisareMeniuPrincipal();
		}
		if (data == "meniu") {
			raspunsValid = true;
			afisareMeniuPrincipal();
		}
	}
	salveazaBilete();
}

void Meniu::afisareMeniuPrincipal() {

	cout << "Ce doresti sa faci in continuare: (1/2/3/4)" << endl;
	cout << "1) Prelucrare Locatii."<<endl;
	cout << "2) Prelucrare Evenimente." << endl;
	cout << "3) Prelucrare Bilete." << endl;
	cout << "4) Iesire." << endl;
	string data;
	cin >> data;
	if (data == "1") {
		prelucrareLocatii();
	}
	else if (data == "2") {
		prelucrareEvenimente();
	}
	else if (data == "3") {
		prelucrareBilete();
	}
	else if (data == "4") {
		iesire();
	}
	else {
		afisareMeniuPrincipal();
	}
	
}

void Meniu::prelucrareLocatii(){
	cout << "--Prelucrare Locatii--" << endl;
	cout << "1) Locatie Noua." << endl;
	cout << "2) Numar de locuri neutilizate." << endl;
	cout << "3) Locatia cu cea mai mare capacitate." << endl;
	cout << "4) Afiseaza o locatie." << endl;
	cout << "5) Afiseaza toate locatiile existente." << endl;
	cout << "Ce prelucrare alegi: (1/2/3/4/5)" << endl;
	string data;
	cin >> data;
	if (data == "1") {
		citesteLocatie();
	}
	else if (data == "2") {
		string locatie;
		selecteazaLocatieCreata(locatie);
		if (locatie != "") {
			Locatie loc = Locatie::contineLocatia(locatie);
			cout << "Numarul de locuri neutilizate pentru " << loc.getDenumire() << " este: " << loc.numarLocuriNeutilizate() << endl;
		}
	}
	else if (data == "3") {
		string locatieMaxima = Locatie::ceaMaiMareCapacitate(Locatie::getLocatiiCreate());
		if (locatieMaxima == "") {
			cout << "Nu exista locatii create."<<endl;
		}
		else {
			Locatie locatie = Locatie::contineLocatia(locatieMaxima);
			cout << "Cea mai mare capacitate se afla in locatia " << locatie.getDenumire() << " si este de " << locatie.getNumarMaximLocuri()<<"." << endl;
		}
	}
	else if (data == "4") {
		string locatie;
		selecteazaLocatieCreata(locatie);
		if (locatie != "") {
			cout << Locatie::contineLocatia(locatie) << endl;
		}
		
	}
	else if (data == "5") {
		Locatie::afiseazaLocatiiCreate();
	}
	
		afisareMeniuPrincipal();

}

void Meniu::prelucrareEvenimente() {
	cout << "--Prelucrare Evenimente--" << endl;
	cout << "1) Eveniment Nou." << endl;
	cout << "2) Numar de locuri libere pentru fiecare zona." << endl;
	cout << "3) Compara doua evenimente." << endl;
	cout << "4) Afiseaza un eveniment." << endl;
	cout << "5) Afiseaza evenimentele create." << endl;

	cout << "Ce prelucrare alegi: (1/2/3/4/5)" << endl;
	string data;
	cin >> data;
	if (data == "1") {
		citesteEveniment();
	}
	else if (data == "2") {
		string eveniment;
		selecteazaEvenimentCreat(eveniment);
		if (eveniment != "") {
			Eveniment ev = Eveniment::contineEveniment(eveniment);
			Locatie l = ev.getLocatie();
			for (int i = 0; i < ev.getLocatie().getNrZone(); i++)
			{
				cout << l.getZone()[i] << ": " << l.getNrLocuriPerZona()[i] - ev.getNrLocuriOcupatePerZona()[i]<<endl;
			}
		}
	}
	else if (data == "3") {
		string eveniment1, eveniment2;
		cout << "Selecteaza primul eveniment: " << endl;
		selecteazaEvenimentCreat(eveniment1);
		cout << "Selecteaza al doilea eveniment: " << endl;
		selecteazaEvenimentCreat(eveniment2);
		if (eveniment1 != "" && eveniment2 != "") {
			Eveniment e1 = Eveniment::contineEveniment(eveniment1);
			Eveniment e2 = Eveniment::contineEveniment(eveniment2);
			if (e1 == e2) {
				cout << "Cele doua evenimente selectate coincid." << endl;
			}
			else if (e1 < e2) {
				cout << e1.getDenumire() << " se afla inaintea evenimentului " << e2.getDenumire()<<endl;
			}
			else {
				cout << e2.getDenumire() << " se afla inaintea evenimentului " << e1.getDenumire()<<endl;

			}
		}
	}
	else if (data == "4") {
		string ev;
		selecteazaEvenimentCreat(ev);
		if (ev != "") {
			cout << Eveniment::contineEveniment(ev)<<endl;
		}
	}
	else if (data == "5") {
		Eveniment::afiseazaEvenimenteCreate();
	}

	afisareMeniuPrincipal();
}

void Meniu::prelucrareBilete() {
	cout << "--Prelucrare Bilete--" << endl;
	cout << "1) Bilet Nou." << endl;
	cout << "2) Valideaza un bilet." << endl;
	cout << "3) Compara doua bilete." << endl;
	cout << "4) Afiseaza un bilet." << endl;
	cout << "5) Afiseaza biletele existente." << endl;

	cout << "Ce prelucrare alegi: (1/2/3/4/5)" << endl;
	string data;
	cin >> data;
	if (data == "1") {
		citesteBilet();
	}
	else if (data == "2") {
		int bilet;
		selecteazaBiletCreat(bilet);
		if (bilet > 0) {
			Bilet::valideazaBiletulSpecificat(bilet);
		}
	}
	else if (data == "3") {
		int bilet1, bilet2;
		cout << "Selecteaza primul bilet: " << endl;
		selecteazaBiletCreat(bilet1);
		cout << "Selecteaza al doilea bilet: " << endl;
		selecteazaBiletCreat(bilet2);
		if (bilet1 > 0 && bilet2 > 0){
			Bilet b1 = Bilet::contineBilet(bilet1);
			Bilet b2 = Bilet::contineBilet(bilet2);
		
			if (strcmp(b1.getEveniment().getDenumire(),b2.getEveniment().getDenumire())==0) {
				if (b1.getLoc() == b2.getLoc()) {
					cout << "Biletele selectate coincid."<<endl;
				}
				else if (b1 >= b2) {
					cout << "Biletul cu locul " << b1.getLoc() << " se afla dupa biletul cu locul " << b2.getLoc() <<". (Eveniment:"<< b1.getEveniment().getDenumire() << ")" << endl;
				}
				else {
					cout << "Biletul cu locul " << b2.getLoc() << " se afla dupa biletul cu locul " << b1.getLoc() << ". (Eveniment:" << b1.getEveniment().getDenumire() << ")" << endl;
				}
			}
			else {
				cout<<"Bilete selectate nu se afla in acelasi eveniment."<<endl;
			}
		}
	}
	else if (data == "4") {
		int bilet1;
		selecteazaBiletCreat(bilet1);
		if (bilet1 > 0) {
			cout << Bilet::contineBilet(bilet1)<<endl;
		}
	}
	else if (data == "5") {
		Bilet::afiseazaBileteCreate();
	}

	afisareMeniuPrincipal();
}

void Meniu::iesire() {
	cout << "Sigur doresti sa iesi ?(Da/Nu)" << endl;
	string raspuns;
	cin >> raspuns;
	if (MetodeUtile::toLowerCase(raspuns) == "nu") {
		afisareMeniuPrincipal();	
	}else if(MetodeUtile::toLowerCase(raspuns) == "da"){
	}
	else {
		afisareMeniuPrincipal();
	}
}

Locatie Meniu::citesteLocatie() {
	cout << "Numar maxim de locuri: ";
	int numarMaximLocuri=0;
	bool valid = false;
	string nr;
	cin >> nr;
	if (MetodeUtile::contineDoarCifre(nr)) {
		numarMaximLocuri = stoi(nr);
		string den;
		while (valid == false) {
			cout << "Denumire:";
			cin >> ws;
			getline(cin,den);
			list<Locatie>::iterator it;
			list<Locatie> locatii = Locatie::getLocatiiCreate();
			for (it = locatii.begin(); it != locatii.end(); ++it) {
				if (den == it->getDenumire()) {
					den = "";
					cout << "Denumirea introdusa este deja utilizata." << endl;
				}
			}
			if (den != "") {
				if (MetodeUtile::contineDoarLitere(den)) {
					valid = true;
				}
				else {
					cout << "Denumirea introdusa nu contine doar litere." << endl;
				}
			}
		}

		valid = false;
		string nr;
		while (valid == false) {
			cout << "Numar de zone: ";
			cin >> nr;
			if ( MetodeUtile::contineDoarCifre(nr) && stoi(nr) > 0) {
				valid = true;
			} else{
				cout << "Numarul de zone introdus este invalid." << endl;
			}
		}
		int nrZone = stoi(nr);
			cout << "Zone: " << endl;
			string zona;
			string* zone = new string[nrZone];
			for (int i = 0; i < nrZone; i++)
			{
				cout << "Zona " << (i + 1) << ": ";
				cin >> ws;
				getline(cin, zona);
				if (zona != "") {
					zone[i] = zona;
				}
				else {
					cout << "Zona introdusa este invalida!" << endl;
					i--;
				}
			}

			string nrLocuriZona;
			int* nrLocuriPerZona = new int[nrZone];
			int sumaNrLocuri = 0;

			for (int i = 0; i < nrZone; i++)
			{
				cout << "Numar de locuri pentru zona " << (i + 1) << ": ";
				cin >> nrLocuriZona;
				if (MetodeUtile::contineDoarCifre(nrLocuriZona)) {
					sumaNrLocuri += stoi(nrLocuriZona);
					if (sumaNrLocuri <= numarMaximLocuri) {

						nrLocuriPerZona[i] = stoi(nrLocuriZona);
					}
					else {
						cout << "Numar de locuri nu poate sa depaseasca numarul maxim alocat!(maxim " << numarMaximLocuri << ")" << endl;
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

			float* preturiPerZona = new float[nrZone];
			for (int i = 0; i < nrZone; i++)
			{
				cout << "Pretul pentru zona " << (i + 1) << ": ";
				cin >> pret;
				if (MetodeUtile::contineDoarCifre(pret) && stoi(pret) >= 0) {
					preturiPerZona[i] = stoi(pret);
				}
				else {
					cout << "Pretul introdus pentru aceasta zona este invalid!" << endl;
					i--;
				}
			}
			Locatie l(numarMaximLocuri, zone, nrLocuriPerZona, nrZone, preturiPerZona, den);
			PrelucrareFisierBinar p;
			p.scrie(l);
			return l;
		
	}
	else {
		cout<<"Numarul maxim introdus este invalid"<<endl;
		afisareMeniuPrincipal();
	}
}

Eveniment Meniu::citesteEveniment() {
	cout << "Cum doresti sa creezi acest eveniment:" << endl;
	cout << "1) Foloseste o locatie deja existenta." << endl;
	cout << "2) Creaza o noua locatie." << endl;
	string selectie;
	cin >> selectie;
	if (selectie == "1" || selectie == "2") {
		if (selectie == "1") {
			string locatie;
			selecteazaLocatieCreata(locatie);
			Locatie locatieAleasa = Locatie::contineLocatia(locatie);
			string den, data, ora;
			citireDateEveniment(den, data, ora);
			Eveniment e(locatieAleasa, den.c_str(), data, ora);
			PrelucrareFisierBinar p;
			p.scrie(e);
			return e ;
		}
		else if (selectie == "2") {
			Locatie locatieAleasa = citesteLocatie();
			string den, data, ora;
			citireDateEveniment(den, data, ora);
			Eveniment e(locatieAleasa, den.c_str(), data, ora);
			PrelucrareFisierBinar p;
			p.scrie(e);
			return e;
		}

	}
	
	
}

void Meniu::citesteBilet() {
	cout << "Cum doresti sa creezi acest bilet:" << endl;
	cout << "1) Foloseste un eveniment deja existent." << endl;
	cout << "2) Creaza un nou eveniment." << endl;
	string data;
	cin >> data;
	if (data == "1" || data == "2") {
		if (data == "1") {
			string eveniment, tipBilet;
			int loc;
			selecteazaEvenimentCreat(eveniment);
			Eveniment evenimentAles = Eveniment::contineEveniment(eveniment);
			cout << evenimentAles;
			citireDateBilet(tipBilet, loc, evenimentAles);
			Bilet b(tipBilet, loc, Eveniment::contineEveniment(eveniment),Bilet::genereazaIdRandom());

		}
		else if (data == "2") {
			Eveniment evenimentAles = citesteEveniment();
			string tipBilet;
			int loc;
			cout << evenimentAles;
			citireDateBilet(tipBilet, loc, evenimentAles);
			Bilet b(tipBilet, loc, Eveniment::contineEveniment(evenimentAles.getDenumire()),Bilet::genereazaIdRandom());
			
		}
	}
}

void Meniu::selecteazaLocatieCreata(string& locatie) {

	list<Locatie>::iterator it;
	list<Locatie> locatii = Locatie::getLocatiiCreate();
	
	if (locatii.size()>0) {
		cout << "Locatii posibile: ";
		for (it = locatii.begin(); it != locatii.end(); ++it)
		{
			if (it != locatii.begin()) {
				cout << ", ";
			}
			cout << it->getDenumire();
		}
		cout << ".";
		bool valid = false;

		while (valid == false) {
			cout << endl << "Ce locatie doresti sa folosesti: " << endl;
			cin >> ws;
			getline(cin,locatie);
			if (Locatie::contineLocatia(locatie, true)) {
				valid = true;
			}
			else {
				cout << "Locatia introdusa este invalida." << endl;
			}
		}
	}
	else {
		locatie = "";
		cout << "Nu exista locatii create."<<endl;
		afisareMeniuPrincipal();
	}
}

void Meniu::selecteazaEvenimentCreat(string& eveniment) {

	list<Eveniment>::iterator it;
	list<Eveniment> evenimente = Eveniment::getEvenimenteCreate();
	if (evenimente.size() > 0) {
		cout << "Evenimente posibile: ";
		for (it = evenimente.begin(); it != evenimente.end(); ++it)
		{
			if (it != evenimente.begin()) {
				cout << ", ";
			}
			cout << it->getDenumire();
		}
		cout << ".";
		bool valid = false;

		while (valid == false) {
			cout << endl << "Ce eveniment doresti sa folosesti: " << endl;
			cin >> ws;
			getline(cin,eveniment);
			if (Eveniment::contineEveniment(eveniment, true)) {
				valid = true;
			}
			else {
				cout << "Evenimentul introdus este invalid.";
			}

		}
	}else {
		eveniment = "";
		cout << "Nu exista evenimente deja create." << endl;
		afisareMeniuPrincipal();
	}

}

void Meniu::selecteazaBiletCreat(int& bilet) {
	vector<Bilet>::iterator it;
	vector<Bilet> bilete = Bilet::getBileteCreate();
	if (bilete.size() > 0) {
		cout << "Bilete posibile: ";
		for (it = bilete.begin(); it != bilete.end(); ++it)
		{
			if (it != bilete.begin()) {
				cout << ", ";
			}
			cout << it->getIdBilet();
		}
		cout << ".";
		bool valid = false;

		string b;
		while (valid == false) {
			cout << endl << "Ce bilet doresti sa folosesti: " << endl;
			cin >> ws;
			getline(cin, b);
				
				if ((MetodeUtile::contineDoarCifre(b) && Bilet::contineBilet(stoi(b), true))) {
					valid = true;
					bilet = stoi(b);

				}
				else {
					cout << "Biletul introdus este invalid.";
				}
		}
	}
	else {
		bilet = -1;
		cout << "Nu exista bilete deja create." << endl;
		afisareMeniuPrincipal();
	}
}

void Meniu::citireDateEveniment(string &den, string &data, string &ora) {
	bool valid = false;
	while (valid == false) {

		cout << "Denumirea evenimentului: ";
		cin >> ws;
		getline(cin, den);
		
		list<Eveniment> evenimente = Eveniment::getEvenimenteCreate();
		list<Eveniment>::iterator it;

		for (it = evenimente.begin(); it != evenimente.end(); ++it) {
			if (den == it->getDenumire()) {
				den = "";
				cout << "Denumirea introdusa este deja utilizata." << endl;
			}
		}

		if (den != "") {
			if (MetodeUtile::contineDoarLitere(den)) {

				char* denumire = new char[den.length() + 1];
				strcpy_s(denumire, den.length() + 1, den.c_str());
				valid = true;
			}
			else {
				cout << "Denumirea introdusa nu  contine doar litere" << endl;
			}
		}
	}

	valid = false;
	while (valid == false) {

		cout << "Data evenimentului(format dd.mm.yyyy): ";
		cin >> data;
		if (MetodeUtile::valideazaData(data)) {
			valid = true;
		}

	}

	valid = false;

	while (valid == false) {

		cout << "Ora evenimentului(format hh:mm): ";
		cin >> ora;
		if (MetodeUtile::valideazaOra(ora)) {
			valid = true;
		}

	}
}

void Meniu::citireDateBilet(string& tipBilet, int& loc,Eveniment e) {
	bool valid = false;
	while (valid == false) {
		cout << "Tipul biletului(Zona): ";
		cin >> ws;
		getline(cin,tipBilet);
		int indexZona = e.getIndexPentruZona(tipBilet);
		if (e.contineZona(tipBilet)) {
			if (e.getNrLocuriOcupatePerZona()[indexZona] < e.getLocatie().getNrLocuriPerZona()[indexZona]) {

				valid = true;
			}
			else {
				cout << "Zona introdusa este ocupata." << endl;
			}
		}
		else {
			cout << "Tipul introdus este invalid." << endl;
		}
		
	}
	
	valid = false;
	string l;
	while (valid == false) {
		cout << "Locul: ";
		cin >> ws;
		getline(cin, l);
		if (MetodeUtile::contineDoarCifre(l)) {
			loc = stoi(l);
			if (e.contineLocInZona(loc, tipBilet) && e.validareLocDuplicat(loc)) {
				valid = true;
			}
			else {
				cout << "Locul introdus este invalid." << endl;
			}
		}
		else {
			cout << "Locul introdus este invalid." << endl;
		}
	}
}

void Meniu::salveazaBilete() {
	
		remove("Bilete.bin"); 
		vector<Bilet>::iterator it;
		vector<Bilet> bilete = Bilet::getBileteCreate();
		PrelucrareFisierBinar p;
		for (it = bilete.begin(); it != bilete.end(); ++it)
		{
			p.scrie(*it);
		}
	
}

void Meniu::citesteDinFisier() {
	PrelucrareFisierText p;

	try {
		string numeFisier;
		cout << "Introduceti numele fisierului:";
		cin >> numeFisier;
		ifstream f(numeFisier);
		if (  MetodeUtile::valideazaTipFisier(numeFisier) && contineFisier(numeFisier) == false && f.is_open()) {
			PrelucrareFisierBinar::scrieNumeFisier(numeFisier);
			p.citeste(numeFisier);
			Locatie::afiseazaLocatiiCreate();
			Eveniment::afiseazaEvenimenteCreate();
			Bilet::afiseazaBileteCreate();
		}

	}
	catch (exception e) {
		cout << e.what();
	}
}

bool Meniu::contineFisier(string numeFisier){
	list<string>::iterator it;
	for (it = fisiereSalvate->begin(); it != fisiereSalvate->end(); ++it)
	{
		if (*it == numeFisier) {
			return true;
		}
	}
	return false;
}

 void Meniu::adaugaNumeFisier(string numeFisier) {
	 fisiereSalvate->push_back(numeFisier);
 }

void Meniu::restaureazaDate() {
	PrelucrareFisierBinar p;
	p.citeste();
	p.citesteNumeFisier();
}