#include <utility>

#include <utility>

#include <string>
#include "../enumerations/BookCategory.h"

using namespace std;

#ifndef DEYAN_BOOK_H
#define DEYAN_BOOK_H

struct Book {

    Book(BookCategory category1 = BookCategory::Unknown, string title = "", string author = "") : category(category1),
                                                                                             title(title),
                                                                                             author(author) {
        this->category = category1;
        this->title = std::move(title);
        this->author = std::move(author);
    }

    BookCategory category;
    string title;
    string author;
};

#endif