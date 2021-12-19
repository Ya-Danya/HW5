#include <string>

using std::string;

class Rnd {
public:
    static string rndString() {
        int length = rand() % 20 + 1;
        char* stringToReturn = new char[length];
        for (int i = 0; i < length; ++i) {
            stringToReturn[i] = rand() % 25 + 66;
        }
        return string(stringToReturn);
    }
};