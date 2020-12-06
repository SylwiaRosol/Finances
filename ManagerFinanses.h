#ifndef MANAGERFINANSES_H
#define MANAGERFINANSES_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <winbase.h>


#include "HelpfulMethods.h"
#include "Incomes.h"
#include "Expenses.h"
#include "FileXMLWithIncomes.h"
#include "FileXMLWithExpenses.h"
#include "DateCheckingMethods.h"

using namespace std;

class ManagerFinanses {

    Incomes income;
    Expenses expense;
    vector <Incomes> incomes;
    vector <Expenses> expenses;
    FileXmlWithIncomes fileXmlWithIncomes;
    FileXmlWithExpenses fileXmlWithExpenses;
    const int ID_LOGGED_USER;

    string enterTheDate();
    string enterADescription();
    float enterTheAmount();
    void sortVector();
    void showBalance(float amountIncomes, float amountExpenses);


    public:
        ManagerFinanses (string nameFileWithIncomes, string nameFileWithExpenses, int idLoggedUser)
        : fileXmlWithIncomes(nameFileWithIncomes), fileXmlWithExpenses(nameFileWithExpenses), ID_LOGGED_USER(idLoggedUser) {
        incomes = fileXmlWithIncomes.loadIncomesFromFile();
        expenses = fileXmlWithExpenses.loadExpensesFromFile();
        };
        void addIncome();
        void addExpense();

        void showBalanceFromThisMonth();
        void showBalanceFromPreviousMonth();
        void showBalanceFromSelectedTime();

};
#endif
