#include "Incomes.h"

Incomes::Incomes(int loggedInUserId){

    IncomesFile incomesFile;

    try
    {
        if(loggedInUserId <= 0)
        {
            throw 0;
        }
        else
        {
            this->loggedInUserId = loggedInUserId;
            this->lastIncomeId = incomesFile.loadAllUserIncomes(incomeVec, loggedInUserId);
        }
    }
    catch(int incorrectUserId)
    {
        cout << endl << "Incorrect user ID. You're not logged in!" << endl << endl;
        system("pause");
        exit(0);
    }

}

Incomes::~Incomes(){

    incomeVec.clear();
}

void Incomes::addIncome(){

    system("cls");

    Income income;
    string currentSystemDate = "";

    cout << "------------------------------------------------------" << endl;
    cout << "          >>> ADD NEW INCOME <<< " << endl;
    cout << "------------------------------------------------------" << endl;


    income = enterIncomeData();

    incomeVec.push_back(income);
    incomesFile.addIncomeToFile(income);

    cout << "Income has been added." << endl << endl;
    system("pause");

}

vector<Income> Incomes::getIncomesFromSelectedPeroid(int startDate, int lastDate)
{
    vector<Income> selectedIncomes;

    if(!incomeVec.empty())
    {
        for(vector<Income>::iterator itr = incomeVec.begin(); itr != incomeVec.end(); itr++)
        {
            if(itr->Income::getDate() >= startDate && itr->Income::getDate() <= lastDate)
            {
                selectedIncomes.push_back(*itr);
            }
        }
    }
    return selectedIncomes;
}

void Incomes::showSelectedIncomes(vector<Income> &selectedIncomes)
{
    if(!selectedIncomes.empty())
    {
        sortIncomesByDateInAscendingOrder(selectedIncomes);

        for(vector<Income>::iterator itr = selectedIncomes.begin(); itr != selectedIncomes.end(); itr++)
        {
            cout << "Date:          " << date.convertDateFromIntToStringWithDash(itr -> Income::getDate()) << endl;
            cout << "Item:          " << itr -> Income::getItem() << endl;
            cout << "Amount:        " << itr -> Income::getAmount() << endl;
            cout << "---------------------------" << endl;
        }

    }
    else
        cout << endl << "You have no incomes in the selected peroid." << endl;
}

float Incomes::getIncomesSum(vector<Income> &selectedIncomes)
{
    float sum = 0.0f;
    for(vector<Income>::iterator itr = selectedIncomes.begin(); itr != selectedIncomes.end(); itr++)
    {
        sum += itr -> Income::getAmount();
    }
    return sum;
}
Income Incomes::enterIncomeData(){

    Income income;

    income.setIncomeId(++lastIncomeId);
    income.setUserId(loggedInUserId);
    income.enterDate();
    income.enterItem();
    income.enterAmount();

    return income;
}

void Incomes::sortIncomesByDateInAscendingOrder(vector<Income> &selectedIncomes)
{
    sort(selectedIncomes.begin(), selectedIncomes.end(), [](Income& firstIncome, Income& secondIncome)
    {
        return firstIncome.getDate() < secondIncome.getDate();
    });

}
