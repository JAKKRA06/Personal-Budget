#include "Date.h"

Date::Date(){;}

Date::~Date(){;}

int Date::getCurrentDate()
{
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
    currentDate =  year + month + day;

    return conversion.stringToInt(currentDate);
}

string Date::changeDateSeparatedByDashToNumber(string date)
{
    date.erase(date.begin()+4);
    date.erase(date.begin()+6);

    return date;
}

bool Date::checkDate(string enteredDateFromUser)
{
    string startDate = "20000101"; string lastDate = "";
    int numberOfDaysOfTheCurrentMonth = getNumberOfDaysOfTheMonth();
    lastDate = setLastDate(numberOfDaysOfTheCurrentMonth);

    string lastDateWithoutDashes = changeDateSeparatedByDashToNumber(lastDate);


     if((atoi(enteredDateFromUser.c_str()) >= atoi(startDate.c_str())) && (atoi(enteredDateFromUser.c_str()) <= atoi(lastDate.c_str())))
    {
        cout << "Entered date from user is correct" << endl;
        return true;
    }
    else
    {
        cout << "Entered date form user is not correct" << endl;
        return false;
    }
}

string Date::setLastDate(int numberOfDaysOfTheCurrentMonth)
{
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

int Date::getNumberOfDaysOfTheMonth()
{
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

int Date::convertDateFromStringWithDashToInt(string enteredDate){

    Conversion conversion;
    int date = 0;
    enteredDate = changeDateSeparatedByDashToNumber(enteredDate);

    return conversion.stringToInt(enteredDate);
}

int Date::enterDate(){

    Conversion conversion;
    string date = "";
    //bool correctDate = false;
    do
    {
        cout << endl << "Enter date (YYYY-MM-DD) :"; cin.sync(); cin.clear();
        getline(cin, date);
    }while(date.length() < 10);\

    date = changeDateSeparatedByDashToNumber(date);

    return conversion.stringToInt(date);
/*
    do
    {
        correctDate = checkDate(date);
        if(correctDate == true)
        {
        }
    }while(correctDate == false);
*/
}

string Date::convertDateFromIntToStringWithDash(int date)
{
    Conversion conversion;
    string newDate = "";
    newDate = conversion.intToString(date);

    newDate.insert(4,"-");
    newDate.insert(7,"-");
    return newDate;
}
