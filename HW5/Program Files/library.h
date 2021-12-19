#include "row.h"
#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Library {
public:
    Book getTask();
    bool tasksEmpty();
    Library(int, int, int);
    Library() : Library(0, 0, 0) {};
    ~Library() {};
private:
    void makeTasks();
    vector<Row> rows;
    queue<Book> tasks;
    int rows_number;
};
