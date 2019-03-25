

#include <iostream>
#include "CreatePlayListAction.h"

using namespace std;

void
CreatePlayListAction::execute(PlaylistsStore &playlistsStore, UserStore &userStore, User &user) {
    cout << "Enter Playlist name: " << endl;

    string playListName;
    cin >> playListName;

    Playlist playlist(playListName);

    playlistsStore.addPlaylist(playlist);
    user.addPlaylist(playlist);
}
