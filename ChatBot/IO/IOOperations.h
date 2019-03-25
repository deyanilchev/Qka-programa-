

#ifndef CHATBOT_IOOPERATIONS_H
#define CHATBOT_IOOPERATIONS_H


#include "../InformationStores/user/UserStore.h"
#include "regex"
#include "../InformationStores/playlists/PlaylistsStore.h"

class IOOperations {
private:
    UserStore &userStore;
    PlaylistsStore &playlistStore;

    void loadUsers();

//    void loadSongs();

    void loadPlaylists();

    User &parseUserId(smatch matches);

    Playlist parsePlaylist(smatch matches, vector<Song> vector1);

    vector<Song> parsePlaylistSongs(smatch results);

    string buildUsersString();

    string buildPlaylistsString();

public:
    explicit IOOperations(UserStore &userStore, PlaylistsStore &playlistsStore);

    void loadAppInfo();

    void saveAppInfo();
};


#endif //CHATBOT_IOOPERATIONS_H
