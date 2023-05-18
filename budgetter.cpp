#include "budgetter.h"

int Budgetter::getLoggedInUserId(){
    return userManager.getLoggedInUserId();
}

void Budgetter::userRegistration(){
    userManager.userRegistration();
}

void Budgetter::userLogin(){
    if (userManager.getLoggedInUserId() == 0){
        if (userManager.userLogin()){
            operationManager = new OperationManager(FILE_WITH_INCOMES_NAME, FILE_WITH_EXPENSES_NAME, userManager.getLoggedInUserId());
        }
    }
}

void Budgetter::changePasswordLoggedInUser(){
    userManager.changePasswordLoggedInUser();
}

void Budgetter::userLogout(){
    if (userManager.getLoggedInUserId() != 0){
        userManager.userLogout();
        delete operationManager;
        operationManager = NULL;
    }
}

void Budgetter::addIncome(){
    operationManager -> addIncome();
}

void Budgetter::addExpense(){
    operationManager -> addExpense();
}

void Budgetter::viewCurrentMonthBalance(){
    operationManager -> viewCurrentMonthBalance();
}

void Budgetter::viewLastMonthBalance(){
    operationManager -> viewLastMonthBalance();
}

void Budgetter::viewBalanceForGivenDates(){
    operationManager -> viewBalanceForGivenDates();
}
