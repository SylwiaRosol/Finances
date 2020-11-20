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
    Expenses(int idUser = 0, int idExpense = 0, string date = "", string categoryExpense = "",float amount = 0, int dateInt = 0) {
        this -> idUser = idUser;
        this -> idExpense = idExpense;
        this -> date = date;
        this -> categoryExpense = categoryExpense;
        this -> amount = amount;
        this -> dateInt = dateInt;
    }

    int getIdUser();
    int getIdExpense();
    string getCategoryExpense();
    string getDate();
    float getAmount();
    int getDateInt();

    void setIdUser(int newIdUser);
    void setIdExpense(int newIdExpense);
    void setCategoryExpense(string newCategoryExpense);
    void setDate(string newDate);
    void setAmount(float newAmount);
    void setDateInt(int newDateInt);
};
#endif
