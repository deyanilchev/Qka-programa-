#include <iostream>
#include "BookBot.h"

bool BookBot::PickUpBook(BookPile &p) {
    if(p.GetNumBooks() == 0)
        return false;

    this->book = p.GetNextBook();
    this->isEmpty = false;
    p.RemoveBook();
    return true;
}

bool BookBot::PlaceDownBook(BookPile &p) {
    if(isEmpty)
        return false;

    isEmpty = true;
    p.AddBook(this->book);
    return true;
}

void BookBot::ListContents() {
    if(isEmpty) {
        cout << this->parser.BookToString(this->book);
    }
}
