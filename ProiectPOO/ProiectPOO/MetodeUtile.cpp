#include<iostream>
#include<string>
#include <ctime>

using namespace std;
#include"MetodeUtile.h"
#pragma warning(disable:4996)

//Validare ca un string este format numai din litere
bool MetodeUtile::contineDoarLitere(string s) {
	 for (int i = 0; i < s.length(); i++)
	 {
		 char c = tolower(s[i]);
		 if (!(c >= 'a' && c <= 'z')) {
			 return false;
		 }
	 }
	 return true;
}

//Validare ca un string este format numai din cifre
 bool MetodeUtile::contineDoarCifre(string s) {
	 for (int i = 0; i < s.length(); i++)
	 {
		
		 if (!(s[i] >= '0' && s[i] <= '9')) {
			 return false;
		 }
	 }
	 return true;
 }
 
 //Validare integritate data privind ziua, luna, anul, formatul si faptul ca data se afla dupa data calendaristica actuala(format dd.mm.yyyy)
 bool MetodeUtile::valideazaData(string s) {
	 if (s.length() == 10 && verificareDataEsteInViitor(s)) {
		 string ziua = s.substr(0, 2);
		 string luna = s.substr(3, 2);
		 string an = s.substr(6, 4);
		 if (contineDoarCifre(ziua) && contineDoarCifre(luna) && contineDoarCifre(an)) {
			 if (stoi(ziua) > 31 || stoi(ziua)<1) {

				 cout << "Zi mai mare de 31 sau invalida"<<endl;
				 return false;
			 }
			 if (stoi(luna) > 12 || stoi(luna) < 1) {
				 cout << "Luna mai mare de 12 sau invalida"<<endl;
				 return false;
			 }
			 if (s[2] != '.' || s[5] != '.') {
				 cout << "Data nu este de forma dd.mm.yyyy"<<endl;
				 return false;
			 }
			 return true;
		 }		 
			 cout << "Data nu este de forma dd.mm.yyyy"<<endl;
			 return false;		
	 }
	 
	 cout << "Data nu este de forma dd.mm.yyyy sau nu este inainte de data curenta"<<endl;
	 return false;
  }

 //Verificare data introdusa se afla dupa data actuala
 bool MetodeUtile::verificareDataEsteInViitor(string dataEv) {
	 time_t now = time(0);

	 char data[100];
	 strftime(data, 100, "%d.%m.%Y", localtime(&now));

	 string dataCurenta = string(data);

	 return verificarePrimaDataEsteInainte(dataCurenta, dataEv);	 
 }

 //Verificare ca prima data introdusa se afla calendaristic inaintea celei de a doua
 bool MetodeUtile::verificarePrimaDataEsteInainte(string data1, string data2) {

	 string ziData2 = data2.substr(0, 2);
	 string lunaData2 = data2.substr(3, 2);
	 string anData2 = data2.substr(6, 4);
	 
	 string ziData1 = data1.substr(0, 2);
	 string lunaData1 = data1.substr(3, 2);
	 string anData1 = data1.substr(6, 4);

	 if (anData2 > anData1) {
		 return true;
	 }
	 else if (anData2 == anData1) {
		 if (lunaData2 > lunaData1) {
			 return true;
		 }
		 else if (lunaData2 == lunaData1) {
			 if (ziData2 > ziData1) {
				 return true;
			 }
			 else {
				 return false;
			 }
		 }
		 else {
			 return false;
		 }
	 }
	 else {
		 return false;
	 }

 }

 //Validare integritate ora privind formatul,ora si minutul(format hh:mm)
 bool MetodeUtile::valideazaOra(string s) {
	 if (s.length() == 5) {
		 string ora = s.substr(0, 2);
		 string minut = s.substr(3, 2);
		 if (contineDoarCifre(ora) && contineDoarCifre(minut)) {
			 if (stoi(ora) > 23) {
				 cout << "Ora introdusa este invalida"<<endl;
				 return false;
			 }
			 if (stoi(minut) > 59) {
				 cout << "Minutul introdus este invalid" << endl;
				 return false;
			 }
			 if (s[2] != ':') {
				 cout << "Ora nu este de forma hh:mm" << endl;
				 return false;
			 }
			 return true;
		 }
		 cout << "Ora nu este de forma hh:mm"<<endl;
		 return false;
	 }
	 cout << "Ora nu este de forma hh:mm"<<endl;
	 return false;
 }


