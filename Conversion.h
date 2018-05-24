#ifndef CONVERSION_H
#define CONVERSION_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

#include "stdlib.h"

using namespace std;

class Conversion
{
    public:
        Conversion();
        virtual ~Conversion();

        string intToString(int number);
        int stringToInt(string date);
        string doubleToString(double amount);
};

#endif // CONVERSION_H
