#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include "structs/book.h"
#include "classes/BookPile.h"

using namespace std;


void PrintBook(Book b) {
    // Prints a string like
    // " The Use of Lemons in Science " by Cave Johnson

    std::cout << "\"" // literal quotemark
              << b.title << "\" by "
              << b.author
              << std::endl;

    string a;
}

int main() {

    // The beginnings of a test plan
    // Create a new pile
    // ( expecting no output )
    cout << " Test 1: Create pile " << endl;
    BookPile p;

    // Expecting a list of no items
    // ( expecting no output )
    cout << " Test 2: Empty BookPile " << endl;
    cout << "   a) Method GetNumBooks() should return 0" << endl;
    if (p.GetNumBooks() == 0) {
        cout << "       Test passed" << endl;
    } else {
        cout << "       Test failed" << endl;
    }

    // Expecting listing the content of the BookPile to produce no output
    cout << " Test 3: Listing an empty BookPile" << endl;
    cout << "   a) Method ListAllBooks() should return no output" << endl;
    p.ListAllBooks();

    return 0;
}