

#ifndef CHATBOT_EXECUTIONER_H
#define CHATBOT_EXECUTIONER_H


#include "../InformationStores/user/UserStore.h"
#include "../InformationStores/playlists/PlaylistsStore.h"

using namespace std;

class Executioner {
private:
    UserStore &userStore;
    PlaylistsStore &playlistStore;
public:
    explicit Executioner(UserStore &userStore, PlaylistsStore &playlistsStore1);

    void execute(string action, User &user);
};


#endif //CHATBOT_EXECUTIONER_H
