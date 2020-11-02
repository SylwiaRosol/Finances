#include <cstdlib>
#include "FinancialResources.h"




char FinancialResources::selectOptionFromTheMainMenu(){

   char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "11. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> choice;
   // choice = MetodyPomocnicze::wczytajZnak();

    return choice;

}

char FinancialResources::selectOptionFromeTheMenuUser() {

    char choice;

    system("cls");
    cout << "    >>> MENU  UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "4. Dodaj przychod" << endl;
    cout << "5. Dodaj wydatek" << endl;
    cout << "6. Bilans z bierz¹cego miesiaca" << endl;
    cout << "7. Bilans z poprzedniego miesiaca" << endl;
    cout << "8. Bilans z wybranego okresu" << endl;
    cout << "9. Zmien haslo" << endl;
    cout << "10. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> choice;
   return choice;
}


void FinancialResources::registerUser(){




}
