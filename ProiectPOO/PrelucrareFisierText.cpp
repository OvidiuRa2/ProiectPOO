#include "PrelucrareFisierText.h"
#include "PrelucrareFisierBinar.h"
#include<fstream>
#include<iostream>
#include <string>
using namespace std;

PrelucrareFisierBinar p;

void PrelucrareFisierText::citesteBilet(ifstream& f)
{
    string denumireEveniment;
    f >> ws;
    getline(f, denumireEveniment);
    string tipBilet;
    f >> ws;
    getline(f, tipBilet);
    int loc = 0;
    f >> loc;
     Bilet b(tipBilet, loc, Eveniment::contineEveniment(denumireEveniment),Bilet::genereazaIdRandom());
}

void PrelucrareFisierText::citesteEveniment(ifstream& f)
{
    string denumireLocatie;
    f >> ws;
    getline(f, denumireLocatie);
    string s;
    f >> ws;
    getline(f, s);
    char* denumire = new char[s.length()+1];
    strcpy_s(denumire, s.length()+1, s.c_str());
    string data;
    f >> ws;
    getline(f, data);
    string ora;
    f >> ws;
    getline(f, ora);
     Eveniment e(Locatie::contineLocatia(denumireLocatie), denumire, data, ora);
     p.scrie(e);
}

void PrelucrareFisierText::citesteLocatie(ifstream& f)
{
    string denumire;
    f >> ws;
    getline(f,denumire);
    int nrMaximLocuri = 0;
    f >> nrMaximLocuri;
    int nrZone = 0;
    f >> nrZone;
   
    string* zone = new string[nrZone];
    for (int i = 0; i < nrZone; i++)
    {
        f >> ws;
        getline(f,zone[i]);
    }
    int* nrLocuriPerZona = new int[nrZone];
    for (int i = 0; i < nrZone; i++)
    {
        f >> nrLocuriPerZona[i];
    }
    float* preturi = new float[nrZone];
    for (int i = 0; i < nrZone; i++)
    {
        f >> preturi[i];
    }
   
      Locatie l(nrMaximLocuri,zone,nrLocuriPerZona,nrZone,preturi,denumire);
      p.scrie(l);
}

void PrelucrareFisierText::scrie( Bilet)
{
}

void PrelucrareFisierText::scrie( Eveniment)
{
}

void PrelucrareFisierText::scrie(Locatie)
{
}

void PrelucrareFisierText::citeste(string denumireFisier) {
    ifstream f(denumireFisier, ios::in);
    string tip;
    while (f >> tip) {
        if (tip == "l") {
            citesteLocatie(f);
        }
        else if (tip == "e") {
            citesteEveniment(f);
        }
        else if (tip == "b") {
            citesteBilet(f);
        }
        else {
            throw exception ("Datele introduse in fisier sunt invalide");
        }
    }
    f.close();
}