#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>
#include <vector>
#include <string>

#include "Costs.h"



using namespace std;

class Incomes : private Costs {

    int idIncome;
    string categoryIncome;
public:
    Incomes(int idUser = 0, int idExpense = 0, string date = "", string categoryExpense = "",float amount = 0, int dateInt=0) {
        this -> idUser = idUser;
        this -> idIncome = idIncome;
        this -> date = date;
        this -> categoryIncome = categoryIncome;
        this -> amount = amount;
        this -> dateInt = dateInt;
    }


    int getIdUser();
    int getIdIncomes();
    string getCategoryIncomes();
    string getDate();
    float getAmount();
    int getDateInt();

    void setIdUser(int newIdUser);
    void setIdIncome(int newIdIncome);
    void setCategoryIncome(string newCategoryIncome);
    void setDate(string newDate);
    void setAmount(float newAmount);
    void setDateInt(int newDateInt);
};
#endif
