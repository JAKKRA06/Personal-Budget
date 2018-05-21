#include "Conversion.h"

Conversion::Conversion(){;}

Conversion::~Conversion(){;}

string Conversion::intToString(int number){

    string str = "";
    stringstream ss;
    ss << number;
    return str = ss.str();
}

int Conversion::stringToInt(string date){

    int newDate = 0;
    return newDate = atoi(date.c_str());
}

string Conversion::doubleToString(double amount){

    ostringstream str;
    str << amount;
    return str.str();

}

