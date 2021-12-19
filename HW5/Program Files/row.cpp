#include "row.h"

vector<Bookshelf> Row::getBookshelves() {
	return bookshelves;
}

int Row::getBookshelvesNumber() {
	return bookshelves_number;
}

Row::Row(int number_of_bookshelves, int number_of_books, int index) {
	number = index;
	bookshelves_number = number_of_bookshelves;
	vector<Bookshelf>::iterator iter = bookshelves.begin();
	for (int i = 0; i < number_of_bookshelves; i++) {
		iter = bookshelves.insert(iter, Bookshelf(number_of_books, number, i + 1));
		++iter;
	}
}