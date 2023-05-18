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

#endif
