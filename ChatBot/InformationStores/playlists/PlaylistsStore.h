//
// Created by Vlado on 23-Mar-19.
//

#ifndef CHATBOT_PLAYLISTSSTORE_H
#define CHATBOT_PLAYLISTSSTORE_H


#include "../../Models/playlist/Playlist.h"

class PlaylistsStore {
private:
    vector<Playlist> playlists;
public:
    void addPlaylist(Playlist &playlist);

    const vector<Playlist> &getPlaylists() const;

    bool isEmpty();

    int size();
};


#endif //CHATBOT_PLAYLISTSSTORE_H
