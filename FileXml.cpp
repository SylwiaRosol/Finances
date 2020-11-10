#include "FileXml.h"

string FileXml::getNameFile() {
    return NAME_FILE;
}

bool FileXml::isFileEmpty(fstream &file) {

    file.seekg(0, ios::end);
    if (file.tellg() == 0)
        return true;
    else
        return false;
}
