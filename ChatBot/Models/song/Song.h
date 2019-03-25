

#ifndef CHATBOT_MUSIC_H
#define CHATBOT_MUSIC_H

#include "string"

using namespace std;

class Song {
private:
    string artist;
    string name;

public:
    Song(string artist, string name);

    explicit Song() = default;

    const string &getArtist() const;

    void setArtist(const string &artist);

    const string &getName() const;

    void setName(const string &name);

    string toString();
};


#endif //CHATBOT_MUSIC_H
