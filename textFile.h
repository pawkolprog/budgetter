#ifndef TEXTFILE_H
#define TEXTFILE_H


#include <iostream>
#include "Markup.h"

using namespace std;

class TextFile {
protected:
    const string FILE_NAME;

public:
    TextFile(string fileName) : FILE_NAME(fileName) {}
};

#endif
