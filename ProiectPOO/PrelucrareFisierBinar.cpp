#include "PrelucrareFisierBinar.h"
#include "Meniu.h"
#include <fstream>

void PrelucrareFisierBinar::citesteBilet(ifstream& f)
{
    string denumireEveniment,tipBilet;
    int length = 0,loc =0, valid=0,id=0;
    char* denumire;
    while (f.read((char*)&length, sizeof(length))) {
        denumire = new char[length + 1];
        f.read(denumire, length + 1);
        denumireEveniment = denumire;
      
         f.read((char*)&length, sizeof(length));
         denumire = new char[length + 1];
         f.read(denumire, length + 1);
         tipBilet = denumire;
         delete[] denumire;

        f.read((char*)&loc, sizeof(loc));
        f.read((char*)&valid, sizeof(valid));
        f.read((char*)&id, sizeof(id));
       
        if (Eveniment::contineEveniment(denumireEveniment, true)) {
        Bilet b(tipBilet, loc, Eveniment::contineEveniment(denumireEveniment),id);
        if (valid == 1) {
            Bilet::valideazaUltimulElement();
        }
        }
      
    }
}

void PrelucrareFisierBinar::citesteEveniment(ifstream& f)
{
    string denumireLocatie,denumireEveniment,data,ora;
    int length = 0;
    char* denumire;
    while(f.read((char*)&length, sizeof(length))){
        denumire = new char[length + 1];
        f.read(denumire, length + 1);
        denumireLocatie = denumire;
        
            f.read((char*)&length, sizeof(length));
             denumire = new char[length + 1];
            f.read(denumire, length + 1);
            denumireEveniment = denumire;
           

            f.read((char*)&length, sizeof(length));
             denumire = new char[length + 1];
            f.read(denumire, length + 1);
            data = denumire;
           

            f.read((char*)&length, sizeof(length));
             denumire = new char[length + 1];
            f.read(denumire, length + 1);
            ora = denumire;
            delete[] denumire;
            if (Locatie::contineLocatia(denumireLocatie, true)) {

              Eveniment e(Locatie::contineLocatia(denumireLocatie), denumireEveniment.c_str(), data, ora);
            }
           

    }
}

void PrelucrareFisierBinar::citesteLocatie(ifstream& f)
{
    int nrMaxim = 0, nrZone = 0,length=0;
    string* zone;
    int* nrLocuriPerZona;
    float* preturiPerZona;
    char* zona;
    char* den;

    while(f.read((char*)&nrMaxim, sizeof(nrMaxim))){
    f.read((char*)&nrZone, sizeof(nrZone));
    zone = new string[nrZone];
    nrLocuriPerZona = new int[nrZone];
    preturiPerZona = new float[nrZone];
    
    for (int i = 0; i < nrZone; i++)
    {
        f.read((char*)&length, sizeof(length));
        zona = new char[length + 1];
        f.read(zona, length + 1);
        zone[i] = zona;
        delete[] zona;
    }

    for (int i = 0; i < nrZone; i++)
    {
        f.read((char*)&nrLocuriPerZona[i], sizeof(nrLocuriPerZona[i]));
    }

    for (int i = 0; i < nrZone; i++)
    {
        f.read((char*)&preturiPerZona[i], sizeof(preturiPerZona[i]));
    }

    string denumire;

    f.read((char*)&length, sizeof(length));
     den = new char[length + 1];
    f.read(den, length + 1);
    denumire = den;
    delete[] den;
     Locatie l(nrMaxim,zone,nrLocuriPerZona,nrZone,preturiPerZona,denumire);
    }
}

void PrelucrareFisierBinar::scrie( Bilet b)
{
    ofstream f("Bilete.bin", ios::out | ios::binary | ios::app);
    int length = strlen(b.getEveniment().getDenumire());
    f.write((char*)&length, sizeof(length));
    f.write(b.getEveniment().getDenumire(), length + 1);
    string tipBilet = b.getTipBilet();
    int loc = b.getLoc();
    length = tipBilet.length();
    f.write((char*)&length, sizeof(length));
    f.write(tipBilet.c_str(), length + 1);

    f.write((char*)&loc, sizeof(loc));

    int valid = b.getValidat();
    f.write((char*)&valid, sizeof(valid));

    int id = b.getIdBilet();
    f.write((char*)&id, sizeof(id));
    f.close();
}

void PrelucrareFisierBinar::scrie( Eveniment e)
{
    ofstream f("Evenimente.bin", ios::out | ios::binary | ios::app);
    string denumireLocatie = e.getLocatie().getDenumire();
    int length = denumireLocatie.length();
    f.write((char*)&length, sizeof(length));
    f.write(denumireLocatie.c_str(), length + 1);
    string denumireEveniment = e.getDenumire();
    length = denumireEveniment.length();
    f.write((char*)&length, sizeof(length));
    f.write(denumireEveniment.c_str(), length + 1);
    string data = e.getData();
    length = data.length();
    f.write((char*)&length, sizeof(length));
    f.write(data.c_str(), length + 1);
    string ora = e.getOra();
    length = ora.length();
    f.write((char*)&length, sizeof(length));
    f.write(ora.c_str(), length + 1);
    f.close();
}

void PrelucrareFisierBinar::scrie( Locatie l)
{
    ofstream f("Locatii.bin", ios::out | ios::binary | ios::app);
    int nrMaxim = l.getNumarMaximLocuri();
    f.write((char*)&nrMaxim, sizeof(nrMaxim));
    int nrZone = l.getNrZone();
    f.write((char*)&nrZone, sizeof(nrZone));
    for (int i = 0; i < nrZone; i++)
    {
        int length = l.getZone()[i].length();
        f.write((char*)&length, sizeof(length));
        f.write(l.getZone()[i].c_str(), length + 1);
    }
    for (int i = 0; i < nrZone; i++)
    {
        int nrLocuri= l.getNrLocuriPerZona()[i];
        f.write((char*)&nrLocuri, sizeof(nrLocuri));

    }
    for (int i = 0; i < nrZone; i++)
    {
        float pret = l.getPreturiPerZona()[i];
        f.write((char*)&pret, sizeof(pret));

    }
    string denumire = l.getDenumire();
    int length = denumire.length();
    f.write((char*)&length, sizeof(length));
    f.write(denumire.c_str(), length + 1);
    f.close();
}

 void PrelucrareFisierBinar::scrieNumeFisier(string numeFisier){
     ofstream f("NumeFisiere.bin", ios::out | ios::binary | ios::app);
     int length = numeFisier.length();
     f.write((char*)&length, sizeof(length));
     f.write(numeFisier.c_str(), length + 1);
     f.close();
 }

 void PrelucrareFisierBinar::citesteNumeFisier() {
     ifstream f("NumeFisiere.bin", ios::in | ios::binary);
     int length;
     while (f.read((char*)&length, sizeof(length))) {
         string denumire;

         char*den = new char[length + 1];
         f.read(den, length + 1);
         denumire = den;
         delete[] den;

         Meniu::adaugaNumeFisier(denumire);
     }
     f.close();
 }


void PrelucrareFisierBinar::citeste() {
    ifstream f1("Locatii.bin", ios::in | ios::binary);
        citesteLocatie(f1);
        f1.close();

    ifstream f2("Evenimente.bin", ios::in | ios::binary);
        citesteEveniment(f2);
        f2.close();

    ifstream f3("Bilete.bin", ios::in | ios::binary);
        citesteBilet(f3);
        f3.close();
}
