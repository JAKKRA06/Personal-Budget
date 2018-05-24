#include "Amount.h"

Amount::Amount(){;}

Amount::~Amount(){;}

string Amount::changeCommaToDot(string amount){

    for(int counter = 0; counter < amount.length(); counter++) {

        if(amount[counter] == 44) {
            amount[counter] = 46;
            return amount;
        }
    }
}

double Amount::enterAmount(){

    string amount = "";
    Conversion conversion;
    do
     {
        cout << endl << "Enter amount: "; cin.sync(); cin.clear();
        getline(cin,amount);
        if(conversion.stringToInt(amount) <= 0)
        {
            cout << "Entered amount should be greater or equal 0. Please try again." << endl;
        }
     }while(conversion.stringToInt(amount) <= 0);

    if(isThereComma(amount) == true)
    {
        amount = changeCommaToDot(amount);
    }
    return atof(amount.c_str());
}

bool Amount::isThereComma(string amount){

    for(int counter = 0; counter < amount.length(); counter++)
    {
        if(amount[counter] == 44)
            return true;
    }
}
