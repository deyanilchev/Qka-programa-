#include <utility>

#include <utility>

#include <string>
#include "../enumerations/BookCategory.h"

using namespace std;

#ifndef DEYAN_BOOK_H
#define DEYAN_BOOK_H

struct Book {

    Book(BookCategory type = BookCategory::Unknown, string title = "", string author = "") : type(type),
                                                                                             title(title),
                                                                                             author(author) {
        this->type = type;
        this->title = std::move(title);
        this->author = std::move(author);
    }

    BookCategory type;
    string title;
    string author;
};

#endif