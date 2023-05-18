#include "fileWithExpenses.h"

int FileWithExpenses::getLastExpenseId(){
    return lastExpenseId;
}

void FileWithExpenses::addExpenseToFile(Expense expense){
    CMarkup xml;

    bool fileExists = xml.Load(FILE_NAME);
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", AuxiliaryMethods::changeIntDateToStringWithDashes(expense.getDate()));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", to_string(expense.getAmount()));

    xml.Save(FILE_NAME);
    lastExpenseId++;
}

vector <Expense> FileWithExpenses::loadLoggedInUserExpensesFromFile(int loggedInUserId){
    vector <Expense> expenses;
    Expense expense;
    CMarkup xml;

    bool fileExists = xml.Load(FILE_NAME);
    if (!fileExists) return expenses;
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem()){
        xml.FindChildElem("UserId");
        if (atoi(MCD_2PCSZ(xml.GetChildData())) == loggedInUserId){
            expense.setUserId(atoi( MCD_2PCSZ(xml.GetChildData())));
            xml.ResetChildPos();
            xml.FindChildElem("ExpenseId");
            expense.setExpenseId(atoi( MCD_2PCSZ(xml.GetChildData())));
            xml.FindChildElem("Date");
            expense.setDate(AuxiliaryMethods::changeStringWithDashesDateToInt(xml.GetChildData()));
            xml.FindChildElem("Item");
            expense.setItem(xml.GetChildData());
            xml.FindChildElem("Amount");
            expense.setAmount(AuxiliaryMethods::stringAmountToDouble(xml.GetChildData()));
            expenses.push_back(expense);
        }
    xml.ResetChildPos();
    xml.FindChildElem("ExpenseId");
    lastExpenseId = atoi(MCD_2PCSZ(xml.GetChildData()));
    }
    return expenses;
}
