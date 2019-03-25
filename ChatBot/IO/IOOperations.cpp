#include <utility>

//
// Created by Vlado on 23-Mar-19.
//

#include "IOOperations.h"
#include <fstream>
#include <ctime>
#include "iostream"
#include <regex>

using namespace std;

IOOperations::IOOperations(UserStore &userStore,
                           SongsStore &songsStore,
                           PlaylistsStore &playlistStore1) : userStore(userStore),
                                                             songsStore(songsStore),
                                                             playlistStore(playlistStore1) {

}

void IOOperations::loadAppInfo() {
    loadUsers();

    loadSongs();

    loadPlaylists();
}

void IOOperations::loadUsers() {
    FILE *reader;

    reader = fopen(R"(C:\Andrian\Programing\Uchilishte\Deyan\ChatBot\user.bin)", "r");

    char firstName[99];
    char secondName[99];
    int age;
    long long id;
    while (!feof(reader)) {
        fscanf(reader, "%lld %s %s %d", &id, firstName, secondName, &age);
        User user(id, firstName, secondName, age);

        userStore.addUser(user);
    }

    fclose(reader);
}

void IOOperations::loadSongs() {
    string line;
    ifstream myfile(R"(C:\Andrian\Programing\Uchilishte\Deyan\ChatBot\songs.bin)");

    string artistName;
    string songName;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            std::regex r("^([\\w+0-9 ]+)( - )([\\w+0-9 ]+)$");
            std::smatch matches;
            std::regex_search(line, matches, r);

            // SHOULD NEVER HAPPEN
            if (matches.empty()) {
                continue;
            }

            artistName = matches[1];
            songName = matches[3];

            Song song(artistName, songName);
            songsStore.addSong(song);
        }
    }

}

void IOOperations::loadPlaylists() {
    string line;
    ifstream myfile(R"(C:\Andrian\Programing\Uchilishte\Deyan\ChatBot\playlists.bin)");


    User* user;
    Playlist playlist;
    vector<Song> songs;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            std::regex r("^(\\d+) - ([a-zA-Z1-9]+) - (.+)$");
            std::smatch matches;
            std::regex_search(line, matches, r);
//            for(auto v: matches) std::cout << v << std::endl;

            // SHOULD NEVER HAPPEN
            if (matches.empty()) {
                continue;
            }

            user = &parseUserId(matches);
            songs = parsePlaylistSongs(matches);

            playlist = parsePlaylist(matches, songs);
            playlistStore.addPlaylist(playlist);

            user->addPlaylist(playlist);
        }

        myfile.close();
    }

}

User& IOOperations::parseUserId(smatch matches) {
    long long userId;
    char *pEnd;
    char idAsCharArray[matches[1].str().length()];
    strcpy(idAsCharArray, matches[1].str().c_str());

    userId = std::strtoll(idAsCharArray, &pEnd, 10);

    for (int i = 0; i < userStore.getUsers().size(); ++i) {
        if (userStore.getUser(i).getId() == userId)
            return userStore.getUser(i);
    }

    // SHOULD NOT HAPPEN :D
}

Playlist IOOperations::parsePlaylist(smatch matches, vector<Song> vector1) {
    return Playlist(matches[2], std::move(vector1));
}

vector<Song> IOOperations::parsePlaylistSongs(smatch results) {
    vector<Song> songs;

    string line = results[3];

    std::regex r("([\\w+0-9 ]+)( - )([\\w+0-9 ]+), *");
    std::smatch matches;

    string::const_iterator searchStart(line.cbegin());
    while (regex_search(searchStart, line.cend(), matches, r)) {
        songs.push_back(songsStore.findSongByWholeName(matches[1].str() + " - " + matches[3].str()));
        searchStart = matches.suffix().first;
    }

    return songs;
}

