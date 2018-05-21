#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include "Income.h"
#include "Markup.h"
#include "User.h"
#include "Date.h"
#include "Conversion.h"
#include "stdlib.h"

#include <iostream>
#include <vector>
#include <string>

class IncomesFile
{
    public:
        IncomesFile();
        virtual ~IncomesFile();

        int loadAllUserIncomes(vector<Income>&incomeVec, int loggedInUserId);
        void addIncomeToFile(Income income);

    private:
        string fileName;
        Conversion conversion;
        Date date;
};
#endif // INCOMESFILE_H
