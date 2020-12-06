#include "ManagerUser.h"


void ManagerUser::registerUser(){
    User user = giveDataNewUser();
    users.push_back(user);
    fileXmlWithUsers.addUserToTheFile(user);
    cout << "Konto zostalo zalozone" << endl;
    system("pause");
}

User ManagerUser::giveDataNewUser() {
    User user;
    string nameUser, password, name,surname;
    user.setIdUser(setIdNewUser());

        cout << "Podaj swoje imie" << endl;
        name = HelpfulMethods::loadLine();
        name = HelpfulMethods::changeFirstLetterForCapitalLetterAndOthersForLowercaseLetters(name);
        user.setName(name);
        cout << "Podaj swoje nazwisko" << endl;
        surname = HelpfulMethods::loadLine();
        surname = HelpfulMethods::changeFirstLetterForCapitalLetterAndOthersForLowercaseLetters(surname);
        user.setSurname(surname);

    do {
        cout << "Podaj login nowego uzytkownika: "<< endl;
        nameUser = HelpfulMethods::loadLine();
    } while (isExistNameUser(nameUser));
    user.setUserName(nameUser);

    cout << "Podaj haslo" << endl;
    password = HelpfulMethods::loadLine();
    user.setPassword(password);

    return user;
}

int ManagerUser::setIdNewUser() {
     return (users.empty() == true) ? 1 : users.back().getIdUser() + 1;
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

void ManagerUser::singOut(){
    idLoggedUser = 0;
    cout << "Wylogowales sie poprawnie" << endl << endl;
    system("pause");
}

void ManagerUser::changePasswordLogedUser(){
    string newPassword;
    cout <<"Podaj nowe haslo" << endl;
    newPassword = HelpfulMethods::loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if( itr-> User::getIdUser() == getIdLoggedUser() ) {
            itr -> User::setPassword(newPassword);
            fileXmlWithUsers.changePasswordLogedUser(newPassword, idLoggedUser);
            cout << "Haslo zostalo zmienione" << endl;
            system("pause");
        }

    }
}


bool ManagerUser::isUserLoggedIn() {
    return (idLoggedUser != 0) ? true : false;
}

int ManagerUser::getIdLoggedUser() {
    return idLoggedUser;
}
