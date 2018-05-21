#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <cstddef>
#include <cstdlib>
#include <sstream>
#include <map>

#include <time.h>
#include <Conversion.h>

using namespace std;

class Date
{
    public:
        Date();
        virtual ~Date();

        int getCurrentDate();
        bool checkDate(string enteredDateFromUser);
        string changeDateSeparatedByDashToNumber(string date);
        int convertDateFromStringWithDashToInt(string enteredDate);
        string convertDateFromIntToStringWithDash(int date);
        int enterDate();

    private:
        int getNumberOfDaysOfTheMonth();
        string setLastDate(int numberOfDaysOfTheCurrentMonth);
};

#endif // DATE_H
