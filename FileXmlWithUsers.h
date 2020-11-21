#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "FileXml.h"
#include "Markup.h"
#include "HelpfulMethods.h"


using namespace std;


class FileXmlWithUsers : public FileXml {

    string nameFile;

public:

    FileXmlWithUsers(string nameFile) : FileXml (nameFile) {};
    void addUserToTheFile (User user);
    vector <User> loadUsersFromFile();
    void changePasswordLogedUser (string password, int idLoggedUser);
};
