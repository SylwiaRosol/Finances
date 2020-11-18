#include <iostream>
#include <vector>
#include <cstdlib>

#include "FinancialResources.h"


using namespace std;

int main()
{
    char choice, choice2;
    FinancialResources financialResources ("users.xml", "incomes.xml");

    while(1) {
        choice = financialResources.selectOptionFromTheMainMenu();


        if(choice == '1') {
            financialResources.registerUser();
        }

        else if(choice == '2') {
            financialResources.singIn();
            while(financialResources.isUserLoggedIn()) {
                choice2 = financialResources.selectOptionFromeTheMenuUser();
                if(choice2 = '4') {
                 financialResources.addIncome();
                }

            }
        }

        else if (choice = '9') {
        exit(0);
         }
    }
        return 0;
}
