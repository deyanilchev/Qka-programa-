

#include "AddSongToPlaylistAction.h"
#include "iostream"

using namespace std;

void AddSongToPlaylistAction::execute(PlaylistsStore &playlistsStore,
                                      UserStore &userStore,
                                      User &user) {

    if (user.getPlaylists().empty()) {
        return;
    }

    cout << "Choose the index of the PLAYLIST you want to add song to or write -1 if you want to prevent that action"
         << endl << std::flush;
    int playlistIndex;
    cin >> playlistIndex;

    cin.ignore();

    cout << "Song artist: " << endl << std::flush;
    string songArtist;
    getline(cin, songArtist);

    cout << "Song name: " << endl << std::flush;
    string songName;
    getline(cin, songName);

    Song song(songArtist, songName);

//    playlistsStore.addSongToPlaylist(song, playlistIndex);
    user.addSongToPlaylist(song, playlistIndex);
}
