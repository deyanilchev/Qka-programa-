//
// Created by Vlado on 10-Feb-19.
//

#include "StoragePile.h"

StoragePile::StoragePile() {

    // Creates a StoragePile of type NoMatter so that every kind of book can  be added if no type is specified
    this->category = BookCategory::NoMatter;
}

StoragePile::StoragePile(string category) {
    this->category = parser.stringToBookCategory(category);
}

StoragePile::StoragePile(BookCategory category) {
    this->category = category;
}

bool StoragePile::AddBook(Book b) {

    // Adds every book if no type is specified
    if (this->category == BookCategory::NoMatter)
        return BookPile::AddBook(b);

    if (this->category != b.category)
        return false;

    // Uses the parent method so that we can reuse already working and tested code
    return BookPile::AddBook(b);
}
