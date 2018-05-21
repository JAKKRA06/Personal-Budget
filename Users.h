#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "UserFile.h"

using namespace std;

class Users
{
    public:
        Users();
        virtual ~Users();
        void signIn();
        void signOut();
        void signUp();
        void changePassword();
        int getSignInUserId();

    private:
        int signInUserId;
        vector<User>usersVec;
        UserFile userFile;
        User enterDataForNewUser();
        int getNewUserId();
        User user;
        string enterPassword();
        bool checkIfLoginExist(string login);
};

#endif // USERS_H
