#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H


#include <iostream>
#include <sstream>
#include <algorithm>
#include <time.h>

using namespace std;

class AuxiliaryMethods {
public:
    static string conversionIntToString(int number);
    static string readLine();
    static string changeFirstLetterToCapitalAndRestLettersToLowercase(string line);
    static int conversionStringToInt(string number);
    static char readChar();
    static char readCharYorN();
    static int readInteger();
    static string changeIntDateToStringWithDashes(int intDate);
    static int changeStringWithDashesDateToInt(string stringDate);
    static int getCurrentDateInt();
    static bool checkStringWithDashesDate(string stringDate);
    static bool checkDateFormat(string stringDate);
    static bool isValidDateInt(int dateToCheck);
    static bool isLeap(int year);
    static bool checkStringAmount(string stringAmount);
    static double stringAmountToDouble(string stringAmount);
};

#endif
