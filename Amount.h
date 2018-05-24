#ifndef AMOUNT_H
#define AMOUNT_H

#include <iostream>

#include "stdlib.h"
#include "Conversion.h"

using namespace std;

class Amount
{
    public:
        Amount();
        virtual ~Amount();

        string changeCommaToDot(string amount);
        double enterAmount();
        bool isThereComma(string amount);
};

#endif // AMOUNT_H
