#include "Expenses.h"

Expenses::Expenses(int loggedInUserId){

    ExpensesFile expensesFile;

    try
    {
        if(loggedInUserId <= 0)
        {
            throw 0;
        }
        else
        {
            this->loggedInUserId = loggedInUserId;
            this->lastExpenseId = expensesFile.loadAllExpensesFromFile(expenseVec, loggedInUserId);
        }
    }
    catch(int incorrectUserId)
    {
        cout << endl << "Incorrect user ID. You're not logged in!" << endl << endl;
        system("pause");
        exit(0);
    }
}

Expenses::~Expenses(){

    expenseVec.clear();
}

void Expenses::addExpense(){

    Expense expense;
    system("cls");
    string currentSystemDate = "";

    cout << "------------------------------------------------------" << endl;
    cout << "          >>> ADD NEW EXPENSE <<< " << endl;
    cout << "------------------------------------------------------" << endl;

    expense = enterExpenseData();

    expenseVec.push_back(expense);
    expensesFile.addExpenseToFile(expense);

    cout << endl << "Expense has been added." << endl;
    system("pause");
}

vector<Expense> Expenses::getExpenseFromSelectedPeroid(int startDate, int lastDate){

    vector<Expense> selectedExpenses;
    if(!expenseVec.empty())
    {
        for(vector<Expense>::iterator itr = expenseVec.begin(); itr != expenseVec.end(); itr++)
        {
            if(itr -> Expense::getDate() >= startDate && itr -> Expense::getDate() <= lastDate)
            {
                selectedExpenses.push_back(*itr);
            }
        }
    }
    return selectedExpenses;
}

void Expenses::showSelectedExpenses(vector<Expense> &selectedExpenses){

    if(!selectedExpenses.empty())
    {
        sortExpensesByDateInAscendingOrder(selectedExpenses);

        for(vector<Expense>::iterator itr = selectedExpenses.begin(); itr != selectedExpenses.end(); itr++)
        {
            cout << "Date:          " << date.convertDateFromIntToStringWithDash(itr -> Expense::getDate()) << endl;
            cout << "Item:          " << itr -> Expense::getItem() << endl;
            cout << "Amount:        " << itr -> Expense::getAmount() << endl;
            cout << "---------------------------" << endl;

        }

    }
    else
        cout << endl << "You have no incomes in the selected peroid." << endl;
}

float Expenses::getExpensesSum(vector<Expense> &selectedExpenses){

    float sum = 0.0f;

    for(vector<Expense>::iterator itr = selectedExpenses.begin(); itr != selectedExpenses.end(); itr++)
    {
        sum += itr -> Expense::getAmount();
    }
    return sum;
}

Expense Expenses::enterExpenseData(){

    Expense expense;

    expense.setExpenseId(++lastExpenseId);
    expense.setUserId(loggedInUserId);
    expense.enterDate();
    expense.enterItem();
    expense.enterAmount();

    return expense;
}

void Expenses::sortExpensesByDateInAscendingOrder(vector<Expense> &selectedExpenses){

    sort(selectedExpenses.begin(), selectedExpenses.end(), [](Expense& firstExpense, Expense& secondExpense)
    {
        return firstExpense.getDate() < secondExpense.getDate();
    });
}

