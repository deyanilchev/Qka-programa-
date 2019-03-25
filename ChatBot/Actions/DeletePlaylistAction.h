//
// Created by Vlado on 25-Mar-19.
//

#ifndef CHATBOT_DELETEPLAYLISTACTION_H
#define CHATBOT_DELETEPLAYLISTACTION_H


#include "Action.h"

class DeletePlaylistAction : public Action{
public:
    void execute(PlaylistsStore &playlistsStore, UserStore &userStore, User &user) override;
};


#endif //CHATBOT_DELETEPLAYLISTACTION_H
