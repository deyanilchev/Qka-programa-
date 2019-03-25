

#include "Playlist.h"
#include "string"

const string &Playlist::getName() const {
    return name;
}

void Playlist::setName(const string &name) {
    Playlist::name = name;
}

void Playlist::addSong(Song &music) {
    musics.push_back(music);
}

const vector<Song> &Playlist::getMusics() const {
    return musics;
}

Playlist::Playlist(string name, vector<Song> songs) {
    Playlist::name = name;

    for (auto &song : songs) {
        Playlist::addSong(song);
    }
}

Playlist::Playlist(string playlistName) {
    Playlist::name = std::move(playlistName);
}

bool Playlist::removeSongByIndex(int index) {
    if (index < 0 || index >= musics.size())
        return false;

    musics.erase(musics.begin() + index);
    return true;
}

int Playlist::size() {
    return musics.size();
}

string Playlist::toString() {
    // toString() example
    // playlistName - Slipknot - Pesen1, Iron Maiden - Pesen2, Murda Boys - Skandali,
    string result;

    result += this->getName() + " -";

    for (int i = 0; i < musics.size(); ++i) {
        result += " " + musics[i].toString() + ",";
    }

    if (musics.empty()) {
        result += " ";
    }

    return result;
}

Playlist::Playlist() = default;
