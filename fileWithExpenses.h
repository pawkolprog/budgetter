#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "expense.h"
#include "auxiliaryMethods.h"
#include "textFile.h"

class FileWithExpenses :public TextFile {
    int lastExpenseId;

    public:
    FileWithExpenses(string fileName) : TextFile(fileName) {
    lastExpenseId = 0;
    }
    int getLastExpenseId();
    void addExpenseToFile(Expense expense);
    vector <Expense> loadLoggedInUserExpensesFromFile(int loggedInUserId);
};

#endif
