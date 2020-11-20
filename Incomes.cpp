#include "Incomes.h"


int Incomes::getIdUser(){
    return idUser;
}
int Incomes::getIdIncomes(){
    return idIncome;
}
string Incomes::getCategoryIncomes(){
    return categoryIncome;
}
string Incomes::getDate(){
    return date;
}
float Incomes::getAmount(){
    return amount;
}
int Incomes::getDateInt(){
    return dateInt;
}


void Incomes::setIdUser(int newIdUser){
    if(newIdUser >0){
    idUser = newIdUser;
}}

void Incomes::setIdIncome(int newIdIncome){
    if(newIdIncome > 0){
    idIncome = newIdIncome;
}
}
void Incomes::setCategoryIncome(string newCategoryIncome){
    categoryIncome = newCategoryIncome;
}
void Incomes::setDate(string newDate){
    date = newDate;
}
void Incomes::setAmount(float newAmount){
    amount = newAmount;
}
void Incomes::setDateInt(int newDateInt){
    dateInt = newDateInt;
}
