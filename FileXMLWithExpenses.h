#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Expenses.h"
#include "FileXml.h"
#include "Markup.h"
#include "HelpfulMethods.h"


using namespace std;


class FileXmlWithExpenses : public FileXml {

    string nameFile;

public:

    FileXmlWithExpenses(string nameFile) : FileXml (nameFile) {};
    void addExpensesToTheFile (Expenses expenses);
    vector <Expenses> loadExpensesFromFile();
    int idNewExpense();
};
