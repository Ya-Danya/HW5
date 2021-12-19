#include "bookshelf.h"
#include <vector>

using std::vector;

Bookshelf::Bookshelf(int number_of_books, int index_of_row, int index) {
    books_number = number_of_books;
	row_index = index_of_row;
    number = index;
	vector<Book>::iterator iter = books.begin();
	for (int i = 0; i < number_of_books; i++) {
		iter = books.insert(iter, Book(row_index, number, i + 1));
		++iter;
	}
}

int Bookshelf::getBooksNumber() {
	return books_number;
}

vector<Book> Bookshelf::getBooks() {
	return books;
}
