//
// Created by Vlado on 23-Mar-19.
//

#ifndef CHATBOT_USERSTORE_H
#define CHATBOT_USERSTORE_H


#include "../../Models/user/User.h"

class UserStore {
private:
    vector<User> users;

public:
    void addUser(User user);

    User &getUser(int index);

    int size();

    vector<User> &getUsers();

    bool containsUser(string firstName, string secondName, int age);

    int indexOf(string firstName, string secondName, int age);
};


#endif //CHATBOT_USERSTORE_H
