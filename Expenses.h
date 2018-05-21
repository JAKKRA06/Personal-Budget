#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>
#include <vector>

#include "Date.h"
#include "Expense.h"
#include "ExpensesFile.h"

using namespace std;

class Expenses
{
    public:
        Expenses(int loggedInUserId);
        virtual ~Expenses();

        void addExpense();
        vector<Expense> getExpenseFromSelectedPeroid(int stardDate, int lastDate);
        void showSelectedExpenses(vector<Expense> &selectedExpenses);
        float getExpensesSum(vector<Expense> &selectedExpenses);

    private:
        vector<Expense>expenseVec;
        int loggedInUserId;
        Date date;
        ExpensesFile expensesFile;
        int lastExpenseId;

        Expense enterExpenseData();
        void sortExpensesByDateInAscendingOrder(vector<Expense> &selectedExpenses);
};

#endif // EXPENSES_H

