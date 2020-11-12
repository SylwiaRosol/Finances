#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "FileXml.h"
#include "Markup.h"
#include "HelpfulMethods.h"


using namespace std;


class FileXmlWitchUsers : public FileXml {

    string nameFile;


public:

    FileXmlWitchUsers(string nameFile) : FileXml (nameFile) {};
    void addUserToTheFile (User user);
    vector <User> loadUsersFromFile();


};
