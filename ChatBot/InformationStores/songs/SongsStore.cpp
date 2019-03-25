//
// Created by Vlado on 23-Mar-19.
//

#include "SongsStore.h"

int SongsStore::size() {
    return songs.size();
}

void SongsStore::addSong(Song song) {
    songs.push_back(song);
}

const vector<Song> &SongsStore::getSongs() const {
    return songs;
}

Song SongsStore::findSongByWholeName(string wholeName) {
    for (auto &song : songs) {
        if (song.getArtist() + " - " + song.getName() == wholeName)
        return song;
    }

    // SHOULD NOT HAPPEN
}
