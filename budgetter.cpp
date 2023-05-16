#include "budgetter.h"

int Budgetter::getLoggedInUserId(){
    return userManager.getLoggedInUserId();
}

void Budgetter::userRegistration(){
    userManager.userRegistration();
}

void Budgetter::userLogin(){
    if (userManager.getLoggedInUserId() == 0){
        if (userManager.userLogin()){
            //adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
        }
    }
}

void Budgetter::changePasswordLoggedInUser(){
    userManager.changePasswordLoggedInUser();
}

void Budgetter::userLogout(){
    if (userManager.getLoggedInUserId() != 0){
        userManager.userLogout();
        //delete adresatMenedzer;
        //adresatMenedzer = NULL;
    }
}

/*

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
