#include "budgetter.h"

int Budgetter::getLoggedInUserId(){
    return userManager.getLoggedInUserId();
}

/*

void AdressBook::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void AdressBook::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void AdressBook::zalogujUzytkownika() {
    if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() == 0){
        if (uzytkownikMenedzer.logowanieUzytkownika()){
            adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
        }
    }
}

void AdressBook::dodajAdresata(){
    if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() != 0){
        adresatMenedzer -> dodajAdresata();
    } else {
        cout << "Przed dodaniem adresata nalezy sie zalogowac." << endl;
        system("pause");
        return;
    }
}

void AdressBook::wyswietlWszystkichAdresatow(){
    adresatMenedzer -> wyswietlWszystkichAdresatow();
}

void AdressBook::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void AdressBook::wylogujUzytkownika() {
    if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() != 0){
        uzytkownikMenedzer.wylogujUzytkownika();
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    }
}

int AdressBook::pobierzIdZalogowanegoUzytkownika(){
    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

void AdressBook::usunAdresata(){
    adresatMenedzer -> usunAdresata();
}

void AdressBook::edytujAdresata(){
    adresatMenedzer -> edytujAdresata();
}

void AdressBook::wyszukajAdresatowPoImieniu(){
    adresatMenedzer -> wyszukajAdresatowPoImieniu();
}

void AdressBook::wyszukajAdresatowPoNazwisku(){
    adresatMenedzer -> wyszukajAdresatowPoNazwisku();
}

*/
