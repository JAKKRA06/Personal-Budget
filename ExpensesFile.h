#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include <string>

#include "Expense.h"
#include "Markup.h"
#include "Date.h"
#include "Conversion.h"
#include "stdlib.h"

using namespace std;

class ExpensesFile
{
    public:
        ExpensesFile();
        virtual ~ExpensesFile();

        int loadAllExpensesFromFile(vector<Expense> &expenseVec, int loggedInUserId);
        void addExpenseToFile(Expense expense);

    private:
        string fileName;
        Date date;
        Conversion conversion;
};

#endif // EXPENSESFILE_H
