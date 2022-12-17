#include <iostream>
using namespace std;
#include "Locatie.h"
#include"MetodeUtile.h"
#include"Eveniment.h"
#include"Bilet.h"

int main() {
	string zone[] = { "loja1","loja2" };
	int nrLocuriPerZona[] = { 10,20 };
	float preturi[] = { 60,30 };

	string zone1[] = { "A","B","C"};
	int nrLocuriPerZona1[] = { 2,10,10 };
	float preturi1[] = {20,50,80};
	
	try {
		cout << "------------Apelare Metode Locatie------------"<<endl;
		Locatie l;
		Locatie l1(100, zone, nrLocuriPerZona, 2, preturi);
		Locatie l2(150,zone1,nrLocuriPerZona1,3,preturi1);
		l1 = l2;
		cout << "Operator= " << endl<< l1 << endl;
		cout <<"Operator []: "<< l1[1] << endl;
		l1--;
		--l1;
		cout <<"Operator --"<<endl<< l1 << endl;
		cout << "--Getteri--"<<endl;
		cout <<"Numar maxim: "<< l2.getNumarMaximLocuri() << endl;
		cout << "Zone: ";
		for (int i = 0; i < l2.getNrZone(); i++)
		{
			cout << l2.getZone()[i] << " ";
		}

		cout << endl;
		cout << "Locuri pentru fiecare zona: ";
		for (int i = 0; i < l2.getNrZone(); i++)
		{
			cout << l2.getNrLocuriPerZona()[i] << " ";
		}

		cout << endl;
		cout << "Preturi pentru fiecare zona: ";
		for (int i = 0; i < l2.getNrZone(); i++)
		{
			cout << l2.getPreturiPerZona()[i] << " ";
		}
		cout << endl<<endl;

		cout << "--Setter de zone/preturi/locuri--" << endl;
		l2.setZone(zone, nrLocuriPerZona, 2, preturi);
		cout << l2<<endl;

		cout << "Locuri neutilizate: " << l2.numarLocuriNeutilizate()<<endl;
		cout << "Locuri utilizate: " << l2.sumaLocuriUtilizate() << endl;
		
		Locatie locatii[] = { l,l1,l2 };
		cout <<  Locatie::ceaMaiMareCapacitate(locatii, 3)<<endl;
		
		cout << "--Operator citire/afisare--" << endl;
		cin >> l2;
		cout << l2;
		cout << "---------------------------------------------"<<endl;
	
		cout << "------------Apelare Metode Eveniment------------" << endl;
		Eveniment e;		
		Eveniment e1(l2, "Ovidiu", "12.06.2023", "21:00");
		Eveniment e2 = e1;
		Eveniment e3(l1, "Gabriel", "10.10.2023", "12:00");

		cout << "--Getteri--" << endl;
		cout << "Numar locuri ocupate pentru fiecare zona: ";
		for (int i = 0; i < e1.getLocatie().getNrZone(); i++)
		{
			cout << e1.getNrLocuriOcupatePerZona()[i] << " ";
		}
		cout << endl;
		cout << "Denumire: " << e1.getDenumire()<<endl;
		cout << "Data: " << e1.getData() << endl;
		cout << "Ora: " << e1.getOra() << endl;
		cout << endl;

		cout << "--Setteri--" << endl;
		e1.setLocatie(l1);
		e1.setDenumire("EvenimentulMeu");
		e1.setData("23.10.2023");
		e1.setOra("13:00");
		cout << e1 << endl;

		cout << "Verificare daca evenimetul a avut loc: " << e1.verificareEvenimentIncheiat()<<endl;

		e = e2;
		cout <<"Operatorul ="<<endl<< e << endl;
		cout << "Operator char*(): " << (char*)e1<<endl;
		cout << "Operator <: " << e3.operator<(e1)<<endl;

		cout << "--Operator citire/afisare--" << endl;
		cin >> e3;
		cout << e3;
		cout << "---------------------------------------------" << endl;

		cout << "------------Apelare Metode Bilet------------" << endl;
		Bilet b;
		Bilet b1("A", 1, e1);
	//	Bilet b3("A", 3, e1); - nu se mai poate crea pt ca depaseste numarul de locuri alocate zonei A
		Bilet b4("B", 3, e1);
		Bilet b5(b4);
		cout << b1;
	
		cout << "--Getteri--" << endl;
		cout << "Pret: " << b1.getPret()<<endl;
		cout << "Numar de bilete create: " << b1.getNrBilete()<<endl;
		cout << "Id-ul biletului: " << b1.getIdBilet()<<endl;
		cout << "Daca biletul este validat: " << b1.getValidat() << endl;
		cout << "Tipul biletului: " << b1.getTipBilet() << endl;
		cout << "Locul biletului: " << b1.getLoc() << endl;
		cout << "Eveniment: " << b1.getEveniment() << endl;
		
		cout << "--Setteri--" << endl;
		b4.setLoc(15, "C");
		cout << e1;  //numarul de locuri ocupate pentru fiecare zona se modifica
		cout << b4;
		Eveniment e4(e1);
		e4.setData("12.08.2023");
		b4.setEveniment(e4);
		cout << b4;


		b1.valideaza();
		b1.valideaza();
		cout << endl;
		
		b5 = b1;
		cout << "Operatorul =" << b5 << endl;
		cout << "Operator !" << endl << !b1 << endl;
		cout << "Operator >=" << endl << b4.operator>=(b1) << endl;

		cout << "--Operator citire/afisare--" << endl;
		cin >> b1;
		cout << b1;
		cout << "---------------------------------------------" << endl;

	}
	catch (exception e) {
		cout << e.what();
	}
	
}