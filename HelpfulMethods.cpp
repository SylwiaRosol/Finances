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

