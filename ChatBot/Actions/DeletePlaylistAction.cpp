//
// Created by Vlado on 25-Mar-19.
//

#include "DeletePlaylistAction.h"
#include "iostream"

using namespace std;

void DeletePlaylistAction::execute(PlaylistsStore &playlistsStore,
                                   UserStore &userStore,
                                   User &user) {
    if (user.getPlaylists().empty()) {
        cout << "There are no playlists which you can delete" << endl;

        return;
    }

    cout << "Choose the index of the PLAYLIST which you want to remove or write -1 if you want to prevent that action:"
         << endl;

    int playlistIndex;
    cin >> playlistIndex;

//    playlistsStore.removePlaylistByIndex(playlistIndex);
    user.removePlaylistByIndex(playlistIndex);
}
