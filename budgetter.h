#ifndef BUDGETTER_H
#define BUDGETTER_H

#include <iostream>

#include "userManager.h"

using namespace std;

class Budgetter {
    UserManager userManager;
    //AdresatMenedzer *adresatMenedzer;
    const string FILE_WITH_INCOMES_NAME;
    const string FILE_WITH_EXPENSES_NAME;

public:
    Budgetter(string fileWithIncomesName, string fileWithExpensesName, string fileWithUsersName) : userManager(fileWithUsersName), FILE_WITH_INCOMES_NAME(fileWithIncomesName), FILE_WITH_EXPENSES_NAME(fileWithExpensesName)
    {
    /*
    adresatMenedzer = NULL;
    }
    ~AdressBook(){
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    }
    */
    }
    int getLoggedInUserId();
    void userRegistration();
    void userLogin();
    void changePasswordLoggedInUser();
    void userLogout();

    void outputAllUsers(){
        userManager.outputAllUsers();
    }


};

#endif
