#include "FileXmlWithUsers.h"


void FileXmlWithUsers::addUserToTheFile (User user) {
    CMarkup xml;
    bool isFileExist = xml.Load(getNameFile());

    if(!isFileExist) {
        xml.AddElem("Users");
}
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.AddAttrib("id",user.getIdUser());
    xml.AddAttrib("name", user.getName());
    xml.AddAttrib("surname", user.getSurname());
    xml.AddAttrib("userName", user.getUserName());
    xml.AddAttrib("password", user.getPassword());

    xml.Save(getNameFile());
}


vector <User> FileXmlWithUsers::loadUsersFromFile(){
    CMarkup xml;
    vector <User> users;
    User user;

    bool isFileExist = xml.Load(getNameFile());
           if(!isFileExist) {
            return users;
        }
        xml.FindElem("Users");
        xml.IntoElem();

        while(xml.FindElem("User")) {


            user.setIdUser(HelpfulMethods::conversionStringForInt(xml.GetAttrib("id")));
            user.setName(xml.GetAttrib("name"));
            user.setSurname(xml.GetAttrib("surname"));
            user.setUserName(xml.GetAttrib("userName"));
            user.setPassword(xml.GetAttrib("password"));

            users.push_back(user);
        }

        return users;
}

void FileXmlWithUsers::changePasswordLogedUser(string password, int idLoggedUser){

    string idUser = HelpfulMethods::conversionIntForString(idLoggedUser);
    CMarkup xml;
    xml.Load(getNameFile());
    xml.FindElem("Users");
    xml.IntoElem();
    xml.FindElem("User");
    if(xml.GetAttrib("id") == idUser){
        xml.SetAttrib("password", password);
    }
    xml.Save(getNameFile());
}




