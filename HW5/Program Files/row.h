#include "bookshelf.h"
#include <vector>

using std::vector;

class Row {
public:
    vector<Bookshelf> getBookshelves();
    int getBookshelvesNumber();
    Row(int, int, int);
    ~Row() {};
private:
    vector<Bookshelf> bookshelves;
    int bookshelves_number;
    int number;
};
