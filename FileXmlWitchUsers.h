#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "FileXml.h"


using namespace std;


class FileXmlWitchUsers : public FileXml {

    string nameFile;
    User getDateUser();
public:

    FileXmlWitchUsers(string nameFile) : FileXml (nameFile) {};
    void addUserToTheFile (User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile (vector <User> &users);

};
