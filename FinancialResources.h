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

    public:

    FinancialResources(string nameFileXmlWithUsers, string nameFileXmlWithIncomes)
    : managerUser(nameFileXmlWithUsers), NAME_FILE_WITH_INCOMES(nameFileXmlWithIncomes) {
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

};
