#include "Users.h"

Users::Users(){

    this->signInUserId = 0;
    userFile.loadAllUsersFromFile(usersVec);
}

Users::~Users(){

    usersVec.clear();
}

int Users::getNewUserId(){

    if(usersVec.empty() == true)
        return 1;
    else
        return usersVec.back().getUserId() + 1;
}

int Users::getSignInUserId(){

    return signInUserId;
}

void Users::signUp(){

    string login = ""; string password = "";

    user = enterDataForNewUser();
    do {
        cout << "Get login: "; cin >> login; cin.ignore();
        user.setUserLogin(login);

    } while(checkIfLoginExist(user.getUserLogin()) == true);

    password = enterPassword();
    user.setUserPassword(password);

    usersVec.push_back(user);
    userFile.addUserToFile(user);

    cout << "Account has been created." << endl;
    system("pause");
}

void Users::signIn(){

    string login = ""; string password = "";
    int numberOfAttempts = 3;
    bool doesUserExist = false;
    vector<User>::iterator itr = usersVec.begin();

    cout << "Get a login: "; cin >> login; cin.ignore();

    while(itr != usersVec.end()) {

        if(itr->User::getUserLogin() == login) {

            doesUserExist = true;
            while(numberOfAttempts > 0){
                cout << "Get a password(minimum 3 char): "; cin >> password; cin.ignore();

                if(itr->User::getUserPassword() == password) {

                    this->signInUserId = itr->User::getUserId();
                    cout << "You logged in!" << endl;
                    break;
                }
                numberOfAttempts--;
            }
            if(numberOfAttempts == 0)
            {
                cout << endl << "You entered wrong password 3 times." << endl << endl;
                this->signInUserId = 0;
                doesUserExist = true;
                break;
            }
        }
        itr++;
    }
    if(doesUserExist == false)
        cout << "There is no user" << endl;

    system("pause");
}

User Users::enterDataForNewUser(){

    string name = ""; string surname = "";

    cout << "Get a name: "; cin >> name; cin.ignore();
    cout << "Get a surname: "; cin >> surname; cin.ignore();

    user.setUserId(getNewUserId());
    user.setUserName(name);
    user.setUserSurname(surname);

    return user;
}

string Users::enterPassword(){

    string password = "";

    do {
        cout << "Get a password(mininum 3 char): "; cin >> password; cin.ignore();

    } while(password.length() < 3);

    return password;
}

bool Users::checkIfLoginExist(string login){

    vector<User>::iterator itr = usersVec.begin();

    while(itr != usersVec.end()){

        if(itr->User::getUserLogin() == user.getUserLogin()) {

            cout << "Login has been exist. Try again." << endl;
            return true;
        } else
            itr++;
    }
    return false;
}

void Users::signOut(){

        this->signInUserId = 0;
}

void Users::changePassword(){

    string newPassword = ""; newPassword = enterPassword();
    bool hasChanged = false;
    vector<User>::iterator itr = usersVec.begin();

    while(itr != usersVec.end()){

        if(itr->User::getUserId() == getSignInUserId()){

            itr->User::setUserPassword(newPassword);
            hasChanged = true;
        }
        itr++;
    }
    userFile.saveAllUserToFile(usersVec);

    if(hasChanged){

        cout << "Password has changed." << endl << endl;
    }
    else{

        cout << "Password has not changed." << endl << endl;
    }
    system("pause");
}
