#include "string"
using namespace std;

#ifndef DEYAN_BOOKCATEGORY_H
#define DEYAN_BOOKCATEGORY_H

enum class BookCategory {
    Biography = 0,
    History,
    Reference,
    Fiction,
    Unknown,
    NoMatter
};

#endif