#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

#include "User.h"

using namespace std;


class ManagerUser {

    vector <User> users;
    User user;
    int idLoggedUser;

    bool isExistNameUser(string nameUser);
    int setIdNewUser();

public:
    void registerUser();
    User giveDataNewUser();
    int singIn();
    void changePasswordLogedUser();
    void singOut();



};
