

#ifndef CHATBOT_PLAYLISTSSTORE_H
#define CHATBOT_PLAYLISTSSTORE_H


#include "../../Models/playlist/Playlist.h"

class PlaylistsStore {
private:
    vector<Playlist> playlists;
public:
    void addPlaylist(Playlist &playlist);

    const vector<Playlist> &getPlaylists() const;

    Playlist& getPlaylistByIndex(int index);

    void addSongToPlaylist(Song &song, int indexOfPlaylist);

    bool removePlaylistByIndex(int index);

    bool isEmpty();

    int size();
};


#endif //CHATBOT_PLAYLISTSSTORE_H
