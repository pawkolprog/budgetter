#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>

#include "income.h"
#include "fileWithIncomes.h"
#include "auxiliaryMethods.h"

class OperationManager {
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;
    const int LOGGED_USER_ID;

    Income enterDataOfNewIncome();
    void sortIncomesVector();
    void putIncomeInSortedVector(Income income);
    void viewIncomeData(int i);

public:
    OperationManager(string fileWithIncomesName, /*string fileWithExpensesName,*/ int loggedUserId) : fileWithIncomes(fileWithIncomesName), LOGGED_USER_ID(loggedUserId) {
    incomes = fileWithIncomes.loadLoggedInUserIncomesFromFile(LOGGED_USER_ID);
    sortIncomesVector();
    }
    void addIncome();
    void viewCurrentMonthBalance();
    void viewLastMonthBalance();
    void viewBalanceForGivenDates();


    void outputAllIncomes();
};

#endif
