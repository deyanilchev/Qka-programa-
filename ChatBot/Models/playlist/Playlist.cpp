//
// Created by Vlado on 23-Mar-19.
//

#include "Playlist.h"

const string &Playlist::getName() const {
    return name;
}

void Playlist::setName(const string &name) {
    Playlist::name = name;
}

void Playlist::addMusic(Song music) {
    musics.push_back(music);
}

const vector<Song> &Playlist::getMusics() const {
    return musics;
}

Playlist::Playlist(string name, vector<Song> songs) {
    Playlist::name = name;

    for (const auto &song : songs) {
        Playlist::addMusic(song);
    }
}

Playlist::Playlist(string playlistName) {
    Playlist::name = std::move(playlistName);
}

Playlist::Playlist() = default;
