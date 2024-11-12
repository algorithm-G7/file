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

void displayFiles(const vector<File>& files) {
    for (const auto& file : files) {
        file.display();
    }
}

int linearSearch(const vector<File>& files, const string& name) {
    for (size_t i = 0; i < files.size(); ++i) {
        if (files[i].name == name) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<File>& files, const string& name) {
    int left = 0;
    int right = files.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (files[middle].name == name) {
            return middle;
        }
        if (files[middle].name < name) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}

int partition(vector<File>& files, int low, int high, bool sortByName) {
    File pivot = files[high];
    int i = low -1;

    for (int j = low; j < high; ++j) {
        if (sortByName) {
            if (files[j].name < pivot.name) {
                swap(files[++i], files[j]);
            }
        } else {
            if (files[j].size < pivot.size) {
                swap(files[++i], files[j]);
            }
        }
    }
    swap(files[++i], files[high]);
    return i;
}

void quickSort(vector<File>& files, int low, int high, bool sortByName) {
    if (low < high) {
        int pi = partition(files, low, high, sortByName);
        quickSort(files, low, pi - 1, sortByName);
        quickSort(files, pi + 1, high, sortByName);
    }
}

void menu(vector<File>& files) {
    while (true) {
        cout << "\n Welcome  To The System \n";
        cout << "     Menu:\n";
        cout << "1. Display Files\n";
        cout << "2. Search File by Name (Linear Search)\n";
        cout << "3. Search File by Name (Binary Search)\n";
        cout << "4. Sort Files by Name\n";
        cout << "5. Sort Files by Size\n";
        cout << "6. Add New File\n";
        cout << "7. Delete File by Name\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displayFiles(files);
                break;
            case 2: {
                cout << "Enter file name to search: ";
                string name;
                cin >> name;
                int index = linearSearch(files, name);
                if (index != -1) {
                    cout << "File found: ";
                    files[index].display();
                } else {
                    cout << "File not found.\n";
                }
                break;
            }
            case 3: {
                cout << "Enter file name to search: ";
                string name;
                cin >> name;
                int index = binarySearch(files, name);
                if (index != -1) {
                    cout << "File found: ";
                    files[index].display();
                } else {
                    cout << "File not found.\n";
                }
                break;
            }
            case 4:
                quickSort(files, 0, files.size() - 1, true);
                cout << "Files sorted by name.\n";
                break;
            case 5:
                quickSort(files, 0, files.size() - 1, false);
                cout << "Files sorted by size.\n";
                break;
            case 6: {
                cout << "Enter new file name: ";
                string newName;
                cin >> newName;
                cout << "Enter new file size (KB): ";
                int newSize;
                cin >> newSize;
                files.push_back(File(newName, newSize));
                cout << "File added.\n";
                break;
            }
            case 7: {
                cout << "Enter file name to delete: ";
                string deleteName;
                cin >> deleteName;
                int index = linearSearch(files, deleteName);
                if (index != -1) {
                    files.erase(files.begin() + index);
                    cout << "File deleted.\n";
                } else {
                    cout << "File not found.\n";
                }
                break;
            }
            case 8:
                cout << "Exiting the program.\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    vector<File> files = {
        File("file1.txt", 125),
        File("file2.txt", 256),
        File("file3.txt", 1024),
        File("file4.txt", 100)
    };

    menu(files);
     return 0;
}
