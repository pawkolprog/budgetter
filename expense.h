#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <math.h>

using namespace std;

class Expense
{
    int expenseId, userId, date;
    string item;
    double amount;

public:

    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();
};

#endif
