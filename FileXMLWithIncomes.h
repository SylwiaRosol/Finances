#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Incomes.h"
#include "FileXml.h"
#include "Markup.h"
#include "HelpfulMethods.h"
#include "DateCheckingMethods.h"


using namespace std;


class FileXmlWithIncomes : public FileXml {

    string nameFile;

public:

    FileXmlWithIncomes(string nameFile) : FileXml (nameFile) {};
    void addIncomesToTheFile (Incomes incomes);
    vector <Incomes> loadIncomesFromFile();
    int idNewIncomes();
};
