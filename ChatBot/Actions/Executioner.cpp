#include <utility>

//
// Created by Vlado on 23-Mar-19.
//

#include "Executioner.h"
#include "iostream"
#include "ShowPlayListsAction.h"
#include "CreatePlayListAction.h"
#include "AddSongToPlaylistAction.h"

using namespace std;

Executioner::Executioner(UserStore &userStore, SongsStore &songsStore, PlaylistsStore &playlistsStore1) : userStore(
        userStore),
                                                                                                          songsStore(
                                                                                                                  songsStore),
                                                                                                          playlistStore(
                                                                                                                  playlistsStore1) {

}

void Executioner::execute(string action, User &user) {
    ShowPlayListsAction showListsActions;
    CreatePlayListAction createPlayListAction;
    AddSongToPlaylistAction addSongToPlaylistAction;


    if (action == "a") {
        showListsActions.execute(playlistStore, songsStore, userStore, user);

        return;
    }

    if (action == "b") {
        createPlayListAction.execute(playlistStore, songsStore, userStore, user);

        return;
    }

    if (action == "c") {
        showListsActions.execute(playlistStore, songsStore, userStore, user);

        addSongToPlaylistAction.execute(playlistStore, songsStore, userStore, user);
        return;
    }
}
