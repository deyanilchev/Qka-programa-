//
// Created by Vlado on 23-Mar-19.
//

#include <iostream>
#include "ShowPlayListsAction.h"

using namespace std;

void
ShowPlayListsAction::execute(PlaylistsStore playlistsStore, SongsStore songsStore, UserStore userStore, User &user) {
    if (user.getPlaylists().empty()) {
        cout << "There are no playlists for your account" << endl;
        return;
    }

    const vector<Playlist> &playlists = user.getPlaylists();
    Playlist playlist;

    for (int i = 0; i < playlists.size(); ++i) {
        playlist = playlists[i];
        cout << "Index:" << i << " Name -> " << playlist.getName() << endl;
    }
}
