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
};