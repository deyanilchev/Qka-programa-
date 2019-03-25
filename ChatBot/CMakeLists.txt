cmake_minimum_required(VERSION 3.13)
project(ChatBot)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChatBot main.cpp InformationStores/user/UserStore.cpp InformationStores/user/UserStore.h Models/user/User.cpp Models/user/User.h Models/playlist/Playlist.cpp Models/playlist/Playlist.h Models/song/Song.cpp Models/song/Song.h IO/IOOperations.cpp IO/IOOperations.h InformationStores/songs/SongsStore.cpp InformationStores/songs/SongsStore.h InformationStores/playlists/PlaylistsStore.cpp InformationStores/playlists/PlaylistsStore.h Actions/Action.cpp Actions/Action.h Actions/Executioner.cpp Actions/Executioner.h Actions/ShowPlayListsAction.cpp Actions/ShowPlayListsAction.h Actions/CreatePlayListAction.cpp Actions/CreatePlayListAction.h Actions/AddSongToPlaylistAction.cpp Actions/AddSongToPlaylistAction.h)