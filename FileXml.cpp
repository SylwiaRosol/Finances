#include "FileXml.h"

string FileXml::getNameFile() {
    return NAME_FILE;
}

bool FileXml::isFileEmpty(fstream &file) {

    file.seekg(0, ios::end);
    return (file.tellg() == 0) ? true : false;
}
