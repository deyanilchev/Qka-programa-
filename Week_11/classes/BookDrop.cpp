//
// Created by Vlado on 10-Feb-19.
//

#include "BookDrop.h"
#include "iostream"
using namespace std;


void BookDrop::CheckIn() {
    string category;
    string title;
    string author;

    cout << "Enter book category(if the category does not exist book will be created as Unknown category)" << endl;
    cin >> category;

    cout << "Enter book title" << endl;
    cin >> title;

    cout << "Enter book author" << endl;
    cin >> author;

    Book book(parser.stringToBookCategory(category), title, author);

    this->AddBook(book);
}

void BookDrop::CheckOut() {
    this->books.clear();
}
