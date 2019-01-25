#include "../structs/book.h"
#include <vector>

class BookPile {
public:
    void AddBook(Book b);

    void RemoveBook();

    Book GetNextBook();

    void ListAllBooks();

    int GetNumBooks();

protected:
    vector<Book *> books;
};

