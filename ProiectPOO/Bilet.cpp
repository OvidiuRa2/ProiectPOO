	#include"Bilet.h"
	#include"MetodeUtile.h"
#include"Eveniment.h"
	#include<vector>
	#include<iterator>
	#include<string>
	using namespace std;

	int Bilet::nrBilete = 0;
	vector<Bilet>* Bilet::bileteCreate = new vector<Bilet>();

	Bilet::Bilet() :idBilet(-1) {
		tipBilet = "";
		loc = 0;
		nrBilete++;
		validat = false;
		pret = 0;
		eveniment = new Eveniment;
		bileteCreate->push_back(*this);
	}

	Bilet::Bilet(string tipBilet, int loc, Eveniment& e,int id ) :idBilet(id) {
		if (e.esteInvalid() == false && e.contineZona(tipBilet) && e.contineLocInZona(loc,tipBilet) && e.validareLocDuplicat(loc))
		{
			nrBilete++;
			this->tipBilet = tipBilet;
			this->loc = loc;
			e.adaugaLoc(loc, tipBilet);
			eveniment = &e;
			validat = false;
			pret = e.getLocatie().getPreturiPerZona()[e.getIndexPentruZona(tipBilet)];
			bileteCreate->push_back(*this);
		}
		else {
			throw exception("Datele introduse pentru bilet sunt invalide!");
		}
	}

	Bilet::Bilet(const Bilet& b) :idBilet(b.idBilet) {
		if (b.eveniment->esteInvalid() == false && b.tipBilet!="" && b.loc>0 && b.pret>0) {
			
			tipBilet = b.tipBilet;
			loc = b.loc;
			eveniment = b.eveniment;
			validat = b.validat;
			pret = b.eveniment->getLocatie().getPreturiPerZona()[b.eveniment->getIndexPentruZona(tipBilet)];

		}
		else {
			tipBilet = "";
			loc = 0;
			nrBilete++;
			validat = false;
			pret = 0;
			eveniment = new Eveniment;
		}

	}

	vector<Bilet> Bilet::getBileteCreate() {
		return *bileteCreate;
	}

	int Bilet::getPret() {
		return pret;
	}

	int Bilet::getNrBilete() {
		return nrBilete;
	}

	int Bilet::getIdBilet() {
		return idBilet;
	}

	bool Bilet::getValidat() {
		return validat;
	}

	string Bilet::getTipBilet() {
		return tipBilet;
	}

	int Bilet::getLoc() {
		return loc;
	}

	Eveniment Bilet :: getEveniment() {
		return *eveniment;
	}


	void Bilet::setLoc(int l,string tip){
		if (eveniment->contineZona(tip) &&  eveniment->contineLocInZona(l, tip) && eveniment->validareLocDuplicat(l)) {
			eveniment->stergeLoc(loc, tipBilet);
			eveniment->adaugaLoc(l, tip);
			loc = l;
			tipBilet = tip;
		}
	}

	void Bilet::setEveniment(Eveniment& e) {
		if (e.esteInvalid() == false &&	e.contineZona(tipBilet) && e.contineLocInZona(loc,tipBilet)) {
			pret = e.getLocatie().getPreturiPerZona()[e.getIndexPentruZona(tipBilet)];
			eveniment = &e;
		}
	}

	int Bilet::genereazaIdRandom() {
		srand(time(0));
		return (1+rand() % 1000)*(nrBilete+1);

	}

	void Bilet::valideaza() {
		if (validat == false)
		{
			if (esteInvalid() == false) {
				validat = true;
			}
			else {
				cout << "Biletul contine date invalide!" << endl;
			}
		}
		else {
			cout<<"Biletul a fost deja validat!"<<endl;
		}
	}

	void Bilet::valideazaBiletulSpecificat(int bilet) {
	
		for (int i = 0; i < bileteCreate->size(); i++)
		{
			if (bileteCreate->at(i).getIdBilet() == bilet) {
				bileteCreate->at(i).valideaza();
			}
		}
	}

	void Bilet::valideazaUltimulElement(){
		bileteCreate->at(bileteCreate->size() - 1).valideaza();
	}


	void Bilet::afiseazaBileteCreate() {
		vector<Bilet>::iterator it;
		for (it = bileteCreate->begin(); it != bileteCreate->end(); ++it)
			cout << *it << endl;
	}

	bool Bilet::esteInvalid() {
		if (eveniment->esteInvalid() == false && tipBilet != "" && loc>0 && pret>0) {
			return false;
		}
		return true;
	}

	Bilet& Bilet::contineBilet(int idBilet) {
		vector<Bilet>::iterator it;
		for (it = bileteCreate->begin(); it != bileteCreate->end(); ++it)
		{
			if (it->getIdBilet() == idBilet) {
				return *it;
			}
		}
		throw  exception("Biletul introdus nu exista");
	}

	bool Bilet::contineBilet(int idBilet, bool) {
		vector<Bilet>::iterator it;
		for (it = bileteCreate->begin(); it != bileteCreate->end(); ++it)
		{
			if (it->getIdBilet() == idBilet) {
				return true;
			}
		}
		return false;
	}


	bool Bilet::operator!() {
		if (validat == false) {
			return true;
		}
		return false;
	}

	Bilet& Bilet::operator=(const Bilet& b) {

		tipBilet = b.tipBilet;
		loc = b.loc;
		eveniment = b.eveniment;
		validat = false;
		pret = b.eveniment->getLocatie().getPreturiPerZona()[b.eveniment->getIndexPentruZona(tipBilet)];

		return *this;
	}

	bool Bilet::operator>=(Bilet b) {
		if (loc >= b.loc) {
			return true;
		}
		return false;
	}

	istream& operator>>(istream& in, Bilet& b) { 
		in >> *b.eveniment;
		bool valid = false;
		while (valid == false) {
			string tip;
			cout << "Introduceti tipul biletului: ";
			in >> ws;
			getline(in, tip);	
			if (b.eveniment->contineZona(tip)) {
				valid = true;
				b.tipBilet = tip;
			}
			else {
				cout << "Zona introdusa este invalida!"<<endl;
			}

		}
		valid = false;
		while (valid == false) {
			string loc;
			cout << "Introduceti locul biletului: ";
			in >> loc;
			if (MetodeUtile::contineDoarCifre(loc) && b.eveniment->contineLocInZona(stoi(loc), b.tipBilet) &&
				b.eveniment->validareLocDuplicat(stoi(loc))) {
				b.loc = stoi(loc);
				valid = true;
			}
			else {
				cout << "Locul introdus este invalid sau nu se afla in zona introdusa anterior!" << endl;
			}
		}
		b.pret = b.getEveniment().getLocatie().getPreturiPerZona()[b.getEveniment().getIndexPentruZona(b.tipBilet)];
		
		return in;
	}
	
	ostream& operator<<(ostream& out, Bilet b) {
		out << endl;
		out << "Numar total de bilete create: " << b.nrBilete<<endl;
		out << "ID bilet: " << b.idBilet<<endl;
		out << "Tipul biletului: "<<b.tipBilet<<endl;
		out << "Locul biletului: " << b.loc<<endl;
		out << "--Detalii eveniment--" << endl;
		out << "Denumire: " << b.eveniment->getDenumire() << endl;
		out << "Data: " << b.eveniment->getData() << endl;
		out << "Ora: " << b.eveniment->getOra() << endl;
		out << endl;
		return out;
	}