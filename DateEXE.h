#ifndef DATE_H
#define DATE_H


#include <map>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>

#include <time.h>
#include "Markup.h"

using namespace std;

class Date {
public:
    Date();
    virtual ~Date();
    void showNumberOfDaysOfTheMonth();
    void showCurrentDate();
    void comparingDate();
    void writeToFileXML();
    void findDateInFileXml();
    string getUserFileName();
    void rozdzielanieDat(string wczytanaLinia, char znak);
    void wczytajDate();

private:
    CMarkup expenses;
    string userFile;
    int numberOfDays;
    string monthUSer;
    int year;
    map<string, int> month;
    string changeCommaToDot(string amount);
};

#endif // DATE_H
