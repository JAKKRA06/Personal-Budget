#include "User.h"

User::User(){
    id = 0;
    login = "";
    name = "";
    surname = "";
    password = "";
}

User::~User(){;}

void User::setUserId(int id){
    this->id = id;
}

void User::setUserName(string name){
    this->name = name;
}

void User::setUserSurname(string surname){
    this->surname = surname;
}

void User::setUserLogin(string login){
    this->login = login;
}

void User::setUserPassword(string password){
    this->password = password;
}

int User::getUserId(){
    return id;
}

string User::getUserName(){
    return name;
}

string User::getUserSurname(){
    return surname;
}

string User::getUserLogin(){
    return login;
}

string User::getUserPassword(){
    return password;
}
