#include <iostream>
#include <cstdlib>

#include "ManagerUser.h"
#include "HelpfulMethods.h"
#include "ManagerFinanses.h"


using namespace std;

class FinancialResources
{

    ManagerUser managerUser;
    ManagerFinanses *managerFinanses;
    const string NAME_FILE_WITH_INCOMES;
    const string NAME_FILE_WITH_EXPENSES;
    public:

    FinancialResources(string nameFileXmlWithUsers, string nameFileXmlWithIncomes, string nameFileXmlWithExpenses)
    : managerUser(nameFileXmlWithUsers), NAME_FILE_WITH_INCOMES(nameFileXmlWithIncomes), NAME_FILE_WITH_EXPENSES(nameFileXmlWithExpenses) {
        managerFinanses = NULL;
    };
        ~FinancialResources() {
        delete managerFinanses;
        managerFinanses = NULL;
    };
        char selectOptionFromTheMainMenu();
        char selectOptionFromeTheMenuUser();

        void registerUser();
        void singIn();
        void changePasswordLogedUser();
        void singOut();
        bool isUserLoggedIn();

        void addIncome();
        void addExpense();

        void showBilanceWithThisMonth();
        void showBalanceWithPreviousMonth();
};
