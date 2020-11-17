#include <iostream>
#include <cstdlib>

#include "ManagerUser.h"
#include "HelpfulMethods.h"
#include "ManagerFinanses.h"


using namespace std;

class FinancialResources
{

    ManagerUser managerUser;
    ManagerFinanses managerFinanses;

    public:

    FinancialResources(string nameFileXmlWitchUsers) : managerUser(nameFileXmlWitchUsers) {};
       // ~FinancialResources();
        char selectOptionFromTheMainMenu();
        char selectOptionFromeTheMenuUser();
        void registerUser();
        void singIn();
        void changePasswordLogedUser();
        void singOut();
        bool isUserLoggedIn();
        void addIncome();

};
