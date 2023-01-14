#pragma once
#include"Eveniment.h"
class Meniu
{
private:

	static list<string>*fisiereSalvate;

	void citesteDinFisier();

	void restaureazaDate();

	bool contineFisier(string);

	void afisareMeniuPrincipal();

	void prelucrareLocatii();
	
	void prelucrareEvenimente();

	void prelucrareBilete();

	Locatie citesteLocatie();

	Eveniment citesteEveniment();

	void citesteBilet();

	void selecteazaLocatieCreata(string&);
	
	void selecteazaEvenimentCreat(string&);

	void selecteazaBiletCreat(int&);
	
	void citireDateEveniment(string&, string&, string&);

	void citireDateBilet(string&, int&,Eveniment);

	void salveazaBilete();
	
	void iesire();
public:
	Meniu();

	static void adaugaNumeFisier(string);
};


