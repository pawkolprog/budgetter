#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H


#include <iostream>
#include <vector>
#include <windows.h>
#include "Markup.h"

#include "user.h"
#include "auxiliaryMethods.h"
#include "textFile.h"

using namespace std;

class FileWithUsers :public TextFile {
    public:
    FileWithUsers(string fileName) : TextFile(fileName) {}
    void addUserToFile(User user);
    vector <User> loadUsers();
    void changeUserPassword(string newPassword, string loggedUserId);
};

#endif
