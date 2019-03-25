//
// Created by Vlado on 23-Mar-19.
//

#include <iostream>
#include "CreatePlayListAction.h"

using namespace std;

void
CreatePlayListAction::execute(PlaylistsStore playlistsStore, SongsStore songsStore, UserStore userStore, User &user) {
    cout << "Enter Playlist name: ";

    string playListName;
    cin >> playListName;

    Playlist playlist(playListName);

    playlistsStore.addPlaylist(playlist);
    user.addPlaylist(playlist);
}
