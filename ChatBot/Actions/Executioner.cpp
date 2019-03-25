#include <utility>


#include "Executioner.h"
#include "iostream"
#include "ShowPlayListsAction.h"
#include "CreatePlayListAction.h"
#include "AddSongToPlaylistAction.h"
#include "RemoveSongFromPlaylistAction.h"
#include "DeletePlaylistAction.h"

using namespace std;

Executioner::Executioner(UserStore &userStore, PlaylistsStore &playlistsStore1) : userStore(userStore),
                                                                                  playlistStore(
                                                                                          playlistsStore1) {

}

void Executioner::execute(string action, User &user) {
    ShowPlayListsAction showListsActions;
    CreatePlayListAction createPlayListAction;
    AddSongToPlaylistAction addSongToPlaylistAction;
    RemoveSongFromPlaylistAction removeSongFromPlaylistAction;
    DeletePlaylistAction deletePlaylistAction;


    if (action == "a") {
        showListsActions.execute(playlistStore, userStore, user);

        return;
    }

    if (action == "b") {
        createPlayListAction.execute(playlistStore, userStore, user);

        return;
    }

    if (action == "c") {
        showListsActions.execute(playlistStore, userStore, user);

        addSongToPlaylistAction.execute(playlistStore, userStore, user);
        return;
    }

    if (action == "d") {
        showListsActions.execute(playlistStore, userStore, user);

        removeSongFromPlaylistAction.execute(playlistStore, userStore, user);

        return;
    }

    if (action == "e") {
        showListsActions.execute(playlistStore, userStore, user);

        deletePlaylistAction.execute(playlistStore, userStore, user);

        return;
    }
}
