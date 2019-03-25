

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

    explicit Playlist(string playlistName);

    Playlist(string name, vector<Song> songs);

    const string &getName() const;

    void setName(const string &name);

    const vector<Song> &getMusics() const;

    void addSong(Song &music);

    bool removeSongByIndex(int index);

    int size();

    string toString();
};


#endif //CHATBOT_PLAYLIST_H
