#include "Income.h"

Income::Income(){

    incomeId = 0;
    userId = 0;
    date = 0;
    item = "";
    amount = 0.0f;
}

Income::~Income(){;}

void Income::setIncomeId(int incomeId)
{
    this->incomeId = incomeId;
}

void Income::setUserId(int userId)
{
    this->userId = userId;
}

void Income::setDate(string enteredDate)
{
    Date date;
    this->date = date.convertDateFromStringWithDashToInt(enteredDate);
}

void Income::setItem(string item)
{
    this->item = item;
}

void Income::setAmount(double amount){

    this->amount = amount;
}


int Income::getIncomeId(){

    return incomeId;
}
int Income::getUserId(){

    return userId;
}

string Income::getItem(){

    return item;
}

double Income::getAmount(){

   return amount;
}

int Income::getDate(){

    return date;
}

void Income::enterDate(){

    char choice;
    Date date;

    do
    {
        cout << endl << "SET DATE" << endl;
        cout << "1 - Current date: " << endl;
        cout << "2 - Another date: " << endl;
        cout << "Your choice: "; cin >> choice; cin.ignore();

        if(choice == '1')
            this->date = date.getCurrentDate();
        else if(choice == '2')
            this->date = date.enterDate();
    }while(choice != '1' && choice != '2');
}

void Income::enterItem(){

     string item = "";
     do
     {
         cout << "Enter your item: "; cin.sync(); cin.clear();
         getline(cin, item);
     }while(item == "");

     this->item = item;
}

void Income::enterAmount(){

   Amount amount;
   this->amount = amount.enterAmount();
}
