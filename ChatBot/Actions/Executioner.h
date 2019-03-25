//
// Created by Vlado on 23-Mar-19.
//

#ifndef CHATBOT_EXECUTIONER_H
#define CHATBOT_EXECUTIONER_H


#include "../InformationStores/user/UserStore.h"
#include "../InformationStores/songs/SongsStore.h"
#include "../InformationStores/playlists/PlaylistsStore.h"

using namespace std;

class Executioner {
private:
    UserStore &userStore;
    SongsStore &songsStore;
    PlaylistsStore &playlistStore;
public:
    explicit Executioner(UserStore &userStore, SongsStore &songsStore, PlaylistsStore &playlistsStore1);

    void execute(string action, User& user);
};


#endif //CHATBOT_EXECUTIONER_H
