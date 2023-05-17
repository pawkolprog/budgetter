#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "income.h"
#include "fileWithIncomes.h"
#include "auxiliaryMethods.h"

class OperationManager {
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;
    const int LOGGED_USER_ID;

    Income enterDataOfNewIncome();

public:
    OperationManager(string fileWithIncomesName, /*string fileWithExpensesName,*/ int loggedUserId) : fileWithIncomes(fileWithIncomesName), LOGGED_USER_ID(loggedUserId) {
    }
    void addIncome();


    void outputAllIncomes();
};





    /*



    void wyswietlDaneAdresata(Adresat adresat);
    Adresat podajDaneNowegoAdresata();
    char wybierzOpcjeZMenuEdycja();

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
        plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, ID_ZALOGOWANEGO_UZYTKOWNIKA);
    }
    void wyswietlWszystkichAdresatow();
    void dodajAdresata();
    void usunAdresata();
    void edytujAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
};

*/

#endif
