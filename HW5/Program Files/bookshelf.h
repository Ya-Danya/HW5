#include "book.h"
#include <vector>

using std::vector;

class Bookshelf {
public:
    Bookshelf(int, int, int);
    int getBooksNumber();
    vector<Book> getBooks();
    ~Bookshelf() {};
private:
    vector<Book> books;
    int row_index;
    int books_number;
    int number;
};
