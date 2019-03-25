

#ifndef CHATBOT_CREATEPLAYLISTACTION_H
#define CHATBOT_CREATEPLAYLISTACTION_H


#include "Action.h"

class CreatePlayListAction : public Action  {
public:
    void execute(PlaylistsStore &playlistsStore, UserStore &userStore, User &user) override;
};


#endif //CHATBOT_CREATEPLAYLISTACTION_H
