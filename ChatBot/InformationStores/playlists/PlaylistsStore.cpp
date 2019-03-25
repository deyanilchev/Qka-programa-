//
// Created by Vlado on 23-Mar-19.
//

#include "PlaylistsStore.h"

void PlaylistsStore::addPlaylist(Playlist &playlist) {
    playlists.push_back(playlist);
}

int PlaylistsStore::size() {
    return playlists.size();
}

const vector<Playlist> &PlaylistsStore::getPlaylists() const {
    return playlists;
}

bool PlaylistsStore::isEmpty() {
    return playlists.empty();
}


