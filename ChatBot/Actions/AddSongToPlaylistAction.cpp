//
// Created by Vlado on 23-Mar-19.
//

#include "AddSongToPlaylistAction.h"
#include "iostream"

using namespace std;

void AddSongToPlaylistAction::execute(PlaylistsStore playlistsStore,
                                      SongsStore songsStore,
                                      UserStore userStore,
                                      User &user) {

    if (user.getPlaylists().empty()) {
        cout << "You must first create a playlist in order to add a song" << endl;

        return;
    }

    cout << "Choose the index of the playlist you want to add song to" << endl << std::flush;
    int playlistIndex;
    cin >> playlistIndex;

    cin.ignore();

    // TODO: Get Song information, save it to the songs store and then to the user playlist
    cout << "Song artist: " << endl << std::flush;
    string songArtist;
    getline(cin, songArtist);

    cout << "Song name: " << endl << std::flush;
    string songName;
    getline(cin, songName);
}
