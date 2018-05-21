#include "Date.h"

Date::Date() {

    this->userFile = "users.xml";
}

Date::~Date() {;}

void Date::showNumberOfDaysOfTheMonth() {

    time_t now = time(NULL);
    tm *ltm = localtime(&now);

    map<string, int> month;
    month ["January"] = 31;
    month ["Fabruary"] = 28;
    month ["March"] = 31;
    month ["April"] = 30;
    month ["May"] = 31;
    month ["June"] = 30;
    month ["July"] = 31;
    month ["August"] = 31;
    month ["September"] = 30;
    month ["October"] = 31;
    month ["November"] = 30;
    month ["December"] = 31;

    cout << "Enter month name: ";
    cin >> monthUSer;
    if(monthUSer != "February") {
        cout << "Number of days of the month: " << monthUSer << " " << month[monthUSer] << " days"<< endl;
    } else {
        cout << "Get a year: ";
        cin >> year;
        if(year > 1900 + ltm->tm_year) {
            if((year%4 == 0 && year%100 != 0) || year%400 == 0)
                cout<< endl << "Year "<< year <<" will be bissextile so february will has 29 days" << endl;
            else
                cout<< endl << "Year "<< year <<" will not be bissextile so february will has 28 days" << endl;
        } else {
            if((year%4 == 0 && year%100 != 0) || year%400 == 0)
                cout<< endl << "Year "<< year <<" was bissextile so february had 29 days" << endl;
            else
                cout<< endl << "Year "<< year <<" was not bissextile so february had 28 days" << endl;
        }
    }
}

void Date::showCurrentDate() {

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

    time_t now = time(NULL);

    tm *ltm = localtime(&now);
    cout << "Current date: " << 1900 + ltm->tm_year << ":" << 1 + ltm->tm_mon << ":" << ltm->tm_mday << endl;
    cout << "Current month has " << month[1+ltm->tm_mon] << " days" <<  endl;
}

void Date::comparingDate() {

// w tej metodzie i w metodzie wczytaj date jeszcze kombinuje w jaki sposob porownywa te daty i nie sa do konca skuteczne narazie
    string date = "2018-03-04";
    string dateInput = "";
    int number = 0;
    int number1 = 0;
    int number2 = 0;
    cout << "Input date of expense(YYYY-MM-DD): ";
    cin >> dateInput;
    int lengthDate = dateInput.length();

    for(int counter = 0; counter != lengthDate; counter++) {
        if(dateInput[counter] > date[counter])
        {
            number++;
        }
        else if(dateInput[counter] == date[counter])
        {
            number1++;
        }

        else
        {
            number2++;
        }
    }
/*
    if(year2 > year)
        cout << "Expense first was earlier" << endl;
    else if(year2 < year)
        cout << "Expense firs was later" << endl;
    else if(year2 == year) {
        if(month2 > month)
            cout << "Expense firs was earlier" << endl;
        else if(month2 < month)
            cout << "Expesne first was later" << endl;
        else if(month2 == month) {
            if(day2 > day)
                cout << "Expense first was earlier" << endl;
            else if(day2 < day)
                cout << "Expense first was later" << endl;
            else if(day2 == day)
                cout << "Expense first was the same day that expense second" << endl;
        }
    }
*/
}
void Date::writeToFileXML() {

    int userId = 1;
    int numberOfUser = 1;
    string amount = "";
    string item = "";
    string date = "";

    cout << "Enter expense: (item) ";
    cin.sync();
    getline(cin, item);
    cout << "Enter expense: (amount) ";
    cin >> amount;
    cout << "Enter date of expense(YYYY-MM-DD): ";
    cin.sync();
    getline(cin, date);

    amount = changeCommaToDot(amount);

    expenses.Load(userFile);

    if(!expenses.FindElem("EXPENSES")) {
        expenses.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        expenses.AddElem("EXPENSES");
    }
    expenses.IntoElem();
    expenses.AddElem("EXPENSE");
    expenses.IntoElem();
    expenses.AddElem("INCOMEID", numberOfUser);
    expenses.AddElem("USERID", userId);
    expenses.AddElem("DATE", date);
    expenses.AddElem("ITEM", item);
    expenses.AddElem("AMOUNT", amount);
    expenses.OutOfElem();

    expenses.Save(userFile);

    int lastIdUser = 0;
    cout << lastIdUser << endl;
    system("pause");

}
string Date::changeCommaToDot(string amount) {

    for(int counter = 0; counter < amount.length(); counter++) {
        if(amount[counter] == 44) {
            amount[counter] = 46;
            return amount;
        }
    }
}

void Date::findDateInFileXml() {

    MCD_STR strxml = "";
    expenses.Load(userFile);
    bool bwell = expenses.IsWellFormed();
    cout << bwell<< endl;
    system("pause");

    strxml = expenses.GetDoc();
    cout << strxml<< endl;


    expenses.FindElem();
    expenses.IntoElem();

    while(expenses.FindElem("userId")) {
        expenses.IntoElem();
        expenses.FindElem("date");
        strxml = expenses.GetData();
        cout << strxml << endl;
    }

    expenses.ResetPos();
    expenses.FindElem();
    expenses.IntoElem();

    for(int numberOfUser = 1; numberOfUser < 4; ) {

        while(expenses.FindElem("userId")) {
            expenses.FindChildElem("amount");
            //if(expenses.GetChildData() == znalezionaWyplata) {
            // cout << "znaleziono wyplate o wysokosci: " << znalezionaWyplata << " w przychodach o id " << numberOfUser<< endl;
            //} else
            //    numberOfUser++;
        }
        numberOfUser++;
    }
}



void Date::wczytajDate() {

    string wczytanaLinia = "";
    vector<string>Daty;
    string date;
    cin >> wczytanaLinia;

    rozdzielanieDat(wczytanaLinia, '-');
}
void Date::rozdzielanieDat(string wczytanaLinia, char znak) {

    int numerPojedynczejDanej = 1;
    stringstream ss(wczytanaLinia);
    string rok = "";
    string miesiac = "";
    string dzien = "";
    string pojedynczaDana = "";

    cout << wczytanaLinia << endl;
    system("pause");

    while(getline(ss, pojedynczaDana, znak)) {

        switch(numerPojedynczejDanej) {
        case 1:
            rok = pojedynczaDana;
            break;
        case 2:
            miesiac = pojedynczaDana;
            break;
        case 3:
            dzien = pojedynczaDana;
            break;
        }
        numerPojedynczejDanej++;
        pojedynczaDana = "";
    }
cout << rok << endl;
cout << miesiac << endl;
cout << dzien << endl;
}
