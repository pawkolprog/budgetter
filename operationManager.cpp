#include "operationManager.h"

void OperationManager::addIncome(){
    Income income;

    system("cls");
    cout << " >>> ADD NEW INCOME <<<" << endl << endl;
    income = enterDataOfNewIncome();
    putIncomeInSortedVector(income);
    fileWithIncomes.addIncomeToFile(income);
    cout << endl << "Income has been added." << endl << endl;
    system("pause");
}

Income OperationManager::enterDataOfNewIncome(){
    Income income;
    char choice;
    string manualDate, stringAmount;

    income.setIncomeId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(LOGGED_USER_ID);

    cout << "Enter the transaction title: ";
    income.setItem(AuxiliaryMethods::readLine());

    cout << "Was it today? <y/n>: ";
    choice = AuxiliaryMethods::readCharYorN();
    if (choice == 'y') income.setDate(AuxiliaryMethods::getCurrentDateInt());
    else {
        cout << "Enter date from 2000-01-01 to last day of current month (yyyy-mm-dd): ";
        manualDate = AuxiliaryMethods::readLine();
        while(!AuxiliaryMethods::checkStringWithDashesDate(manualDate)) {
            cout << "Wrong date. Try again (yyyy-mm-dd): ";
            manualDate = AuxiliaryMethods::readLine();
        }
        income.setDate(AuxiliaryMethods::changeStringWithDashesDateToInt(manualDate));
    }

    cout << "Enter amount of the transaction: ";
    stringAmount = AuxiliaryMethods::readLine();
    while(!AuxiliaryMethods::checkStringAmount(stringAmount)){
        cout << "It is not valid number. Try again: ";
        stringAmount = AuxiliaryMethods::readLine();
    }
    income.setAmount(AuxiliaryMethods::stringAmountToDouble(stringAmount));

    return income;
}

void OperationManager::sortIncomesVector(){
    sort(incomes.begin( ), incomes.end( ), [ ]( auto lhs, auto rhs ){return lhs.getDate() < rhs.getDate();});
}

void OperationManager::putIncomeInSortedVector(Income income){
    if (incomes.empty()) incomes.push_back(income);
    else {
        for (vector <Income>::iterator it = incomes.end(); it != incomes.begin(); --it){
            if (income.getDate() >= (it - 1) -> getDate()){
                incomes.emplace(it, income);
                return;
            }
        }
        incomes.emplace(incomes.begin(), income);
    }
}

void OperationManager::viewCurrentMonthBalance(){
    system("cls");
    int yearMonth, counter = 0;
    double sum = 0;

    if (incomes.empty()){
        cout << endl << "No added transactions." << endl << endl;
        system("pause");
        return;
    }
    yearMonth = (AuxiliaryMethods::getCurrentDateInt()) / 100;
    yearMonth *= 100;

    for (int i = 0; i < (int) incomes.size(); i++){
        if (incomes[i].getDate() > yearMonth){
            if (counter == 0){
                cout << "        >>> CURRENT MONTH BALANCE <<<" << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "DATE         AMOUNT                  ITEM" << endl;
            }
            viewIncomeData(i);
            sum += incomes[i].getAmount();
            counter++;
        }
    }
    if (counter == 0) {
        cout << "No added transactions this month.";
        system("pause");
    } else {
        cout << endl << "Number of found transactions: " << counter;
        cout << ". Sum of transactions: " << setprecision(15) << sum << endl;
        system("pause");
    }
}

void OperationManager::viewIncomeData(int i)
{
    cout << AuxiliaryMethods::changeIntDateToStringWithDashes(incomes[i].getDate()) << "   ";
    cout << setprecision(15) << incomes[i].getAmount() << "                  ";
    cout << incomes[i].getItem() << endl;
}

void OperationManager::viewLastMonthBalance(){
    system("cls");
    int minYearMonth, maxYearMonth, counter = 0;
    double sum = 0;

    if (incomes.empty()){
        cout << endl << "No added transactions." << endl << endl;
        system("pause");
        return;
    }
    maxYearMonth = (AuxiliaryMethods::getCurrentDateInt()) / 100;
    if (maxYearMonth%100 == 1) minYearMonth = maxYearMonth - 100 + 11;
    else minYearMonth = maxYearMonth - 1;
    maxYearMonth *= 100;
    minYearMonth *= 100;

    for (int i = 0; i < (int) incomes.size(); i++){
        if (incomes[i].getDate() > minYearMonth && incomes[i].getDate() < maxYearMonth){
            if (counter == 0){
                cout << "         >>> LAST MONTH BALANCE <<<" << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "DATE         AMOUNT                  ITEM" << endl;
            }
            viewIncomeData(i);
            sum += incomes[i].getAmount();
            counter++;
        }
    }
    if (counter == 0) {
        cout << "No added transactions last month." << endl;
        system("pause");
    } else {
        cout << endl << "Number of found transactions: " << counter;
        cout << ". Sum of transactions: " << setprecision(15) << sum << endl;
        system("pause");
    }
}

void OperationManager::viewBalanceForGivenDates() {
    system("cls");
    int minIntDate, maxIntDate, counter = 0;
    string minStringDate, maxStringDate;
    double sum = 0;

    if (incomes.empty()) {
        cout << endl << "No added transactions." << endl << endl;
        system("pause");
        return;
    }

    cout << "Enter the start date from 2000-01-01 to last day of current month (yyyy-mm-dd): ";
    minStringDate = AuxiliaryMethods::readLine();
    while(!AuxiliaryMethods::checkStringWithDashesDate(minStringDate)) {
        cout << "Wrong date. Try again (yyyy-mm-dd): ";
        minStringDate = AuxiliaryMethods::readLine();
    }
    minIntDate = AuxiliaryMethods::changeStringWithDashesDateToInt(minStringDate);

    cout << "Enter the end date from " << minStringDate << " to last day of current month (yyyy-mm-dd): ";
    maxStringDate = AuxiliaryMethods::readLine();
    while(!AuxiliaryMethods::checkStringWithDashesDate(maxStringDate) || AuxiliaryMethods::changeStringWithDashesDateToInt(maxStringDate) < minIntDate) {
        cout << "Wrong date. Try again (yyyy-mm-dd): ";
        maxStringDate = AuxiliaryMethods::readLine();
    }
    maxIntDate = AuxiliaryMethods::changeStringWithDashesDateToInt(maxStringDate);

    for (int i = 0; i < (int) incomes.size(); i++) {
        if (incomes[i].getDate() >= minIntDate && incomes[i].getDate() <= maxIntDate) {
            if (counter == 0) {
                cout << " >>> BALANCE FROM " << minStringDate << " TO " << maxStringDate << " <<<" << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "DATE         AMOUNT                  ITEM" << endl;
            }
            viewIncomeData(i);
            sum += incomes[i].getAmount();
            counter++;
        }
    }
    if (counter == 0) {
        cout << "No added transactions between given dates." << endl;
        system("pause");
    } else {
        cout << endl << "Number of found transactions: " << counter;
        cout << ". Sum of transactions: " << setprecision(15) << sum << endl;
        system("pause");
    }
}

void OperationManager::outputAllIncomes() {
    for (int i = 0; i < (int) incomes.size(); i++) {
        cout << incomes[i].getIncomeId() << endl;
        cout << incomes[i].getUserId() << endl;
        cout << incomes[i].getItem() << endl;
        cout << incomes[i].getDate() << endl;
        cout << setprecision(10) << incomes[i].getAmount() << endl;
    }
}
