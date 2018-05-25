#include "Date.h"

Date::Date(){

    dayFromUser = 0;
    monthFromUser = 0;
}

Date::~Date(){;}

int Date::getCurrentDate(){

    Conversion conversion;
    string currentDate = ""; string year = ""; string month = ""; string day = "";

    time_t now = time(NULL);
    tm *ltm = localtime(&now);

    year = conversion.intToString(1900 + ltm->tm_year);
    month = conversion.intToString(1 + ltm->tm_mon);

    if(month.length() < 2)
    {
        month = "";
        month += "0" + conversion.intToString(1 + ltm->tm_mon);
    }
    day = conversion.intToString(ltm->tm_mday);
    if(day.length() < 2)
    {
        day = "";
        day += "0" + conversion.intToString(ltm->tm_mday);
    }

    currentDate =  year + month + day;

    return conversion.stringToInt(currentDate);
}

string Date::changeDateSeparatedByDashToNumber(string date){

    date.erase(date.begin()+4);
    date.erase(date.begin()+6);

    return date;
}

void Date::setDayFromUser(int day){

    this->dayFromUser = day;
}

void Date::setMonthFromUser(int month){

    this->monthFromUser = month;
}

int Date::getDayFromUser(){

    return dayFromUser;
}

int Date::getMonthFromUser(){

    return monthFromUser;
}

void Date::separateDateFromUser(string date){

    Conversion conversion;
    string month = "";string day = "";

    for(int counter = 0; counter < date.length(); counter++){

        if(counter == 5){
                if(date[counter] == '0'){;}
                else{ month += date[counter];}
        }
        else if(counter == 6){ month += date[counter];}
        else if(counter == 8){ day += date[counter];}
        else if(counter == 9){ day += date[counter];}
    }

    setDayFromUser(conversion.stringToInt(day));
    setMonthFromUser(conversion.stringToInt(month));
}

int Date::getNumberOfDaysOfMonth(int numberOfMonth){

    time_t now = time(NULL);
    tm *ltm = localtime(&now);
    int year = getCurrentYear();
    int numberOfDaysOfFebruary = 29;

    map<int, int> month;
    month [1] = 31;
    month [2] = 28;
    month [3] = 31;
    month [4] = 30;
    month [5] = 31;
    month [6] = 30;
    month [7] = 31;
    month [8] = 31;
    month [9] = 30;
    month [10] = 31;
    month [11] = 30;
    month [12] = 31;

     if((year%4 == 0 && year%100 != 0) || year%400 == 0)
     {
         if(numberOfMonth == 2)
            return numberOfDaysOfFebruary;
        else
            return month[numberOfMonth];
     }
     else
        return month[numberOfMonth];
}

bool Date::checkDate(string enteredDateFromUser){

    string startDate = "20000101"; string lastDate = "";

    separateDateFromUser(enteredDateFromUser);

    int numberOfMonth = getCurrentMonth();
    int numberOfDaysOfTheCurrentMonth = getNumberOfDaysOfTheCurrentMonth();
    lastDate = setLastDate(numberOfDaysOfTheCurrentMonth);

    string lastDateWithoutDashes = changeDateSeparatedByDashToNumber(lastDate);
    enteredDateFromUser = changeDateSeparatedByDashToNumber(enteredDateFromUser);

    if(getDayFromUser() <= getNumberOfDaysOfMonth(getMonthFromUser()))
    {
        if((atoi(enteredDateFromUser.c_str()) >= atoi(startDate.c_str())) && (atoi(enteredDateFromUser.c_str()) <= atoi(lastDateWithoutDashes.c_str())) && getMonthFromUser() < 12)
        {
            return true;
        }
        else
        {
            cout << "Entered date form user is not correct." << endl;
            cout << "Enter date form 2000-01-01 to the last day of current month." << endl;
            return false;
        }
    }
    else
    {
        cout << "Entered date form user is not correct." << endl;
        cout << "Enter date form 2000-01-01 to the last day of current month." << endl;
        return false;
    }
}

string Date::setLastDate(int numberOfDaysOfTheCurrentMonth){

    Conversion conversion;
    string lastDate = ""; string year = ""; string month = ""; string day = "";
    time_t now = time(NULL);
    tm *ltm = localtime(&now);

    year = conversion.intToString(1900 + ltm->tm_year);
    month = conversion.intToString(1 + ltm->tm_mon);

    if(month.length() < 2)
    {
        month = "";
        month += "0" + conversion.intToString(1 + ltm->tm_mon);
    }
    day = conversion.intToString(numberOfDaysOfTheCurrentMonth);
    lastDate =  year + "-" + month + "-" + day;
    return lastDate;
}

int Date::getNumberOfDaysOfTheCurrentMonth(){

    int numberOfTheMonth = 0;

    time_t now = time(NULL);
    tm *ltm = localtime(&now);
    numberOfTheMonth = 1 + ltm->tm_mon;

    map<int, int> month;
    month [1] = 31;
    month [2] = 28;
    month [3] = 31;
    month [4] = 30;
    month [5] = 31;
    month [6] = 30;
    month [7] = 31;
    month [8] = 31;
    month [9] = 30;
    month [10] = 31;
    month [11] = 30;
    month [12] = 31;

    return month[numberOfTheMonth];
}

int Date::getCurrentYear(){

    int currentYear = 0;

    time_t now = time(NULL);
    tm *ltm = localtime(&now);
    currentYear = 1900 + ltm->tm_year;
    return currentYear;
}

int Date::getCurrentMonth(){

    int currentMonth = 0;

    time_t now = time(NULL);
    tm *ltm = localtime(&now);
    currentMonth = 1 + ltm->tm_mon;

    return currentMonth;
}

int Date::convertDateFromStringWithDashToInt(string enteredDate){

    Conversion conversion;
    int date = 0;
    enteredDate = changeDateSeparatedByDashToNumber(enteredDate);

    return conversion.stringToInt(enteredDate);
}

int Date::enterDate(){

    Conversion conversion;
    string date = "";
    bool correctDate = false;
    do
    {
        cout << endl << "Enter date (YYYY-MM-DD): "; cin.sync(); cin.clear();
        getline(cin, date);
        correctDate = checkDate(date);

    }while(correctDate == false);

    date = changeDateSeparatedByDashToNumber(date);

    return conversion.stringToInt(date);
}

string Date::convertDateFromIntToStringWithDash(int date){

    Conversion conversion;
    string newDate = "";
    newDate = conversion.intToString(date);

    newDate.insert(4,"-");
    newDate.insert(7,"-");
    return newDate;
}

int Date::getFirstDateInMonth(int year, int month){

    Conversion conversion;
    int firstDate = 0;
    string stringDate = "";
    int days = 1;
    time_t date = time(0);
    struct tm *now = localtime(&date);

    if(year >= 2000 & year <= (now->tm_year + 1900))
    {
        stringDate += conversion.intToString(year);
    }
    if(month < 13)
    {
        if(month >= 1 && month <= 9)
        {
            stringDate += "0" + conversion.intToString(month);
        }
        else
            stringDate += conversion.intToString(month);
    }
    if(days >= 1 && days <= 9)
    {
        stringDate += "0" + conversion.intToString(days);
    }
    else
        stringDate += conversion.intToString(days);

    firstDate = conversion.stringToInt(stringDate);
    return firstDate;
}

int Date::getLastDateInMonth(int year, int month){

    Conversion conversion;
    int lastDate = 0;
    string date = "";
    int days = getNumberOfDaysOfMonth(month);

    if(year > 2000)
    {
        date += conversion.intToString(year);
    }
    if(month < 13)
    {
        if(month >= 1 && month <= 9)
        {
            date += "0" + conversion.intToString(month);
        }
        else
            date += conversion.intToString(month);
    }
    date += conversion.intToString(days);

    return lastDate = conversion.stringToInt(date);
}
