#include "userManager.h"

int UserManager::getLoggedInUserId(){
    return loggedUserId;
}

void UserManager::userRegistration(){
    User user = enterDataOfNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Account has been created." << endl << endl;
    system("pause");
}

User UserManager::enterDataOfNewUser(){
    User user;

    user.setId(getNewUserId());

    do
    {
        cout << "Enter login: ";
        user.setLogin(AuxiliaryMethods::readLine());
    } while (isLoginExist(user.getLogin()));

    cout << "Enter password: ";
    user.setPassword(AuxiliaryMethods::readLine());

    cout << "Enter name: ";
    user.setName(AuxiliaryMethods::changeFirstLetterToCapitalAndRestLettersToLowercase(AuxiliaryMethods::readLine()));

    cout << "Enter surname: ";
    user.setSurname(AuxiliaryMethods::changeFirstLetterToCapitalAndRestLettersToLowercase(AuxiliaryMethods::readLine()));

    return user;
}

int UserManager::getNewUserId(){
    if (users.empty()) return 1;
    else return users.back().getId() + 1;
}

bool UserManager::isLoginExist(string login){
    for (int i = 0; i < (int) users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "There is a user with this login." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::loadUsers(){
    users = fileWithUsers.loadUsers();
}

bool UserManager::userLogin(){
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = AuxiliaryMethods::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Enter password. " << numberOfAttempts << " attempts left: ";
                password = AuxiliaryMethods::readLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "You have logged in." << endl << endl;
                    system("pause");
                    loggedUserId = itr -> getId();
                    return true;
                }
            }
            cout << "You entered 3 times wrong password." << endl;
            system("pause");
            return false;
        }
        itr++;
    }
    cout << "There is no user with this login." << endl << endl;
    system("pause");
    return false;
}

void UserManager::changePasswordLoggedInUser(){
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = AuxiliaryMethods::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == loggedUserId)
        {
            itr -> setPassword(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.changeUserPassword(newPassword, AuxiliaryMethods::conversionIntToString(loggedUserId));
}

void UserManager::userLogout(){
    loggedUserId = 0;
}


void UserManager::outputAllUsers() {
    for (int i = 0; i < (int) users.size(); i++) {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
}
