

#include <iostream>
#include "ShowPlayListsAction.h"

using namespace std;

void
ShowPlayListsAction::execute(PlaylistsStore &playlistsStore, UserStore &userStore, User &user) {
    if (user.getPlaylists().empty()) {
        cout << "There are no playlists for your account" << endl;
        return;
    }

    const vector<Playlist> &playlists = user.getPlaylists();

    Playlist playlist;
    vector<Song> playlistMusics;
    for (int i = 0; i < playlists.size(); ++i) {
        playlist = playlists[i];
        cout << "Index:" << i << " Playlist -> " << playlist.getName() << endl;

        cout << "  Songs:" << endl;
        playlistMusics = playlist.getMusics();
        for (auto &playlistMusic : playlistMusics) {
            cout << "     " << playlistMusic.getArtist() << " - " << playlistMusic.getName() << endl;
        }
    }

    cout << endl;
}
