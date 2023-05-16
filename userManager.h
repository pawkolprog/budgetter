#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "user.h"
#include "fileWithUsers.h"
#include "auxiliaryMethods.h"

using namespace std;

class UserManager {
    int loggedUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    //int pobierzIdNowegoUzytkownika();
    //bool czyIstniejeLogin(string login);

public:
    UserManager(string fileWithUsersName) : fileWithUsers(fileWithUsersName) {
    loggedUserId = 0;
    //wczytajUzytkownikow();
}
    int getLoggedInUserId();

/*
public:
    UserManager(string fileWithUsersName) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
    idZalogowanegoUzytkownika = 0;
    wczytajUzytkownikow();
}
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    Uzytkownik podajDaneNowegoUzytkownika();
    void wczytajUzytkownikow();
    bool logowanieUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();
*/
};


#endif
