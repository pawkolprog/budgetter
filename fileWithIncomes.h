#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "income.h"
#include "auxiliaryMethods.h"
#include "textFile.h"

class FileWithIncomes :public TextFile {
    int lastIncomeId;

    public:
    FileWithIncomes(string fileName) : TextFile(fileName) {
    lastIncomeId = 0;
    }
    int getLastIncomeId();
    void addIncomeToFile(Income income);
    vector <Income> loadLoggedInUserIncomesFromFile(int loggedInUserId);
};


/*
class PlikZAdresatami :public PlikTekstowy {
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);

public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {
    idOstatniegoAdresata = 0;
}
    void dopiszAdresataDoPliku(Adresat adresat);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    void usunAdresata(int idUsuwanegoAdresata);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata);
};
*/

#endif
