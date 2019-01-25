#include <iostream>
#include "BookPile.h"

void BookPile::AddBook(Book b) {

}

void BookPile::RemoveBook() {

}

Book BookPile::GetNextBook() {
    return Book();
}

void BookPile::ListAllBooks() {
    if(books.empty()) {
        cout << "[EMPTY]" << endl;
        return;
    }

    // TODO: LIST ALL BOOKS
}

int BookPile::GetNumBooks() {
    return 0;
}
