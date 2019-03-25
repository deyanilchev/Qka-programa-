//
// Created by Vlado on 23-Mar-19.
//

#ifndef CHATBOT_IOOPERATIONS_H
#define CHATBOT_IOOPERATIONS_H


#include "../InformationStores/user/UserStore.h"
#include "../InformationStores/songs/SongsStore.h"
#include "regex"
#include "../InformationStores/playlists/PlaylistsStore.h"

class IOOperations {
private:
    UserStore &userStore;
    SongsStore &songsStore;
    PlaylistsStore &playlistStore;

    void loadUsers();

    void loadSongs();

    void loadPlaylists();

    User& parseUserId(smatch matches);

    Playlist parsePlaylist(smatch matches, vector<Song> vector1);

    vector<Song> parsePlaylistSongs(smatch results);

public:
    explicit IOOperations(UserStore &userStore, SongsStore &songsStore, PlaylistsStore &playlistsStore);

    void loadAppInfo();
};


#endif //CHATBOT_IOOPERATIONS_H
