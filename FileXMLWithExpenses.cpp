#include "FileXmlWithExpenses.h"


void FileXmlWithExpenses::addExpensesToTheFile(Expenses expense) {
    CMarkup xml;
    bool isFileExist = xml.Load(getNameFile());

    if(!isFileExist) {
        xml.AddElem("Expenses");
}
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.AddAttrib("id",expense.getIdUser());
    xml.AddAttrib("idExpense", expense.getIdExpense());
    xml.AddAttrib("date", expense.getDate());
    xml.AddAttrib("category", expense.getCategoryExpense());
    xml.AddAttrib("amount", HelpfulMethods::conversionFloatForString(expense.getAmount()));

    xml.Save(getNameFile());
}


vector <Expenses> FileXmlWithExpenses::loadExpensesFromFile() {
    CMarkup xml;
    vector <Expenses> expenses;
    Expenses expense;

    bool isFileExist = xml.Load(getNameFile());
           if(!isFileExist) {
            return expenses;
        }
        xml.FindElem("Expenses");
        xml.IntoElem();

        while(xml.FindElem("Expense")) {


            expense.setIdUser(HelpfulMethods::conversionStringForInt(xml.GetAttrib("id")));
            expense.setIdExpense(HelpfulMethods::conversionStringForInt(xml.GetAttrib("idExpense")));
            expense.setDate(xml.GetAttrib("date"));
            expense.setCategoryExpense(xml.GetAttrib("category"));
            expense.setAmount(HelpfulMethods::conversionStringForFloat(xml.GetAttrib("amount")));
            expenses.push_back(expense);
        }

        return expenses;
}

int FileXmlWithExpenses::idNewExpense() {
    CMarkup xml;
   int id;
   string text;
    xml.Load(getNameFile());
    xml.FindElem("Expenses");
        xml.IntoElem();

        while(xml.FindElem("Expense")) {

         text = xml.GetAttrib("idExpense");
        }
        id = HelpfulMethods::conversionStringForInt(text);
        return id +1;
}
