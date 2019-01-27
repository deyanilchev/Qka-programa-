#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
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
    BookPile pile;

    // Expecting a list of no items
    // ( expecting no output )
    cout << " Test 2: Empty BookPile " << endl;
    cout << "   a) Method GetNumBooks() should return 0" << endl;
    if (pile.GetNumBooks() == 0) {
        cout << "       Test passed" << endl;
    } else {
        cout << "       Test failed" << endl;
    }

    // Expecting listing the content of the BookPile to produce no output
    cout << " Test 3: Listing an empty BookPile" << endl;
    cout << "   a) Method ListAllBooks() should return no output" << endl;
    pile.ListAllBooks();


    cout << " Test 4: Adding a book" << endl;
    cout << "   a) Adding a book should result in that book's title being shown when ListAllBooks is called." << endl;
    Book book;
    book.author = "Jk. Rollings";
    book.title = "Harry Potter";

    pile.AddBook(book);

    pile.ListAllBooks();

    cout << " Test 5: Adding more Books should not affect those already on the BookPile" << endl;
    cout << "   a) Adding a second book should result in both books names being printed" << endl;
    // тип име;
    // име.полетоКоетоТиТрябва = нещото което искаш да е равно;

    Book anotherBook;
    anotherBook.author = "Steven King";
    anotherBook.title = "Scary book";

    pile.AddBook(anotherBook);

    pile.ListAllBooks();

    cout << "   b) GetNumBooks() should return 2" << endl;
    if (pile.GetNumBooks() == 2) {
        cout << "Test passed" << endl;
    } else {
        cout << "Test failed" << endl;
    }

    cout << " Test 6: Removing a book should remove the last book inside the BookPile object" << endl;
    pile.RemoveBook();
    cout << "   a) PileListAllBooks() should print only Harry Potter" << endl;
    pile.ListAllBooks();

    cout << "   b) GetNumBooks() should return a size decreased by 1" << endl;
    if (pile.GetNumBooks() == 1) {
        cout << "Test passed" << endl;
    } else {
        cout << "Test failed" << endl;
    }

    cout << " Test 7: Creating a new BookPile should not affect the first one." << endl;
    BookPile secondPile;
    cout << "   a) Calling PrintAllBooks() in the second BookPile should return no output" << endl;
    secondPile.ListAllBooks();
    cout << "   b) Calling PrintAllBooks() in the first BookPile should return its last state" << endl;
    pile.ListAllBooks();

    cout << " Test 8: GetNextBook() should return a copy of the object at the top of the pile" << endl;
    cout << "   a) GetNextBook() returns a copy of the object" << endl;
    Book returnedBook = pile.GetNextBook();
    returnedBook.title = "Wrong Title";
    cout
            << "   b) Listing all books in the book pile should return the old titles and \"Wrong Title\" should not appear in the output"
            << endl;
    pile.ListAllBooks();

    cout << " Test 9: Listing the contents of the BookPile should not affect its content" << endl;
    cout << "   a) Listing the content should not affect its size" << endl;
    int oldSize = pile.GetNumBooks();

    pile.ListAllBooks();

    if (oldSize == pile.GetNumBooks()) {
        cout << "Test passed" << endl;
    } else {
        cout << "Test failed" << endl;
    }

    cout << "   b) Double printing should result in the same output as before" << endl;
    pile.ListAllBooks();

    cout << " Test 10: GetNextBook() should not affect the contents of the BookPile" << endl;
    int oldSize1 = pile.GetNumBooks();
    cout << "   a) Listing the BookPile before and after GetNextBook() should result in the same output" << endl;
    pile.ListAllBooks();

    Book b = pile.GetNextBook();

    pile.ListAllBooks();

    cout << "   b) GetNextBook() should not affect the size of the BookPile" << endl;
    if (oldSize1 == pile.GetNumBooks()) {
        cout << "Test passed" << endl;
    } else {
        cout << "Test failed" << endl;
    }

    cout << " Test: 11: Removing a book from a BookPile should return true or false" << endl;
    cout << "   a) Successfully removing an element should return true" << endl;
    BookPile somePile;
    somePile.AddBook(book);

    if (somePile.RemoveBook()) {
        cout << "Test passed" << endl;
    } else {
        cout << "Test failed" << endl;
    }

    cout << "   b) Failing to remove an element from an empty BookPile should not result in a program crash" << endl;
    BookPile emptyBookPile;

    if(!emptyBookPile.RemoveBook()) {
        cout << "Test passed" << endl;
    } else {
        cout << "Test failed" << endl;
    }

    cout << " Test 12: Getting a book from an empty BookPile should not result in a program crash" << endl;
    cout << emptyBookPile.GetNextBook().title;
    return 0;
}