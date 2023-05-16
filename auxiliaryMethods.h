#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H


#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods {
public:
    static string conversionIntToString(int number);
    static string readLine();
    static string changeFirstLetterToCapitalAndRestLettersToLowercase(string line);
    static int conversionStringToInt(string number);
    static char readChar();
    static int readInteger();
};

#endif
