#include "auxiliaryMethods.h"

string AuxiliaryMethods::conversionIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::readLine() {
    string input = "";
    getline(cin, input);
    return input;
}

string AuxiliaryMethods::changeFirstLetterToCapitalAndRestLettersToLowercase(string line){
    if (!line.empty())
    {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        line[0] = toupper(line[0]);
    }
    return line;
}

int AuxiliaryMethods::conversionStringToInt(string number){
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

char AuxiliaryMethods::readChar(){
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not correct. Try again." << endl;
    }
    return character;
}

char AuxiliaryMethods::readCharYorN(){
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1 && (input[0] == 'y' || input[0] == 'n'))
        {
            character = input[0];
            break;
        }
        cout << "This is not correct. Try again." << endl;
    }
    return character;
}

int AuxiliaryMethods::readInteger()
{
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

string AuxiliaryMethods::changeIntDateToStringWithDashes(int intDate){
    string stringDate;
    stringstream ss;

    ss << intDate;
    stringDate = ss.str();
    stringDate.insert(4, "-");
    stringDate.insert(7, "-");
    return stringDate;
}

int AuxiliaryMethods::changeStringWithDashesDateToInt(string stringDate){
    int intDate;
    stringDate.erase(stringDate.begin()+7);
    stringDate.erase(stringDate.begin()+4);
    intDate = atoi(stringDate.c_str());
    return intDate;
}

int AuxiliaryMethods::getCurrentDateInt() {
    int currentDate;
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    currentDate = (1900 + timeinfo -> tm_year) * 10000 + (1 + timeinfo -> tm_mon) * 100 + (timeinfo -> tm_mday);

    return currentDate;
}

bool AuxiliaryMethods::checkStringWithDashesDate(string stringDate){
    int intDate;
    if (!checkDateFormat(stringDate)) return false;
    intDate = changeStringWithDashesDateToInt(stringDate);
    if (!isValidDateInt(intDate)) return false;
    return true;
}

bool AuxiliaryMethods::checkDateFormat(string stringDate) {
    if (stringDate.length() != 10) return false;
    if (!((size_t) stringDate.find('-') == 4 && (size_t) stringDate.find('-', 5) == 7)) return false;
    return true;
}

bool AuxiliaryMethods::isValidDateInt(int dateToCheck){
    int minValidDateMonth = 200001;
    int maxValidDateMonth = getCurrentDateInt() / 100;
    int year, month, day;
    day = dateToCheck%100;
    dateToCheck /= 100;
    if (dateToCheck > maxValidDateMonth || dateToCheck < minValidDateMonth) return false;
    month = dateToCheck%100;
    dateToCheck /= 100;
    year = dateToCheck;

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    if (month == 2)
    {
        if (isLeap(year)) return (day <= 29);
        else return (day <= 28);
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
        return (day <= 30);

    return true;
}

bool AuxiliaryMethods::isLeap(int year) {
return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool AuxiliaryMethods::checkStringAmount(string stringAmount){
    int counter = 0;
    for (int i = 0; i < (int) stringAmount.size(); i++){
        if (!isdigit(stringAmount[i])){
            if (stringAmount[i] != '.' && stringAmount[i] != ',') return false;
            else counter++;
        }
    }
    if (counter > 1) return false;
    else return true;
}

double AuxiliaryMethods::stringAmountToDouble(string stringAmount){
    double doubleAmount;
    for (int i = 0; i < (int) stringAmount.size(); i++){
        if (stringAmount[i] == ',') stringAmount.replace(i, 1, ".");
    }
    doubleAmount = stod(stringAmount);
    return doubleAmount;
}

