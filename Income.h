#ifndef INCOME_H
#define INCOME_H

#include <algorithm>
#include <iostream>

#include "Date.h"
#include "Amount.h"

class Income
{
    public:
        Income();
        virtual ~Income();

        void setIncomeId(int incomeId);
        void setUserId(int uesId);
        void setDate(string enteredDate);
        void setItem(string item);
        void setAmount(double amount);

        int getIncomeId();
        int getUserId();
        int getDate();
        string getItem();
        double getAmount();

        void enterDate();
        void enterItem();
        void enterAmount();

    private:
        int incomeId;
        int userId;
        int date;
        string item ;
        double amount;
};
#endif // INCOME_H
