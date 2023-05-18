#include "expense.h"

void Expense::setExpenseId(int newId){
    if (newId > 0)
    expenseId = newId;
}
void Expense::setUserId(int newUserId){
    if (newUserId > 0)
    userId = newUserId;
}
void Expense::setDate(int newDate){
    date = newDate;
}

void Expense::setItem(string newItem){
    item = newItem;
}

void Expense::setAmount(double newAmount){
    amount = round(newAmount*100)/100;
}

int Expense::getExpenseId() {
    return expenseId;
}
int Expense::getUserId() {
    return userId;
}
int Expense::getDate() {
    return date;
}
string Expense::getItem() {
    return item;
}
double Expense::getAmount() {
    return amount;
}
