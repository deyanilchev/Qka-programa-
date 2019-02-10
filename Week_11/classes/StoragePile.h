//
// Created by Vlado on 10-Feb-19.
//

#ifndef DEYAN_STORAGEPILE_H
#define DEYAN_STORAGEPILE_H


#include "BookPile.h"

class StoragePile : public BookPile {
private:
    BookCategory category;
    BookParser parser;

public:
    StoragePile();

    explicit StoragePile(string category);

    explicit StoragePile(BookCategory category);

    bool AddBook(Book b) override;
};


#endif //DEYAN_STORAGEPILE_H
