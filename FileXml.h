#ifndef FILEXML_H
#define FILEXML_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;

class FileXml {


const string  NAME_FILE;

    public:

        FileXml(string nameFile) : NAME_FILE(nameFile) {}
        string getNameFile();
        bool isFileEmpty(fstream &file);
};
#endif
