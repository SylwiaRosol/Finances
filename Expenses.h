#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>
#include <vector>
#include <string>

#include "Costs.h"



using namespace std;

class Expenses : private Costs {

    int idExpense;
    string categoryExpense;
public:

    int getIdUser();
    int getIdExpense();
    string getCategoryExpense();
    string getDate();
    float getAmount();

    void setIdUser(int newIdUser);
    void setIdExpense(int newIdExpense);
    void setCategoryExpense(string newCategoryExpense);
    void setDate(string newDate);
    void setAmount(float newAmount);
};
#endif
