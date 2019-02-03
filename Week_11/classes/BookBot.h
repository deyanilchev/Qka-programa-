#ifndef DEYAN_BOOKBOT_H_
#define DEYAN_BOOKBOT_H_

#include "BookPile.h"

class BookBot {
public:
    bool PickUpBook(BookPile &p);

    bool PlaceDownBook(BookPile &p);

    void ListContents();

private:
    Book book;
    bool isEmpty = true;
    BookParser parser;
};

#endif