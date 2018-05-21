#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>

#include "IncomesFile.h"
#include "Incomes.h"
#include "Expenses.h"
#include "ExpensesFile.h"
#include "Date.h"

using namespace std;

class PersonalBudget
{
    public:
        PersonalBudget(int userId);
        virtual ~PersonalBudget();
        void addIncome();
        void addExpense();
        void currentMonthBalance();
        void selectedPeroidBalance();

    private:
        int signInUserId;
        IncomesFile incomeFile;
        Incomes *incomes;
        Expenses *expenses;
};
#endif // PERSONALBUDGET_H
