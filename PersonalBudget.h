#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

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
        void perviousMonthBalance();
        void selectedPeroidBalance();
        void showBalance(int startDate, int lastDate);

    private:
        int signInUserId;
        IncomesFile incomeFile;
        Incomes *incomes;
        Expenses *expenses;
        Date date;
};
#endif // PERSONALBUDGET_H
