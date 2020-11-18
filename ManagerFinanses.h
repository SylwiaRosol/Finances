#ifndef MANAGERFINANSES_H
#define MANAGERFINANSES_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <winbase.h>


#include "HelpfulMethods.h"
#include "Incomes.h"


using namespace std;

class ManagerFinanses {

    Incomes income;
    vector <Incomes> incomes;
    const int ID_LOGGED_USER;

    public:
        ManagerFinanses (/*string nameFileWithIncomes,*/ int idLoggedUser) : ID_LOGGED_USER(idLoggedUser) {};
        void addIncome();
        string enterTheDate();
        string enterADescription();
        float enterTheAmount();
        string loadTodayDate();
};
#endif
