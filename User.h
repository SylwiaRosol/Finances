#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User {

    string userName;
    string password;
    string name;
    string surname;
    int idUser;
public:

    string getUserName();
    string getPassword();
    string getName();
    string getSurname();
    int getIdUser();
    void setUserName(string userName);
    void setPassword(string password);
    void setName(string name);
    void setSurname(string surname);
    void setIdUser(int idUser);

};


#endif
