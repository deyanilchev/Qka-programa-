

#ifndef CHATBOT_ACTION_H
#define CHATBOT_ACTION_H

#include "string"
#include "../InformationStores/playlists/PlaylistsStore.h"
#include "../InformationStores/user/UserStore.h"

using namespace std;

class Action {
public:
    virtual void execute(PlaylistsStore &playlistsStore, UserStore &userStore, User &user) = 0;
};


#endif //CHATBOT_ACTION_H
