#ifndef COSTS_H
#define COSTS_H

#include <iostream>
#include <string>
#include <windows.h>
#include <winbase.h>

#include "HelpfulMethods.h"




using namespace std;

class Costs {

   int idUser;
    float amount;
    string date;
public:
    string loadTodayDate();
};

#endif
