#ifndef DEYAN_BOOKPILE_H_
#define DEYAN_BOOKPILE_H_

#include <vector>
#include "../structs/book.h"
#include "BookParser.h"

class BookPile {
public:
    void AddBook(Book ook);

    bool RemoveBook();

    Book GetNextBook();

    void ListAllBooks();

    int GetNumBooks();

protected:
    vector<Book> books;
    BookParser parser;
};

#endif