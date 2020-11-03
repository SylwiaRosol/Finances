#include "ManagerUser.h"


void ManagerUser::registerUser(){
    User user = giveDataNewUser();
    users.push_back(user);
    cout << "Konto zostalo zalozone" << endl;
    system("pause");
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


int ManagerUser::singIn() {

    string nameUser = "", password = "";

    cout <<"Podaj login" << endl;
    cin >> nameUser;


    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr->getUserName() == nameUser)
        {
            for (int test = 3; test > 0; test--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << test << ": ";
                cin >> password;

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");

                     idLoggedUser = itr -> getIdUser();
                     return idLoggedUser;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;

}
