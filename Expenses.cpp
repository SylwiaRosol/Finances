#include "Expenses.h"


int Expenses::getIdUser(){
    return idUser;
}
int Expenses::getIdExpense(){
    return idExpense;
}
string Expenses::getCategoryExpense(){
    return categoryExpense;
}
string Expenses::getDate(){
    return date;
}
float Expenses::getAmount(){
    return amount;
}


void Expenses::setIdUser(int newIdUser){
    if(newIdUser >1){
    idUser = newIdUser;
}}

void Expenses::setIdExpense(int newIdExpense){
    if(newIdExpense > 1){
    idExpense = newIdExpense;
}
}
void Expenses::setCategoryExpense(string newCategoryExpense){
    categoryExpense = newCategoryExpense;
}
void Expenses::setDate(string newDate){
    date = newDate;
}
void Expenses::setAmount(float newAmount){
    amount = newAmount;
}
