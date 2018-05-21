#ifndef EXPENSE_H
#define EXPENSE_H

#include <algorithm>
#include <iostream>
#include "Date.h"
#include "Amount.h"

using namespace std;

class Expense
{
    public:
        Expense();
        virtual ~Expense();

        int getExpenseId();
        int getUserId();
        int getDate();
        string getItem();
        double getAmount();

        void setExpenseId(int expenseId);
        void setUserId(int userId);
        void setDate(string enteredDate);
        void setItem(string item);
        void setAmount(double amount);

        void enterDate();
        void enterItem();
        void enterAmount();

    private:
        int expenseId;
        int userId;
        int date;
        string item;
        double amount;
};

#endif // EXPENSE_H
