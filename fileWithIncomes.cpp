#include "fileWithIncomes.h"

int FileWithIncomes::getLastIncomeId(){
    return lastIncomeId;
}

void FileWithIncomes::addIncomeToFile(Income income){
    CMarkup xml;

    bool fileExists = xml.Load(FILE_NAME);
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", AuxiliaryMethods::changeIntDateToStringWithDashes(income.getDate()));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", to_string(income.getAmount()));

    xml.Save(FILE_NAME);
    lastIncomeId++;
}

vector <Income> FileWithIncomes::loadLoggedInUserIncomesFromFile(int loggedInUserId){
    vector <Income> incomes;
    Income income;
    CMarkup xml;

    bool fileExists = xml.Load(FILE_NAME);
    if (!fileExists) return incomes;
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem()){
        xml.FindChildElem("UserId");
        if (atoi(MCD_2PCSZ(xml.GetChildData())) == loggedInUserId){
            income.setUserId(atoi( MCD_2PCSZ(xml.GetChildData())));
            xml.ResetChildPos();
            xml.FindChildElem("IncomeId");
            income.setIncomeId(atoi( MCD_2PCSZ(xml.GetChildData())));
            xml.FindChildElem("Date");
            income.setDate(AuxiliaryMethods::changeStringWithDashesDateToInt(xml.GetChildData()));
            xml.FindChildElem("Item");
            income.setItem(xml.GetChildData());
            xml.FindChildElem("Amount");
            income.setAmount(AuxiliaryMethods::stringAmountToDouble(xml.GetChildData()));
            incomes.push_back(income);
        }
    xml.ResetChildPos();
    xml.FindChildElem("IncomeId");
    lastIncomeId = atoi(MCD_2PCSZ(xml.GetChildData()));
    }
    return incomes;
}
