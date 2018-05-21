#include <iostream>
#include <windows.h>
#include <string>
#include <time.h>
#include <conio.h>

#include "User.h"
#include "UserFile.h"
#include "Users.h"
#include "Markup.h"
#include "PersonalBudget.h"
#include "Date.h"

using namespace std;

char signUpMenu();
char userMenu();

int main(){

    Users users;
    char userChoice;

    while(true){

        if(users.getSignInUserId() == 0){

            userChoice = signUpMenu();

            switch(userChoice){
            case '1':
                users.signUp();
                break;
            case '2':
               users.signIn();
                break;
            case '9':
               exit(0);
                break;
            }
        }
        else if(users.getSignInUserId() != 0){

            do{
                PersonalBudget budget(users.getSignInUserId());

                userChoice = userMenu();

                switch(userChoice){
                    case '1':
                        budget.addIncome();
                        break;
                    case '2':
                        budget.addExpense();
                        break;
                    case '3':
                        break;
                    case '4':
                        break;
                    case '5':
                        budget.selectedPeroidBalance();
                        break;
                    case '6':
                        users.changePassword();
                        break;
                    case '7':
                        users.signOut();
                        break;
                    }
            }while(userChoice != '7');
        }
    }
    return 0;
}

char signUpMenu(){

    char userChoice;
    system("cls");

    cout << ">>>>> MENU <<<<<" << endl;
    cout << "----------------" << endl;
    cout << "1. SignUp" << endl;
    cout << "2. SignIn" << endl;
    cout << "9. Exit" << endl;
    cout << "Your choice: "; cin >> userChoice; cin.ignore();

    return userChoice;
}

char userMenu(){

    char userChoice;
    system("cls");

    cout << "       >>>>> USER MENU <<<<<" << endl;
    cout << "------------------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Current month balance" << endl;
    cout << "4. Previous month balance" << endl;
    cout << "5. Balance of the selected peroid" << endl;
    cout << "-------------------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Your choice: "; cin >> userChoice; cin.ignore();

    return userChoice;
}

