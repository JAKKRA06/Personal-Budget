#include "PersonalBudget.h"

PersonalBudget::PersonalBudget(int userId){

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

PersonalBudget::~PersonalBudget(){

    delete incomes;
    delete expenses;
}

void PersonalBudget::addIncome(){

    incomes->addIncome();
}

void PersonalBudget::addExpense(){

    expenses->addExpense();
}

void PersonalBudget::currentMonthBalance(){


    int startDate = 0; int lastDate = 0; int numberOfDaysOfTheCurrentMonth = 0;

    startDate = date.getFirstDateInMonth(date.getCurrentYear(), date.getCurrentMonth());
    lastDate = date.getLastDateInMonth(date.getCurrentYear(), date.getCurrentMonth());

    system("cls");

    cout << "------------------------------------------------------" << endl;
    cout << "          >>> CURRENT MONTH BALANCE <<< " << endl;
    cout << "------------------------------------------------------" << endl;

    showBalance(startDate, lastDate);
}

void PersonalBudget::perviousMonthBalance(){

    int year = date.getCurrentYear();
    int month = date.getCurrentMonth();

    if(month == 1)
    {
        year--;
        month = 12;
    }
    else
        month --;

    int startDate = date.getFirstDateInMonth(year, month);
    int lastdate = date.getLastDateInMonth(year, month);

    system("cls");

    cout << "------------------------------------------------------" << endl;
    cout << "          >>> BALANCE FROM PREVIOUS MONTH <<< " << endl;
    cout << "------------------------------------------------------" << endl;

    showBalance(startDate, lastdate);
}

void PersonalBudget::selectedPeroidBalance(){

    system("cls");
    Conversion conversion;
    Date date;
    int startDate = 0; int lastDate = 0;
    bool isStartDateGreaterThanLastDate = false;

    cout << "------------------------------------------------------" << endl;
    cout << "          >>> BALANCE FROM SELECTED PEROID <<< " << endl;
    cout << "------------------------------------------------------" << endl;

    do
     {
        cout << "----------START DATE----------" << endl;
        startDate = date.enterDate();
        cout << "----------LAST DATE-----------" << endl;
        lastDate = date.enterDate();

        if(startDate > lastDate)
        {
            isStartDateGreaterThanLastDate = true;
            cout << endl << "Last date must be greater or equal than start date!" << endl;
            cout << endl << "Please try again." << endl;
        }
        else
            isStartDateGreaterThanLastDate = false;
    }while(isStartDateGreaterThanLastDate == true);

    showBalance(startDate, lastDate);
}

void PersonalBudget::showBalance(int startDate, int lastDate){

    double sumOfIncomes = 0.0d;
    double sumOfExpenses = 0.0d;
    vector<Income> selectedIncomes;
    vector<Expense> selectedExpenses;

    selectedIncomes = incomes->getIncomesFromSelectedPeroid(startDate, lastDate);
    selectedExpenses = expenses->getExpenseFromSelectedPeroid(startDate, lastDate);

    sumOfIncomes = incomes->getIncomesSum(selectedIncomes);
    sumOfExpenses = expenses->getExpensesSum(selectedExpenses);

    cout << endl << "          >>>INCOMES<<<          " << endl;
    cout << "---------------------------------" << endl;
    incomes->showSelectedIncomes(selectedIncomes);

    cout << endl << "          >>>EXPENSES<<<          " << endl;
    cout << "----------------------------------" << endl;
    expenses->showSelectedExpenses(selectedExpenses);
    cout << endl;

    cout << "Total incomes of selected peroid:   " << fixed << setprecision(2) << sumOfIncomes << endl;
    cout << "Total expenses of selected peroid:  " << fixed << setprecision(2) << sumOfExpenses << endl;
    cout << "Saving/Debt:                        " << fixed << setprecision(2) << sumOfIncomes-sumOfExpenses << endl;
    system("pause");
}









