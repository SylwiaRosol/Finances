#include "HelpfulMethods.h"


string HelpfulMethods::conversionIntForString(int number){

    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int HelpfulMethods::conversionStringForInt(string text) {

    int number;
    istringstream iss(text);
    iss >> number;
    return number;
}

float HelpfulMethods::conversionStringForFloat(string text) {

    float number;
    istringstream iss(text);
    iss >> number;
    return number;
}
string HelpfulMethods::conversionFloatForString(float number){

    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}


string HelpfulMethods::changeFirstLetterForCapitalLetterAndOthersForLowercaseLetters(string text){

     if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

char HelpfulMethods::loadSign(){

    string input = "";
    char sign  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            sign = input[0];
            break;
        } else if (input.length() > 1) {
            cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
        }
    }
    return sign;
}

string HelpfulMethods::loadLine(){

    string input = "";
    getline(cin, input);
    return input;
}

int HelpfulMethods::loadIntiger() {

    string input = "";
    int number = 0;

    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}
float HelpfulMethods::loadFloat() {

    string input = "";
    float number = 0;
    bool numberIsGood = true;

    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number){
                    for(int i=0; i< input.size(); i++){
                        if(input[i] == ',') {
                cout << "Zapisz liczbe dziesietna z kropka, a nie z przecinkiem" << endl;
                numberIsGood = false;
            }}} else {
            cout << "To nie jest liczba, wpisz ponownie" << endl;
            numberIsGood = false;
        }
            if (numberIsGood == true)
                break; break;
            }

    return number;
}


string HelpfulMethods::loadTodayDate() {
        string year, month, day;
        SYSTEMTIME st;
        GetSystemTime(&st);
        year = HelpfulMethods::conversionIntForString(st.wYear);
        month = HelpfulMethods::conversionIntForString(st.wMonth);
        day = HelpfulMethods::conversionIntForString(st.wDay);
        string date = year + "-" + month + "-" + day;
    return date;
}

int HelpfulMethods::changeDate(string date){

        for(int i=0; i<date.size(); i++){
            if(date[i] == '-') {
        date.erase(i,1);
       }}
       int changeDate = conversionStringForInt(date);
       return changeDate;
}

int HelpfulMethods::beginningOfThisMonth(){
    int startingDate;
    string date = loadTodayDate();
    date.erase(8,2);
    date.insert(8,"0");
    date.insert(9,"1");
    startingDate = changeDate(date);
    return startingDate;

}
int HelpfulMethods::beginningOfPreviousMonth(){
    int date = beginningOfThisMonth();
    SYSTEMTIME st;
    GetSystemTime(&st);

    if(st.wMonth == 1){
        date = date -8900;
    } else {
        date = date - 100;
    }
    return date;
}
int HelpfulMethods::theEndOfPreviousMonth(){
    SYSTEMTIME st;
    GetSystemTime(&st);
    int date;
    if( (st.wMonth == 1) || (st.wMonth == 5) || (st.wMonth == 7) || (st.wMonth == 10) || (st.wMonth == 12)) {
        date = beginningOfPreviousMonth() + 30;
    }
    if ((st.wMonth == 2) || (st.wMonth == 4) || (st.wMonth == 6) || (st.wMonth == 8) || (st.wMonth == 9) || (st.wMonth == 11)) {
        date = beginningOfPreviousMonth() + 31;
    }
    if((st.wMonth == 3)) {
        if(st.wYear %4 == 0){
            date = beginningOfPreviousMonth() + 29;
        } else {
            date = beginningOfPreviousMonth() + 28;
        }
    }
    return date;
}

bool HelpfulMethods::isTheDateGood(string date){

    if(date.size() != 10)  {
        cout << "Podana data ma nieodpowiednia ilosc znakow" << endl;
        return false;
    }
    for(int i=0; i<date.size(); i++) {

        if((i==4) || (i==7)) {
                if(date[i]!='-'){
            cout << "Podana data ma nieodpowiednia forme" << endl;
                return false;
        }}}

        if((isTheYearGood(date)== true) && (isTheMonthGood(date)==true) && (isTheDayGood(date)==true)) {
                return true;
            } else {
                return false;
                }
}

bool HelpfulMethods::isTheYearGood(string date){
    string year;
    int yearInt;
    SYSTEMTIME st;
    GetSystemTime(&st);

    for(int i=0; i<=3; i++) {
        year += date[i];
    }
    yearInt = changeDate(year);
    if((yearInt >= 2000) && (yearInt <= st.wYear)) {
        return true;
        } else {
        cout << "Niepoprawnie podany rok" << endl;
            return false;
        }
}

bool HelpfulMethods::isTheMonthGood(string date){
    string month, year;
    int monthInt, yearInt;
    SYSTEMTIME st;
    GetSystemTime(&st);

    for (int i = 5; i < 7; i++) {
        month += date[i];
    }
    monthInt = changeDate(month);

    for (int j = 0; j<=3; j++){
        year +=date[j];
    }
    yearInt = changeDate(year);

if (yearInt == st.wYear) {
    if ((monthInt <= st.wMonth) && (monthInt >=1)) {
        return true;
    } else {
        cout << "Data nie moze byc z przyszlego miesiaca" << endl;
        return false;
}} else {
     if((monthInt >= 1) && (monthInt <= 12)) {
        return true;
   } else {
       cout <<"Niepoprawnie podany miesiac" << endl;
    return false;
   }}
}

bool HelpfulMethods::isTheDayGood(string date) {
    string day, month;
    int dayInt, monthInt;
    for (int i = 8; i <= 9; i++) {
        day += date[i];
    }
    dayInt = changeDate(day);
    for (int j = 5; j <= 6; j++) {
        month += date[j];
    }
    monthInt = changeDate(month);

    if((monthInt == 1) || (monthInt == 3) ||(monthInt == 5) ||(monthInt == 7) ||(monthInt == 8) ||(monthInt == 10) ||(monthInt == 12)) {
        if((dayInt >= 1) && (dayInt <= 31)) {
            return true;
        } else {
            cout << "Niepoprawnie podany dzien"<< endl;
            return false;
        }}

    if((monthInt == 4) || (monthInt == 6) ||(monthInt == 9) ||(monthInt == 11)) {
        if((dayInt >= 1) && (dayInt <= 30)) {
            return true;
        } else {
            cout << "Niepoprawnie podany dzien"<< endl;
            return false;
        }}

    if( monthInt == 2) {
        string year;
        for (int k = 0; k<=3; k++){
            year += date[k];
        }
        int yearInt = changeDate(year);
        if (yearInt %4 == 0){
            if((dayInt >= 1) && (dayInt <= 29)){
            return true;
        } else
            cout << "Niepoprawnie podany dzien"<< endl;
            return false;
        } else {
            if((dayInt >= 1) && (dayInt <= 28)){
            return true;
        } else {
            cout << "Niepoprawnie podany dzien"<< endl;
            return false;
        }}}
}
