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
    fileXmlWithIncomes.addIncomesToTheFile(income);
    string date = income.getDate();
    income.setDateInt(DateCheckingMethods::changeDate(date));
    incomes.push_back(income);
}

void ManagerFinanses::addExpense(){
    system("cls");
    cout << "-----DODAWANIE WYDATKU-----" << endl;
    expense.setIdUser(ID_LOGGED_USER);
    expense.setIdExpense(fileXmlWithExpenses.idNewExpense());
    expense.setDate(enterTheDate());
    expense.setAmount(enterTheAmount());
    expense.setCategoryExpense(enterADescription());
    fileXmlWithExpenses.addExpensesToTheFile(expense);
    string date = expense.getDate();
    expense.setDateInt(DateCheckingMethods::changeDate(date));
    expenses.push_back(expense);
}

string ManagerFinanses::enterTheDate() {
    char choice;
    string date;
    while(true) {
    cout <<"Czy dodawany elemnt dotyczy dzisiejszego dnia? t-tak, n-nie"<<endl;
    choice = HelpfulMethods::loadSign();
    if((choice == 't') || (choice == 'T')) {
        date = DateCheckingMethods::loadTodayDate();
        break;
    } else if ((choice == 'n') || (choice == 'N')) {
        while(true) {
        cout<<"Podaj date wprowadzanego kosztu" <<endl;
        date = HelpfulMethods::loadLine();
        if(DateCheckingMethods::isTheDateGood(date)== true){
            break; break;
        }} break;
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

void ManagerFinanses::showBalanceFromThisMonth(){
    float amountIncomes=0, amountExpenses=0;
    sortVector();
    system("cls");
    cout<<"------BILANS Z OBECNEGO MIESIACA------" << endl << endl;
    cout<< "PRZYCHODY:"<< endl;
    for (vector <Incomes>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        if ((itr-> Incomes::getIdUser() == ID_LOGGED_USER) && (itr -> Incomes::getDateInt() >= DateCheckingMethods::beginningOfThisMonth())) {

        cout << "Data: " << itr ->Incomes::getDate() << " Kwota: " << itr -> Incomes::getAmount() <<" PLN   Kategoria: " << itr -> Incomes::getCategoryIncomes() << endl;
            amountIncomes +=  itr -> Incomes::getAmount();
    }}


    cout<<endl << "WYDATKI:"<< endl;
    for (vector <Expenses>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        if ((itr-> Expenses::getIdUser() == ID_LOGGED_USER) && (itr -> Expenses::getDateInt() >= DateCheckingMethods::beginningOfThisMonth())) {

        cout << "Data: " << itr -> Expenses::getDate() << " Kwota: " << itr -> Expenses::getAmount() <<" PLN   Kategoria: " << itr -> Expenses::getCategoryExpense() << endl;
            amountExpenses += itr -> Expenses::getAmount();
    }}
    showBalance(amountIncomes, amountExpenses);
    system("pause");
}

void ManagerFinanses::showBalanceFromPreviousMonth(){
    float amountIncomes=0, amountExpenses=0;
    sortVector();
    system("cls");
    cout<<"------BILANS Z POPRZEDNIEGO MIESIACA------" << endl << endl;
    cout<< "PRZYCHODY:"<< endl;
    for (vector <Incomes>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        if(( itr-> Incomes::getIdUser() == ID_LOGGED_USER ) && (itr -> Incomes::getDateInt() >= DateCheckingMethods::beginningOfPreviousMonth()) && (itr -> Incomes::getDateInt() <= DateCheckingMethods::theEndOfPreviousMonth())) {
        cout << "Data: " << itr ->Incomes::getDate() << " Kwota: " << itr -> Incomes::getAmount() <<" PLN   Kategoria: " << itr -> Incomes::getCategoryIncomes() << endl;
            amountIncomes +=  itr -> Incomes::getAmount();

    }}

        cout <<endl << "WYDATKI:" << endl;
    for (vector <Expenses>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        if(( itr-> Expenses::getIdUser() == ID_LOGGED_USER ) && (itr -> Expenses::getDateInt() >= DateCheckingMethods::beginningOfPreviousMonth()) && (itr -> Expenses::getDateInt() <= DateCheckingMethods::theEndOfPreviousMonth())) {
        cout << "Data: " << itr ->Expenses::getDate() << " Kwota: " << itr -> Expenses::getAmount() <<" PLN   Kategoria: " << itr -> Expenses::getCategoryExpense() << endl;
            amountExpenses +=  itr -> Expenses::getAmount();

    }}
    showBalance(amountIncomes, amountExpenses);
    system("pause");
}

void ManagerFinanses::showBalanceFromSelectedTime() {
    float amountIncomes=0, amountExpenses=0;
    string startDate, endDate;
    int startDateInt, endDateInt;
    sortVector();
    system("cls");
    cout<<"------BILANS Z WYBRANEGO OKRESU------" << endl << endl;
    while(true){
    cout<< "Podaj date poczatkowa" << endl;
    startDate = HelpfulMethods::loadLine();
    if(DateCheckingMethods::isTheDateGood(startDate)== true){
        cout <<"Podaj date koncowa" << endl;
        endDate = HelpfulMethods::loadLine();
        if (DateCheckingMethods::isTheDateGood(endDate)== true){
            startDateInt = DateCheckingMethods::changeDate(startDate);
            endDateInt = DateCheckingMethods::changeDate(endDate);
            if ( startDateInt < endDateInt){
                break; break; break; break;
            } else {
                cout << "Data poczatkowa powinna byc data wczesniejsza, niz data koncowa" << endl;
            }}}}

    cout<< "PRZYCHODY:"<< endl;
    for (vector <Incomes>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        if(( itr-> Incomes::getIdUser() == ID_LOGGED_USER ) && (itr -> Incomes::getDateInt() >= startDateInt) && (itr -> Incomes::getDateInt() <= endDateInt)) {
        cout << "Data: " << itr ->Incomes::getDate() << " Kwota: " << itr -> Incomes::getAmount() <<" PLN   Kategoria: " << itr -> Incomes::getCategoryIncomes() << endl;
            amountIncomes +=  itr -> Incomes::getAmount();
    }}

        cout <<endl << "WYDATKI:" << endl;
    for (vector <Expenses>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        if(( itr-> Expenses::getIdUser() == ID_LOGGED_USER ) && (itr -> Expenses::getDateInt() >= startDateInt) && (itr -> Expenses::getDateInt() <= endDateInt)) {
        cout << "Data: " << itr ->Expenses::getDate() << " Kwota: " << itr -> Expenses::getAmount() <<" PLN   Kategoria: " << itr -> Expenses::getCategoryExpense() << endl;
            amountExpenses +=  itr -> Expenses::getAmount();
    }}
    showBalance(amountIncomes, amountExpenses);
    system("pause");

}

void ManagerFinanses::sortVector(){

    sort(incomes.begin(), incomes.end());
    sort(expenses.begin(), expenses.end());
}

void ManagerFinanses::showBalance(float amountIncomes, float amountExpenses) {

        cout << endl << endl <<"DOCHODY: "<< amountIncomes<< " PLN"<< endl;
        cout  <<"WYDATKI: "<< amountExpenses << " PLN"<< endl;
        cout << "BILANS: " << amountIncomes-amountExpenses << " PLN" << endl << endl;
}
