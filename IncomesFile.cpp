#include "IncomesFile.h"

IncomesFile::IncomesFile(){

    this->fileName = "incomes.xml";

}

IncomesFile::~IncomesFile(){;}

void IncomesFile::addIncomeToFile(Income income){

    CMarkup incomeXML;
    incomeXML.Load(fileName);

    if(!incomeXML.FindElem("INCOMES")) {

        incomeXML.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        incomeXML.AddElem("INCOMES");
    }
    incomeXML.IntoElem();
    incomeXML.AddElem("INCOME");
    incomeXML.IntoElem();
    incomeXML.AddElem("INCOMEID", conversion.intToString(income.getIncomeId()));
    incomeXML.AddElem("USERID", conversion.intToString(income.getUserId()));
    incomeXML.AddElem("DATE", date.convertDateFromIntToStringWithDash(income.getDate()));
    incomeXML.AddElem("ITEM", income.getItem());
    incomeXML.AddElem("AMOUNT", conversion.doubleToString(income.getAmount()));
    incomeXML.OutOfElem();

    incomeXML.Save(fileName);
}

int IncomesFile::loadAllUserIncomes(vector<Income>&incomeVec, int loggedInUserId){

    CMarkup xmlFile;
    Income income;
    int lastIncomeIdInFile = 0;

    if(xmlFile.Load(fileName))
    {
        if(xmlFile.FindElem("INCOMES"))
        {
            xmlFile.IntoElem();

            while(xmlFile.FindElem("INCOME"))
            {
                xmlFile.IntoElem();
                xmlFile.FindElem("INCOMEID");
                income.setIncomeId(atoi(xmlFile.GetData().c_str()));
                lastIncomeIdInFile = income.getIncomeId();

                xmlFile.FindElem("USERID");

                if(conversion.intToString(loggedInUserId) == xmlFile.GetData())
                {
                    xmlFile.FindElem("USERID");
                    income.setUserId(atoi(xmlFile.GetData().c_str()));

                    xmlFile.FindElem("DATE");
                    income.setDate(xmlFile.GetData());

                    xmlFile.FindElem("ITEM");
                    income.setItem(xmlFile.GetData());

                    xmlFile.FindElem("AMOUNT");
                    income.setAmount(atof(xmlFile.GetData().c_str()));

                    incomeVec.push_back(income);
                }
                xmlFile.OutOfElem();
            }
        }
    }
    return lastIncomeIdInFile;
}

