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
    string date = income.getDate();
    income.setDateInt(HelpfulMethods::changeDate(date));
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
    string date = expense.getDate();
    expense.setDateInt(HelpfulMethods::changeDate(date));

}

string ManagerFinanses::enterTheDate() {
    char choice;
    string date;
    while(true) {
    cout <<"Czy dodawany elemnt dotyczy dzisiejszego dnia? t-tak, n-nie"<<endl;
    choice = HelpfulMethods::loadSign();
    if(choice == 't') {
        date = HelpfulMethods::loadTodayDate();
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

void ManagerFinanses::showBalanceWithThisMonth(){
    float amountIncomes=0, amountExpenses=0;

    system("cls");
    cout<<"------BILANS Z OBECNEGO MIESIACA------" << endl << endl;
    cout<< "PRZYCHODY:"<< endl;
    for (vector <Incomes>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        if ((itr-> Incomes::getIdUser() == ID_LOGGED_USER) && (itr -> Incomes::getDateInt() >= HelpfulMethods::beginningOfThisMonth())) {

        cout << "Data: " << itr ->Incomes::getDate() << " Kwota: " << itr -> Incomes::getAmount() <<" PLN   Kategoria: " << itr -> Incomes::getCategoryIncomes() << endl;
            amountIncomes +=  itr -> Incomes::getAmount();
    }}


    cout<<endl << "WYDATKI:"<< endl;
    for (vector <Expenses>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        if ((itr-> Expenses::getIdUser() == ID_LOGGED_USER) && (itr -> Expenses::getDateInt() >= HelpfulMethods::beginningOfThisMonth())) {

        cout << "Data: " << itr -> Expenses::getDate() << " Kwota: " << itr -> Expenses::getAmount() <<" PLN   Kategoria: " << itr -> Expenses::getCategoryExpense() << endl;
            amountExpenses += itr -> Expenses::getAmount();
    }}

        cout << endl << endl <<"DOCHODY W OBECNYM MIESIACU TO: "<< amountIncomes<< " PLN"<< endl;
        cout  <<"WYDATKI Z OBECNEGO MIESIACA TO: "<< amountExpenses << " PLN"<< endl;
        cout << "BILANS Z OBECNEGO MIESIACA TO: " << amountIncomes-amountExpenses << " PLN" << endl << endl;

    system("pause");
}

void ManagerFinanses::showBalanceWithPreviousMonth(){

    float amountIncomes=0, amountExpenses=0;
    system("cls");
    cout<<"------BILANS Z POPRZEDNIEGO MIESIACA------" << endl << endl;
    cout<< "PRZYCHODY:"<< endl;
    for (vector <Incomes>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        if(( itr-> Incomes::getIdUser() == ID_LOGGED_USER ) && (itr -> Incomes::getDateInt() >= HelpfulMethods::beginningOfPreviousMonth()) && (itr -> Incomes::getDateInt() <= HelpfulMethods::theEndOfPreviousMonth())) {
        cout << "Data: " << itr ->Incomes::getDate() << " Kwota: " << itr -> Incomes::getAmount() <<" PLN   Kategoria: " << itr -> Incomes::getCategoryIncomes() << endl;
            amountIncomes +=  itr -> Incomes::getAmount();

    }}

        cout <<endl << "WYDATKI:" << endl;
    for (vector <Expenses>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        if(( itr-> Expenses::getIdUser() == ID_LOGGED_USER ) && (itr -> Expenses::getDateInt() >= HelpfulMethods::beginningOfPreviousMonth()) && (itr -> Expenses::getDateInt() <= HelpfulMethods::theEndOfPreviousMonth())) {
        cout << "Data: " << itr ->Expenses::getDate() << " Kwota: " << itr -> Expenses::getAmount() <<" PLN   Kategoria: " << itr -> Expenses::getCategoryExpense() << endl;
            amountExpenses +=  itr -> Expenses::getAmount();

    }}


    cout << endl << endl <<"DOCHODY W POPRZEDNIM MIESIACU TO: "<< amountIncomes<< " PLN"<< endl;
    cout  <<"WYDATKI Z POPRZEDNIEGO MIESIACA TO: "<< amountExpenses << " PLN"<< endl;
    cout << "BILANS Z POPRZEDNIEGO MIESIACA TO: " << amountIncomes-amountExpenses << " PLN" << endl << endl;


    system("pause");
}

/*
int ManagerFinanses::getIdLoggedUser(){
    return ID_LOGGED_USER;
}
vector <Incomes> ManagerFinanses::getVectorIncomes(){
    return incomes;
}
vector <Expenses> ManagerFinanses::getVectorExpeses(){
    return expenses;
}
*/
