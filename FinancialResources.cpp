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
    cout << "4. Dodaj przychod" << endl;
    cout << "5. Dodaj wydatek" << endl;
    cout << "6. Bilans z bierzacego miesiaca" << endl;
    cout << "7. Bilans z poprzedniego miesiaca" << endl;
    cout << "8. Bilans z wybranego okresu" << endl;
    cout << "9. Zmien haslo" << endl;
    cout << "10. Wyloguj sie" << endl;
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
}

bool FinancialResources::isUserLoggedIn(){
    managerUser.isUserLoggedIn();
}
void FinancialResources::addIncome() {
    managerFinanses.addIncome();
}
