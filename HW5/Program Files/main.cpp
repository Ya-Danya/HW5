#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <vector>
#include "library.h"

Library library;
std::mutex task_getting_mutex, catalogue_mutex, logging_mutex;
int counter;

void addNewBook() {
    task_getting_mutex.lock();
    bool finished = library.tasksEmpty();
    Book new_book ;
    if (!finished) {
        new_book = library.getTask();
    }
    task_getting_mutex.unlock();
    if (!finished) {
        logging_mutex.lock();
        std::cout << "Student " << std::this_thread::get_id()
            << " adds book " << new_book.toString() << "\n";
        logging_mutex.unlock();
        catalogue_mutex.lock();
        catalogue_mutex.unlock();
    } 
}

void errMessage() {
    std::cout << "incorrect command line!\n"
        "  Waited:\n"
        "     command <library: number of rows> <row: number of bookshelves> <bookshelf: number of books> <number of students>\n"
        "  Or:\n"
        "     command <library: number of rows> <row: number of bookshelves> <bookshelf: number of books>\n"
        "  Or:\n"
        "     command <library: number of students>\n"
        "  Or:\n"
        "     command";
}

int main(int argc, char* argv[]) {
    if (argc > 5) {
        errMessage();
        return 1;
    }
    std::cout << "Starting program\n";
    unsigned int start_time = clock();
    int number_of_rows, number_of_bookshelves, number_of_books, number_of_students;
    counter = 0;
    if (argc == 5) {
        number_of_rows = atoi(argv[1]);
        number_of_bookshelves = atoi(argv[2]);
        number_of_books = atoi(argv[3]);
        number_of_students = atoi(argv[4]);
        if (number_of_rows < 1 || number_of_bookshelves < 1 || number_of_books < 1 || number_of_students < 1) {
            errMessage();
            return 1;
        }
    }
    else if (argc == 4) {
        number_of_rows = atoi(argv[1]);
        number_of_bookshelves = atoi(argv[2]);
        number_of_books = atoi(argv[3]);
        number_of_students = 10;
        if (number_of_rows < 1 || number_of_bookshelves < 1 || number_of_books < 1) {
            errMessage();
            return 1;
        }
    }
    else if (argc == 2) {
        number_of_rows = 1;
        number_of_bookshelves = 1;
        number_of_books = 1;
        number_of_students = atoi(argv[1]);
        if (number_of_students < 1) {
            errMessage();
            return 1;
        }
    }
    else if (argc == 1) {
        number_of_rows = 10;
        number_of_bookshelves = 10;
        number_of_books = 10;
        number_of_students = 10;
    }
    else {
        errMessage();
        return 0;
    }
    library = Library(number_of_rows, number_of_bookshelves, number_of_books);

    std::vector<std::thread> students;
    std::vector <std::thread>::iterator iter = students.begin();
    for (int i = 0; i < number_of_students; ++i) {
        auto seek = []() {
            task_getting_mutex.lock();
            bool finished = library.tasksEmpty();
            task_getting_mutex.unlock();
            while (!finished) {
                addNewBook();
                task_getting_mutex.lock();
                finished = library.tasksEmpty();
                task_getting_mutex.unlock();
            }
        };
        iter = students.insert(iter, std::thread(seek));
        ++iter;
    }

    for (int i = 0; i < number_of_students; ++i) {
        students[i].join();
    }
    std::cout << "Program finished in " << clock() - start_time << " seconds";
    return 0;
}