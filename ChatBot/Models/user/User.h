//
// Created by Vlado on 23-Mar-19.
//

#ifndef CHATBOT_USER_H
#define CHATBOT_USER_H

#include "string"
#include "vector"
#include "../playlist/Playlist.h"

using namespace std;

class User {
private:
    long long id;
    string name;
    string secondName;
    int age;

    vector<Playlist> playlists;

public:
    User();

    User(long long id, string name, string secondName, int age);

    long long int getId() const;

    void setId(long long int id);

    const string &getName() const;

    void setName(const string &name);

    const string &getSecondName() const;

    void setSecondName(const string &secondName);

    const vector<Playlist> &getPlaylists() const;

    void addPlaylist(Playlist &playlist);

    string toString();
};


#endif //CHATBOT_USER_H
