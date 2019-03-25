//
// Created by Vlado on 25-Mar-19.
//

#include "RemoveSongFromPlaylistAction.h"
#include "iostream"

using namespace std;

void RemoveSongFromPlaylistAction::execute(PlaylistsStore &playlistsStore,
                                           UserStore &userStore,
                                           User &user) {
    if (user.getPlaylists().empty()) {
        return;
    }

    cout
            << "Choose the index of the PLAYLIST you want to remove song from or write -1 if you want to prevent that action:"
            << endl << std::flush;
    int playlistIndex;
    cin >> playlistIndex;

    if (playlistIndex == -1)
        return;

    Playlist &playlist = user.getPlaylistByIndex(playlistIndex);

    if(playlist.getMusics().empty()) {
        cout << "There are no songs which can be deleted!" << endl;
        return;
    }

    for (int i = 0; i < playlist.getMusics().size(); ++i) {
        cout << "Index: " << i << " Song -> " << playlist.getMusics()[i].getArtist() << " - "
             << playlist.getMusics()[i].getName() << endl;
    }

    cout << "Choose the index of the SONG which you want to remove or write -1 if you want to prevent that action: "
         << endl;
    int songIndex;
    cin >> songIndex;

    if (songIndex == -1) {
        return;
    }

    if (songIndex >= playlist.size()) {
        cout << "Song could not be deleted, please choose a correct index";
        return;
    }

    playlist.removeSongByIndex(songIndex);
    user.getPlaylistByIndex(playlistIndex).removeSongByIndex(songIndex);
}
