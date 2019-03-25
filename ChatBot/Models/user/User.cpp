#include <utility>



#include "User.h"
#include "iostream"

using namespace std;

const string &User::getName() const {
    return name;
}

void User::setName(const string &name) {
    User::name = name;
}

vector<Playlist> &User::getPlaylists() {
    return playlists;
}

void User::addPlaylist(Playlist &playlist) {
    User::playlists.push_back(playlist);
}

const string &User::getSecondName() const {
    return secondName;
}

void User::setSecondName(const string &secondName) {
    User::secondName = secondName;
}

User::User(long long id, string name, string secondName, int age) {
    User::id = id;
    User::name = std::move(name);
    User::secondName = std::move(secondName);
    User::age = age;
}

string User::toString() {
    return User::name + " " + User::secondName + " " + std::to_string(User::age);
}

long long int User::getId() const {
    return id;
}

void User::setId(long long int id) {
    User::id = id;
}

void User::addSongToPlaylist(Song &song, int indexOfPlaylist) {
    User::playlists[indexOfPlaylist].addSong(song);
}

Playlist &User::getPlaylistByIndex(int index) {
    return User::playlists[index];
}

bool User::removePlaylistByIndex(int index) {
    if (index < 0 || index >= playlists.size())
        return false;

    playlists.erase(playlists.begin() + index);
    return true;
}

User::User() = default;
