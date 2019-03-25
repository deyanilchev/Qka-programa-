//
// Created by Vlado on 23-Mar-19.
//

#ifndef CHATBOT_ACTION_H
#define CHATBOT_ACTION_H

#include "string"
#include "../InformationStores/playlists/PlaylistsStore.h"
#include "../InformationStores/songs/SongsStore.h"
#include "../InformationStores/user/UserStore.h"

using namespace std;

class Action {
public:
    virtual void execute(PlaylistsStore playlistsStore, SongsStore songsStore, UserStore userStore, User& user) = 0;
};


#endif //CHATBOT_ACTION_H
