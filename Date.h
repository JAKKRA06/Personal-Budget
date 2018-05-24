#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <cstddef>
#include <cstdlib>
#include <sstream>
#include <map>
#include <time.h>

#include "Conversion.h"

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
        int getDayFromUser();
        int getMonthFromUser();
        void setDayFromUser(int day);
        void setMonthFromUser(int month);
        int getCurrentMonth();
        int getCurrentYear();
        int getFirstDateInMonth(int year, int month);
        int getLastDateInMonth(int year, int month);

    private:
        int getNumberOfDaysOfTheCurrentMonth();
        string setLastDate(int numberOfDaysOfTheCurrentMonth);
        int dayFromUser;
        void separateDateFromUser(string date);
        int monthFromUser;
        int getNumberOfDaysOfMonth(int numberOfMonth);
};

#endif // DATE_H
