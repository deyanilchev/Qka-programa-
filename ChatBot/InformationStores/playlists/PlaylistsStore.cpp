

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

Playlist &PlaylistsStore::getPlaylistByIndex(int index) {
    return playlists[index];
}

void PlaylistsStore::addSongToPlaylist(Song &song, int indexOfPlaylist) {
    playlists[indexOfPlaylist].addSong(song);
}

bool PlaylistsStore::removePlaylistByIndex(int index) {
    if (index < 0 || index >= playlists.size())
        return false;

    playlists.erase(playlists.begin() + index);
    return true;
}


