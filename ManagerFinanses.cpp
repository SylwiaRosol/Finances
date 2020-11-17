#include "ManagerFinanses.h"

void ManagerFinanses::addIncome(){
    char choice;
    system("cls");
    cout << "-----DODAWANIE PRZYCHODU-----" << endl;
    string date = enterTheDate();
    string text = enterADescription();
    float amount = enterTheAmount();
}

string ManagerFinanses::enterTheDate() {
    char choice;
    string date;
    cout <<"Czy chcesz dodaj przychod z dzisiejsza data? t-tak, n-nie"<<endl;
    choice = HelpfulMethods::loadSign();
    if(choice == 't') {
             system("pause");
    } else if (choice == 'n') {
        cout<<"Podaj date otrzymania przychodu" <<endl;
        date = HelpfulMethods::loadLine();
    } else {
        cout<<"Podajes bledna odpowiedz";
        system("pause");
    }
    return date;
}

string ManagerFinanses::enterADescription() {
    string text;
    cout <<"Czego dotyczy podany koszt?" << endl;
    text = HelpfulMethods::loadLine();
    return text;
}

float ManagerFinanses::enterTheAmount() {
    float amount;
    cout << "Podaj kwote. Kwote dzisietna podaj z kropka, a nie z przecinkiem."<< endl;
    cin >> amount;
    return amount;
}
