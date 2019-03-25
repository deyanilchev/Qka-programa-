#include <utility>

//
// Created by Vlado on 23-Mar-19.
//

#include "Song.h"

const string &Song::getArtist() const {
    return artist;
}

void Song::setArtist(const string &artist) {
    Song::artist = artist;
}

const string &Song::getName() const {
    return name;
}

void Song::setName(const string &name) {
    Song::name = name;
}

Song::Song(string artist, string name) : artist(std::move(artist)), name(std::move(name)) {

}
