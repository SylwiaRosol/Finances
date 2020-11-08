#include <iostream>

#include "ManagerUser.h"


using namespace std;

class FinancialResources
{

    ManagerUser managerUser;

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

};
