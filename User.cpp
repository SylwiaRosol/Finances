#include "User.h"


string User::getUserName(){
    return userName;
}
string User::getPassword() {
    return password;
}
string User::getName() {
    return name;
}
string User::getSurname() {
    return surname;
}
int User::getIdUser() {
    return idUser;
}
void User::setUserName(string newUserName) {
    userName = newUserName;
}
void User::setPassword(string newPassword){
    password = newPassword;
}
void User::setName(string newName) {
    name = newName;
}
void User::setSurname(string newSurname) {
    surname = newSurname;
}
void User::setIdUser(int newIdUser) {
    idUser = newIdUser;
}

