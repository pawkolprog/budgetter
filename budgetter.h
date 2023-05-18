#ifndef BUDGETTER_H
#define BUDGETTER_H

#include <iostream>

#include "userManager.h"
#include "operationManager.h"

using namespace std;

class Budgetter {
    UserManager userManager;
    OperationManager *operationManager;
    const string FILE_WITH_INCOMES_NAME;
    const string FILE_WITH_EXPENSES_NAME;

public:
    Budgetter(string fileWithIncomesName, string fileWithExpensesName, string fileWithUsersName) : userManager(fileWithUsersName), FILE_WITH_INCOMES_NAME(fileWithIncomesName), FILE_WITH_EXPENSES_NAME(fileWithExpensesName)
    {
        operationManager = NULL;
    }
    ~Budgetter(){
        delete operationManager;
        operationManager = NULL;
    }

    int getLoggedInUserId();
    void userRegistration();
    void userLogin();
    void changePasswordLoggedInUser();
    void userLogout();
    void addIncome();
    void addExpense();
    void viewCurrentMonthBalance();
    void viewLastMonthBalance();
    void viewBalanceForGivenDates();
};

#endif
