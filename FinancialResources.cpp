#include "FinancialResources.h"




char FinancialResources::selectOptionFromTheMainMenu(){

   char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelpfulMethods::loadSign();

    return choice;

}

char FinancialResources::selectOptionFromeTheMenuUser() {

    char choice;

    system("cls");
    cout << "    >>> MENU  UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z bierzacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelpfulMethods::loadSign();
   return choice;
}



void FinancialResources::registerUser(){
    managerUser.registerUser();
}

void FinancialResources::singIn() {
    managerUser.singIn();
    if(managerUser.isUserLoggedIn()){
        managerFinanses = new ManagerFinanses(NAME_FILE_WITH_INCOMES, NAME_FILE_WITH_EXPENSES, managerUser.getIdLoggedUser());
    }
}
void FinancialResources::singOut(){
    managerUser.singOut();
}
void FinancialResources::changePasswordLogedUser(){
    managerUser.changePasswordLogedUser();
}

bool FinancialResources::isUserLoggedIn(){
    managerUser.isUserLoggedIn();
}

void FinancialResources::addIncome() {
    managerFinanses->addIncome();
}

void FinancialResources::addExpense() {
    managerFinanses->addExpense();
}

void FinancialResources::showBilanceWithThisMonth(){
    managerFinanses->showBalanceWithThisMonth();
}
void FinancialResources::showBalanceWithPreviousMonth() {
    managerFinanses->showBalanceWithPreviousMonth();
}
