#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include <math.h>

using namespace std;

class Income
{
    int incomeId, userId, date;
    string item;
    double amount;

public:

    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getIncomeId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();
};

#endif
