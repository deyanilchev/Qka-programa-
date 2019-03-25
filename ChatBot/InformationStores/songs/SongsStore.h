//
// Created by Vlado on 23-Mar-19.
//

#ifndef CHATBOT_SONGSSTORE_H
#define CHATBOT_SONGSSTORE_H


#include <vector>
#include "../../Models/song/Song.h"

class SongsStore {
private:
    vector<Song> songs;
public:
    int size();

    void addSong(Song song);

    Song findSongByWholeName(string wholeName);

    const vector<Song> &getSongs() const;
};


#endif //CHATBOT_SONGSSTORE_H
