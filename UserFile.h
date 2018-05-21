#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "User.h"
#include "Markup.h"

using namespace std;

class UserFile
{
    public:
        UserFile();
        virtual ~UserFile();
        void loadAllUsersFromFile(vector<User>&usersVec);
        void addUserToFile(User);
        void saveAllUserToFile(vector<User>&usersVec);

    private:
        CMarkup users;
        User user;
        string fileName;
};

#endif // USERFILE_H
