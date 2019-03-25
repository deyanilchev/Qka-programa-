

#ifndef CHATBOT_SHOWPLAYLISTSACTION_H
#define CHATBOT_SHOWPLAYLISTSACTION_H


#include "Action.h"

class ShowPlayListsAction : public Action {
public:
    void execute(PlaylistsStore &playlistsStore, UserStore &userStore, User &user) override;
};


#endif //CHATBOT_SHOWPLAYLISTSACTION_H
