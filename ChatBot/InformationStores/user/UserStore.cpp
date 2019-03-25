

#include "UserStore.h"

void UserStore::addUser(User user) {
    users.push_back(user);
}

int UserStore::size() {
    return users.size();
}

vector<User> &UserStore::getUsers() {
    return users;
}

User &UserStore::getUser(int index) {
    return users[index];
}

bool UserStore::containsUser(string firstName, string secondName, int age) {
    string query = firstName + " " + secondName + " " + std::to_string(age);

    User user;
    for (const auto &i : users) {
        user = i;
        if (query == user.toString())
            return true;
    }

    return false;
}

int UserStore::indexOf(string firstName, string secondName, int age) {
    string query = firstName + " " + secondName + " " + std::to_string(age);

    for (int i = 0; i < users.size(); ++i) {
        if (query == users[i].toString())
            return i;
    }

    return -1;
}
