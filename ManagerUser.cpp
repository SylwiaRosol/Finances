#include "ManagerUser.h"


void ManagerUser::registerUser(){
    User user = giveDataNewUser();
    users.push_back(user);
    cout << "Konto zostalo zalozone" << endl;
}

User ManagerUser::giveDataNewUser() {
    User user;
    string nameUser, password;
    user.setIdUser(setIdNewUser());

    do {
        cout << "Podaj login nowego uzytkownika: "<< endl;
        cin >> nameUser;
    } while (isExistNameUser(nameUser));
    user.setUserName(nameUser);

    cout << "Podaj haslo" << endl;
    cin >> password;
    user.setPassword(password);

    return user;
}

int ManagerUser::setIdNewUser() {
     if (users.empty() == true)
        return 1;
    else
        return users.back().getIdUser() + 1;
}

bool ManagerUser::isExistNameUser(string nameUser) {

 for (int i=0; i<users.size(); i++) {

    if(users[i].getUserName() == nameUser) {
        cout << "Istnieje uzytkownik o takim loginie" << endl;
        return true;
    }
 }
 return false;
}
