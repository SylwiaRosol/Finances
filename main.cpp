#include <iostream>
#include <vector>
#include <cstdlib>

#include "FinancialResources.h"


using namespace std;

int main()
{
    char choice, secondChoice = '0';
    FinancialResources financialResources ("users.xml", "incomes.xml", "expenses.xml");

    while(1) {
        choice = financialResources.selectOptionFromTheMainMenu();


        if(choice == '1') {
            financialResources.registerUser();
        }

        else if(choice == '2') {
            financialResources.singIn();
            while(financialResources.isUserLoggedIn()) {
                secondChoice = financialResources.selectOptionFromeTheMenuUser();
                if(secondChoice == '1') {
                 financialResources.addIncome();
                }   else if( secondChoice == '2') {
                    //dodaj wydatek
                }   else if( secondChoice == '3') {
                    //bilans z miesiaca
                }   else if( secondChoice == '4') {
                    //bilans z poprzedniego miesiaza
                }   else if( secondChoice == '5') {
                    //bilans wybrany
                }   else if( secondChoice == '6') {
                    financialResources.changePasswordLogedUser();
                }   else if( secondChoice == '7') {
                    financialResources.singOut();
                }

            }
        }

        else if (choice = '9') {
        exit(0);
         }
    }
        return 0;
}
