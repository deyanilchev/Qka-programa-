//
// Created by Vlado on 03-Feb-19.
//

#include "BookParser.h"

const char *array[] = {"Biography",
                       "History",
                       "Reference",
                       "Fiction",
                       "Unknown"};

template<typename Enumeration>
auto as_integer(Enumeration const value)
-> typename std::underlying_type<Enumeration>::type {
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}


string BookParser::BookToString(Book book) {
    string result = "Title: " + book.title + ", Category: " + array[as_integer(book.type)];

    return result;
}
