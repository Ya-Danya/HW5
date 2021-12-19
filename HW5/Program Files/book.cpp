#include "book.h"
#include "rnd.h"

Book::Book(int rowNumber, int shelfNumber, int index) {
    this->author = Rnd::rndString();
    this->name = Rnd::rndString();
    this->shelfNumber = shelfNumber;
    this->rowNumber = rowNumber;
    this->number = index;
}

string Book::toString() {
    return "The book named: " + name + " Author: " + author + "stored in a row: "
        + std::to_string(rowNumber) + " in a shelf number: " + std::to_string(shelfNumber) 
        + " with number " + std::to_string(number);
}