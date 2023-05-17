#include "fileWithUsers.h"

void FileWithUsers::addUserToFile(User user){
    CMarkup xml;

    bool fileExists = xml.Load(FILE_NAME);
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("Id", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save(FILE_NAME);
}

vector <User> FileWithUsers::loadUsers(){
    vector <User> users;
    User user;
    CMarkup xml;

    bool fileExists = xml.Load(FILE_NAME);
    if (!fileExists) return users;
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem() ) {
        xml.FindChildElem();
        user.setId(atoi( MCD_2PCSZ(xml.GetChildData())));
        xml.FindChildElem();
        user.setLogin(xml.GetChildData());
        xml.FindChildElem();
        user.setPassword(xml.GetChildData());
        xml.FindChildElem();
        user.setName(xml.GetChildData());
        xml.FindChildElem();
        user.setSurname(xml.GetChildData());
        users.push_back(user);
    }
    return users;
}

void FileWithUsers::changeUserPassword(string newPassword, string loggedUserId){
    CMarkup xml;

    xml.Load(FILE_NAME);
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem()){
        xml.FindChildElem("Id");
        if (xml.GetChildData() == loggedUserId){
            xml.FindChildElem("Password");
            xml.SetChildData(newPassword);
            xml.Save(FILE_NAME);
            break;
        }
    }
}

