//
// Created by Vlado on 23-Mar-19.
//

#ifndef CHATBOT_PLAYLIST_H
#define CHATBOT_PLAYLIST_H

#include <vector>
#include "string"
#include "../song/Song.h"

using namespace std;

class Playlist {
private:
    string name;
    vector<Song> musics;
public:
    Playlist();

    Playlist(string name, vector<Song> songs);

    const string &getName() const;

    void setName(const string &name);

    const vector<Song> &getMusics() const;

    void addMusic(Song music);

    Playlist(string playlistName);
};


#endif //CHATBOT_PLAYLIST_H
