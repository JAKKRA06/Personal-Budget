#include "PersonalBudget.h"

PersonalBudget::PersonalBudget(int userId)
{
    try
    {
        if(userId <= 0)
        {
            throw 0;
        }
        else
        {
            this->signInUserId = userId;
            incomes = new Incomes(userId);
            expenses = new Expenses(userId);
        }
    }
    catch(int incorrectUserId)
    {
        cout << endl << "Incorrect user ID. You're not logged in!" << endl << endl;
        system("pause");
        exit(0);
    }
}

PersonalBudget::~PersonalBudget(){;}

void PersonalBudget::addIncome(){

    incomes->addIncome();
}

void PersonalBudget::addExpense(){

        expenses->addExpense();
}

void PersonalBudget::currentMonthBalance(){

    ;

}

void PersonalBudget::selectedPeroidBalance(){

    system("cls");

    string startDate = ""; string lastDate = "";
    float sumOfIncomes = 0.0f;
    float sumOfExpenses = 0.0f;
    vector<Income> selectedIncomes;
    vector<Expense> selectedExpenses;
    int startDateNumber = 0; int lastDateNumber = 0;
    Conversion conversion;
    Date date;

    cout << "------------------------------------------------------" << endl;
    cout << "          >>> SELECTED PEROID BALANCE <<< " << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Select peroid of time(YYYY-MM-DD)"; cin.sync(); cin.clear();
    cout << endl << "From: "; getline(cin, startDate); cin.sync(); cin.clear();
    cout << "To: "; getline(cin, lastDate);

    startDateNumber = date.convertDateFromStringWithDashToInt(startDate);
    lastDateNumber = date.convertDateFromStringWithDashToInt(lastDate);


    selectedIncomes = incomes->getIncomesFromSelectedPeroid(startDateNumber, lastDateNumber);
    selectedExpenses = expenses->getExpenseFromSelectedPeroid(startDateNumber, lastDateNumber);

    cout << endl << "Incomes of selected peroid:  " << endl;
    incomes->showSelectedIncomes(selectedIncomes);
    cout << endl << "Expenses of selected peroid: " << endl;
    expenses->showSelectedExpenses(selectedExpenses);
    cout << endl;

    sumOfIncomes = incomes->getIncomesSum(selectedIncomes);
    sumOfExpenses = expenses->getExpensesSum(selectedExpenses);

    cout << "Total incomes of selected peroid:   " << sumOfIncomes << endl;
    cout << "Total expenses of selected peroid:  " << sumOfExpenses << endl;
    cout << "Saving/Debt:                        " << sumOfIncomes-sumOfExpenses << endl;
    system("pause");
}










