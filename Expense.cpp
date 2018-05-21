#include "Expense.h"

Expense::Expense(){

    expenseId = 0;
    userId = 0;
    date = 0;
    item = "";
    amount = 0.0f;
}

Expense::~Expense(){;}

int Expense::getExpenseId(){

    return expenseId;
}

int Expense::getUserId(){

    return userId;
}

int Expense::getDate(){

    return date;
}

string Expense::getItem(){

    return item;
}

double Expense::getAmount(){

    return amount;
}


void Expense::setExpenseId(int expenseId){

    this->expenseId = expenseId;
}

void Expense::setUserId(int userId){

    this->userId = userId;
}

void Expense::setDate(string enteredDate){

    Date date;
    this->date = date.convertDateFromStringWithDashToInt(enteredDate);
}

void Expense::setItem(string item){

    this->item = item;
}

void Expense::setAmount(double amount){

    this->amount = amount;
}


void Expense::enterDate(){

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

void Expense::enterItem(){

     string item = "";
     do
     {
         cout << endl << "Enter your item: "; cin.sync(); cin.clear();
         getline(cin, item);
     }while(item == "");

     this->item = item;
}

void Expense::enterAmount(){

    Amount amount;
    this->amount = amount.enterAmount();
}

