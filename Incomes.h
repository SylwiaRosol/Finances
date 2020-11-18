#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>
#include <vector>
#include <string>

#include "Costs.h"



using namespace std;

class Incomes : private Costs {

    Costs cost;
    int idIncome;
    string categoryIncome;
public:

    int getIdUser();
    int getIdIncomes();
    string getCategoryIncomes();
    string getDate();
    float getAmount();

    void setIdUser(int newIdUser);
    void setIdIncome(int newIdIncome);
    void setCategoryIncome(string newCategoryIncome);
    void setDate(string newDate);
    void setAmount(float newAmount);
};
#endif
