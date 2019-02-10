#include <iostream>
#include "BookPile.h"

bool BookPile::AddBook(Book book) {
    books.push_back(book);
    return true;
}

bool BookPile::RemoveBook() {
    if (books.empty())
        return false;

    books.pop_back();
    return true;
}

Book BookPile::GetNextBook() {
    if (books.empty()) {
        return Book();
    }

    Book book;
    Book returnedBook = books[books.size() - 1];

    book.title = returnedBook.title;
    book.author = returnedBook.author;

    return book;
}

void BookPile::ListAllBooks() {
    if (books.empty()) {
        cout << "[EMPTY]" << endl;
        return;
    }

    // This loops iterates through the vector's elements and prints them to the console
    for (int i = 0; i < books.size(); ++i) {
        cout << "Book " << i + 1 << " -> " << this->parser.BookToString(books[i]) << endl;
    }
}

int BookPile::GetNumBooks() {
    return books.size();
}
