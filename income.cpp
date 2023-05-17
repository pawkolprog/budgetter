#include "income.h"

void Income::setIncomeId(int newId){
    if (newId > 0)
    incomeId = newId;
}
void Income::setUserId(int newUserId){
    if (newUserId > 0)
    userId = newUserId;
}
void Income::setDate(int newDate){
    date = newDate;
}

void Income::setItem(string newItem){
    item = newItem;
}

void Income::setAmount(double newAmount){
    amount = round(newAmount*100)/100;
}

int Income::getIncomeId() {
    return incomeId;
}
int Income::getUserId() {
    return userId;
}
int Income::getDate() {
    return date;
}
string Income::getItem() {
    return item;
}
double Income::getAmount() {
    return amount;
}
