#include "FileXmlWithIncomes.h"


void FileXmlWithIncomes::addIncomesToTheFile (Incomes income) {
    CMarkup xml;
    bool isFileExist = xml.Load(getNameFile());

    if(!isFileExist) {
        xml.AddElem("Incomes");
}
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.AddAttrib("id",income.getIdUser());
    xml.AddAttrib("idIncome", income.getIdIncomes());
    xml.AddAttrib("date", income.getDate());
    xml.AddAttrib("category", income.getCategoryIncomes());
    xml.AddAttrib("amount", HelpfulMethods::conversionFloatForString(income.getAmount()));

    xml.Save(getNameFile());
}


vector <Incomes> FileXmlWithIncomes::loadIncomesFromFile() {
    CMarkup xml;
    vector <Incomes> incomes;
    Incomes income;

    bool isFileExist = xml.Load(getNameFile());
           if(!isFileExist) {
            return incomes;
        }
        xml.FindElem("Incomes");
        xml.IntoElem();

        while(xml.FindElem("Income")) {

            income.setIdUser(HelpfulMethods::conversionStringForInt(xml.GetAttrib("id")));
            income.setIdIncome(HelpfulMethods::conversionStringForInt(xml.GetAttrib("idIncome")));
            income.setDate(xml.GetAttrib("date"));
            income.setCategoryIncome(xml.GetAttrib("category"));
            income.setAmount(HelpfulMethods::conversionStringForFloat(xml.GetAttrib("amount")));
            income.setDateInt(DateCheckingMethods::changeDate(xml.GetAttrib("date")));
            incomes.push_back(income);
        }

        return incomes;
}

int FileXmlWithIncomes::idNewIncomes() {
    CMarkup xml;
   int id;
   string text;
    bool isFileExist = xml.Load(getNameFile());
           if(!isFileExist) {
            return 1;
        }

    xml.FindElem("Incomes");
        xml.IntoElem();

        while(xml.FindElem("Income")) {

         text = xml.GetAttrib("idIncome");
        }
        id = HelpfulMethods::conversionStringForInt(text);
        return id +1;
}
