//
// Created by Vlado on 23-Mar-19.
//

#ifndef CHATBOT_CREATEPLAYLISTACTION_H
#define CHATBOT_CREATEPLAYLISTACTION_H


#include "Action.h"

class CreatePlayListAction : public Action  {
public:
    void execute(PlaylistsStore playlistsStore, SongsStore songsStore, UserStore userStore, User &user) override;
};


#endif //CHATBOT_CREATEPLAYLISTACTION_H
