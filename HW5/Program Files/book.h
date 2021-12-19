#include <string>

using std::string;

class Book {
public:
    Book(int, int, int);
    string toString();
    Book() :Book(0, 0, 0) {};
private:
    string author;
    string name;
    int shelfNumber;
    int rowNumber;
    int number;
};