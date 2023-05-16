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
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
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
