#ifndef DATECHECKINGMETHODS_H
#define DATECHECKINGMETHODS_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "HelpfulMethods.h"

using namespace std;

class DateCheckingMethods {
    public:

    static string loadTodayDate();
    static int changeDate(string date);
    static int beginningOfThisMonth();
    static int beginningOfPreviousMonth();
    static int theEndOfPreviousMonth();

    static bool isTheDateGood(string data);
    static bool isTheYearGood(string data);
    static bool isTheMonthGood(string data);
    static bool isTheDayGood(string data);

};
#endif
