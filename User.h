#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    public:
        User();
        virtual ~User();

        void setUserId(int id) ;
        void setUserLogin(string login);
        void setUserName(string name);
        void setUserSurname(string surname);
        void setUserPassword(string password);

        int getUserId();
        string getUserLogin();
        string getUserName();
        string getUserSurname();
        string getUserPassword();

    private:
        int id;
        string login;
        string name;
        string surname;
        string password;
};

#endif // USER_H
