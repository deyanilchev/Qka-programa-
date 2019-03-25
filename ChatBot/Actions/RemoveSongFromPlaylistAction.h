//
// Created by Vlado on 25-Mar-19.
//

#ifndef CHATBOT_REMOVESONGFROMPLAYLISTACTION_H
#define CHATBOT_REMOVESONGFROMPLAYLISTACTION_H


#include "Action.h"

class RemoveSongFromPlaylistAction : public Action {
public:
    void execute(PlaylistsStore &playlistsStore, UserStore &userStore, User &user) override;
};


#endif //CHATBOT_REMOVESONGFROMPLAYLISTACTION_H
