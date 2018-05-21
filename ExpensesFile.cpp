#include "ExpensesFile.h"

ExpensesFile::ExpensesFile(){

    this->fileName = "expense.xml";
}

ExpensesFile::~ExpensesFile(){;}

void ExpensesFile::addExpenseToFile(Expense expense){

    CMarkup expenseXML;
    expenseXML.Load(fileName);

    if(!expenseXML.FindElem("EXPENSES")) {

        expenseXML.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        expenseXML.AddElem("EXPENSES");
    }
    expenseXML.IntoElem();
    expenseXML.AddElem("EXPENSE");
    expenseXML.IntoElem();
    expenseXML.AddElem("EXPENSEID", conversion.intToString(expense.getExpenseId()));
    expenseXML.AddElem("USERID", conversion.intToString(expense.getUserId()));
    expenseXML.AddElem("DATE", date.convertDateFromIntToStringWithDash(expense.getDate()));
    expenseXML.AddElem("ITEM", expense.getItem());
    expenseXML.AddElem("AMOUNT", conversion.doubleToString(expense.getAmount()));
    expenseXML.OutOfElem();

    expenseXML.Save(fileName);
}

int ExpensesFile::loadAllExpensesFromFile(vector<Expense>&expenseVec, int loggedInUserId){

    CMarkup xmlFile;
    Expense expense;
    int lastExpenseIdInFile = 0;

    if(xmlFile.Load(fileName))
    {
        if(xmlFile.FindElem("EXPENSES"))
        {
            xmlFile.IntoElem();

            while(xmlFile.FindElem("EXPENSE"))
            {
                xmlFile.IntoElem();
                xmlFile.FindElem("EXPENSEID");
                expense.setExpenseId(atoi(xmlFile.GetData().c_str()));
                lastExpenseIdInFile = expense.getExpenseId();

                xmlFile.FindElem("USERID");

                if(conversion.intToString(loggedInUserId) == xmlFile.GetData())
                {
                    xmlFile.FindElem("USERID");
                    expense.setUserId(atoi(xmlFile.GetData().c_str()));

                    xmlFile.FindElem("DATE");
                    expense.setDate(xmlFile.GetData());

                    xmlFile.FindElem("ITEM");
                    expense.setItem(xmlFile.GetData());

                    xmlFile.FindElem("AMOUNT");
                    expense.setAmount(atof(xmlFile.GetData().c_str()));

                    expenseVec.push_back(expense);
                }
                xmlFile.OutOfElem();
            }
        }
    }
    return lastExpenseIdInFile;
}
