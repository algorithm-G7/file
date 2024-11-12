#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class File {
public:
    string name;
    int size;

    File(string name, int size) {
        this->name = name;
        this->size = size;
    }

    void display() const {
        cout << name << " (" << size << "KB)" << endl;
    }
};
