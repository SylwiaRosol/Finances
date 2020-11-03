#include <iostream>
#include <vector>
#include "User.h"

using namespace std;


class ManagerUser {

    vector <User> users;
    User user;

    bool isExistNameUser(string nameUser);
    int setIdNewUser();

public:
    void registerUser();
    User giveDataNewUser();
    void singIn();
    void changePasswordLogedUser();
    void singOut();



};
