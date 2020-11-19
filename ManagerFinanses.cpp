#include "ManagerFinanses.h"

void ManagerFinanses::addIncome(){
    char choice;
    system("cls");
    cout << "-----DODAWANIE PRZYCHODU-----" << endl;
    income.setIdUser(ID_LOGGED_USER);
    income.setIdIncome(fileXmlWithIncomes.idNewIncomes());
    income.setDate(enterTheDate());
    income.setAmount(enterTheAmount());
    income.setCategoryIncome(enterADescription());
    incomes.push_back(income);
    fileXmlWithIncomes.addIncomesToTheFile(income);
}

void ManagerFinanses::addExpense(){
    system("cls");
    cout << "-----DODAWANIE WYDATKU-----" << endl;
    expense.setIdUser(ID_LOGGED_USER);
    expense.setIdExpense(fileXmlWithExpenses.idNewExpense());
    expense.setDate(enterTheDate());
    expense.setAmount(enterTheAmount());
    expense.setCategoryExpense(enterADescription());
    expenses.push_back(expense);
    fileXmlWithExpenses.addExpensesToTheFile(expense);
}

string ManagerFinanses::enterTheDate() {
    char choice;
    string date;
    while(true) {
    cout <<"Czy dodawany elemnt dotyczy dzisiejszego dnia? t-tak, n-nie"<<endl;
    choice = HelpfulMethods::loadSign();
    if(choice == 't') {
        date = loadTodayDate();
        break;
    } else if (choice == 'n') {
        cout<<"Podaj date otrzymania przychodu" <<endl;
        date = HelpfulMethods::loadLine();
        break;
    } else {
        cout<<"Podales bledna odpowiedz, sprobuj ponownie" << endl << endl;
    }}
    return date;
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
    amount = HelpfulMethods::loadFloat();
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

