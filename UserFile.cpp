#include "UserFile.h"

UserFile::UserFile(){

    this->fileName = "users.xml";
}

UserFile::~UserFile(){;}

void UserFile::addUserToFile(User user){

    users.Load(fileName);

    if(!users.FindElem("USERS")) {
        users.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        users.AddElem("USERS");
    }
    users.IntoElem();
    users.AddElem("USER");
    users.IntoElem();
    users.AddElem("USERID", user.getUserId());
    users.AddElem("LOGIN", user.getUserLogin());
    users.AddElem("NAME", user.getUserName());
    users.AddElem("SURNAME", user.getUserSurname());
    users.AddElem("PASSWORD", user.getUserPassword());
    users.OutOfElem();

    users.Save(fileName);
}

void UserFile::loadAllUsersFromFile(vector<User> &usersVec){

    CMarkup xmlFile;
    xmlFile.Load(fileName);

    while(xmlFile.FindElem()) {

        xmlFile.IntoElem();

        xmlFile.FindElem("USER");
        xmlFile.IntoElem();

        xmlFile.FindElem("USERID");
        user.setUserId(atoi(xmlFile.GetData().c_str()));

        xmlFile.FindElem("LOGIN");
        user.setUserLogin(xmlFile.GetData());

        xmlFile.FindElem("NAME");
        user.setUserName(xmlFile.GetData());

        xmlFile.FindElem("SURNAME");
        user.setUserSurname(xmlFile.GetData());

        xmlFile.FindElem("PASSWORD");
        user.setUserPassword(xmlFile.GetData());

        usersVec.push_back(user);

        xmlFile.OutOfElem();
    }
}

void UserFile::saveAllUserToFile(vector<User> &usersVec){

    CMarkup users;
    int counter = 0;

    for (vector <User>::iterator itr = usersVec.begin(); itr != usersVec.end(); itr++){

        if(counter > 0)
            users.Load(fileName);

        if(!users.FindElem("USERS")) {

            users.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            users.AddElem("USERS");
        }
        users.IntoElem();
        users.AddElem("USER");
        users.IntoElem();
        users.AddElem("USERID", itr->User::getUserId());
        users.AddElem("LOGIN", itr->User::getUserLogin());
        users.AddElem("NAME", itr->User::getUserName());
        users.AddElem("SURNAME", itr->User::getUserSurname());
        users.AddElem("PASSWORD", itr->User::getUserPassword());
        users.OutOfElem();
        counter++;
        users.Save(fileName);
    }
}
