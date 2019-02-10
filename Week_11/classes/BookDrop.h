//
// Created by Vlado on 10-Feb-19.
//

#ifndef DEYAN_BOOKDROP_H
#define DEYAN_BOOKDROP_H


#include "BookBot.h"

class BookDrop : public BookPile {
public:
    void CheckIn();
    void CheckOut();

private:
    BookParser parser;
};


#endif //DEYAN_BOOKDROP_H
