#include "ManagerFinanses.h"

void ManagerFinanses::addIncome(){
    char choice;
    system("cls");
    cout << "-----DODAWANIE PRZYCHODU-----" << endl;
    income.setIdUser(ID_LOGGED_USER);
    //income.setIdIncome();
    income.setDate(enterTheDate());
    income.setAmount(enterTheAmount());
    income.setCategoryIncome(enterADescription());
    incomes.push_back(income);
}

string ManagerFinanses::enterTheDate() {
    char choice;
    string date;
    do{
    cout <<"Czy chcesz dodaj przychod z dzisiejsza data? t-tak, n-nie"<<endl;
    choice = HelpfulMethods::loadSign();
    if(choice == 't') {
        date = loadTodayDate();
        return date;
    } else if (choice == 'n') {
        cout<<"Podaj date otrzymania przychodu" <<endl;
        date = HelpfulMethods::loadLine();
        return date;
    } else {
        cout<<"Podajes bledna odpowiedz";
        system("pause");
    }
    } while(choice!='n' || choice!='N' || choice !='t' || choice !='T');

}

string ManagerFinanses::enterADescription() {
    string description;
    cout <<"Czego dotyczy podany koszt?" << endl;
    description = HelpfulMethods::loadLine();
    return description;
}

float ManagerFinanses::enterTheAmount() {
    float amount;
    cout << "Podaj kwote. Kwote dzisietna podaj z kropka, a nie z przecinkiem."<< endl;
    cin >> amount;
    return amount;
}


string ManagerFinanses::loadTodayDate() {
        string year, month, day;
        SYSTEMTIME st;
        GetSystemTime(&st);
        year = HelpfulMethods::conversionIntForString(st.wYear);
        month = HelpfulMethods::conversionIntForString(st.wMonth);
        day = HelpfulMethods::conversionIntForString(st.wDay);
        string date = year + "-" + month + "-" + day;
    return date;
}
