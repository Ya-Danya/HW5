#include "library.h"

Library::Library(int number_of_rows, int number_of_bookshelves, int number_of_books) {
    vector<Row>::iterator iter = rows.begin();
    rows_number = number_of_rows;
    for (size_t i = 0; i < number_of_rows; i++) {
        iter = rows.insert(iter, Row(number_of_bookshelves, number_of_books, i + 1));
        ++iter;
    }
    makeTasks();
}

void Library::makeTasks() {
    for (int i = 0; i < rows_number; i++) {
        for (int j = 0; j < rows[i].getBookshelvesNumber(); j++) {
            for (int k = 0; k < rows[i].getBookshelves()[j].getBooksNumber(); k++) {
                tasks.push(rows[i].getBookshelves()[j].getBooks()[k]);
            }
        }
    }
}

Book Library::getTask() {
    Book task = tasks.front();
    tasks.pop();
    return task;
}


bool Library::tasksEmpty() {
    return tasks.empty();
}