#ifndef HELPFULMETHODS_H
#define HELPFULMETHODS_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;

class HelpfulMethods {

public:
    static string conversionIntForString(int number);
    static int conversionStringForInt(string text);
    static float conversionStringForFloat(string text);
    static string conversionFloatForString(float number);
    static string changeFirstLetterForCapitalLetterAndOthersForLowercaseLetters(string text);

    static char loadSign();
    static string loadLine();
    static int loadIntiger();
    static float loadFloat();

    static string loadTodayDate();
    static int changeDate(string date);
    static int beginningOfThisMonth();
    static int beginningOfPreviousMonth();
    static int theEndOfPreviousMonth();
  /*
    static bool isTheDateGood();
    static bool isTheYearGood();
    static bool isTheMonthGood();
    static bool isTheDayGood();
*/
};

#endif
