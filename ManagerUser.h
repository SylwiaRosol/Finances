#ifndef MANAGERUSER_H
#define MANAGERUSER_H

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

#include "User.h"
#include "FileXmlWithUsers.h"
#include "HelpfulMethods.h"

using namespace std;


class ManagerUser {

    vector <User> users;
    User user;
    FileXmlWithUsers fileXmlWithUsers;
    int idLoggedUser;

    bool isExistNameUser(string nameUser);
    int setIdNewUser();

public:
    ManagerUser(string nameFileXmlWithUser) : fileXmlWithUsers(nameFileXmlWithUser) {
       users = fileXmlWithUsers.loadUsersFromFile();
         idLoggedUser = 0;
         };

    void registerUser();
    User giveDataNewUser();
    int singIn();
    void changePasswordLogedUser();
    void singOut();
    bool isUserLoggedIn();
    int getIdLoggedUser();
};

#endif
