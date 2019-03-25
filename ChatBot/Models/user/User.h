

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

    vector<Playlist> &getPlaylists();

    void addSongToPlaylist(Song &song, int indexOfPlaylist);

    void addPlaylist(Playlist &playlist);

    Playlist& getPlaylistByIndex(int index);

    bool removePlaylistByIndex(int index);

    string toString();
};


#endif //CHATBOT_USER_H
