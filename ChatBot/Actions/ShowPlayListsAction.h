//
// Created by Vlado on 23-Mar-19.
//

#ifndef CHATBOT_SHOWPLAYLISTSACTION_H
#define CHATBOT_SHOWPLAYLISTSACTION_H


#include "Action.h"

class ShowPlayListsAction : public Action {
public:
    void execute(PlaylistsStore playlistsStore, SongsStore songsStore, UserStore userStore, User& user) override;
};


#endif //CHATBOT_SHOWPLAYLISTSACTION_H
