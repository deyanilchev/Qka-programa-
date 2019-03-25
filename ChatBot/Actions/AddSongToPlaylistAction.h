//
// Created by Vlado on 23-Mar-19.
//

#ifndef CHATBOT_ADDSONGTOPLAYLISTACTION_H
#define CHATBOT_ADDSONGTOPLAYLISTACTION_H


#include "Action.h"

class AddSongToPlaylistAction : public Action {
public:
    void execute(PlaylistsStore playlistsStore, SongsStore songsStore, UserStore userStore, User &user) override;
};


#endif //CHATBOT_ADDSONGTOPLAYLISTACTION_H
