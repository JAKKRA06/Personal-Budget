#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "IncomesFile.h"
#include "Income.h"
#include "Date.h"

using namespace std;

class Incomes
{
    public:
        Incomes(int loggedInUserId);
        virtual ~Incomes();

        void addIncome();
        vector<Income>getIncomesFromSelectedPeroid(int stardDate, int lastDate);
        void showSelectedIncomes(vector<Income> &selectedIncomes);
        float getIncomesSum(vector<Income> &selectedIncomes);

    private:
        int lastIncomeId;
        int loggedInUserId;
        vector<Income>incomeVec;
        Date date;
        IncomesFile incomesFile;

        Income enterIncomeData();
        void sortIncomesByDateInAscendingOrder(vector<Income> &selectedIncomes);
};
#endif // INCOMES_H
