#include <iostream>
#include <vector>
#include <cstdlib>

#include "FinancialResources.h"

using namespace std;

int main()
{
    char choice;
    FinancialResources financialResources;

    while(1) {
        choice = financialResources.selectOptionFromTheMainMenu();


        if(choice == '1') {
            financialResources.registerUser();
        }

        else if(choice == '2') {
            financialResources.singIn();
        }

        else if (choice = '9') {
        exit(0);
         }
    }
    return 0;
}
