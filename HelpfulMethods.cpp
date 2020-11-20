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
    bool numberIsNotGood = true;
    bool numberHaveNotComma = true;

    while (numberIsNotGood==true) {
        getline(cin, input);
        numberHaveNotComma = true;
        for(int i=0; i< input.size(); i++){
            if(input[i] == ',') {
                cout << "Zapisz liczbe dziesietna z kropka, a nie z przecinkiem" << endl;
                numberHaveNotComma = false;
        }}
        if(numberHaveNotComma == true){
           stringstream myStream(input);
        if (myStream >> number){
            numberIsNotGood = false;
        } else {
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }}}
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
