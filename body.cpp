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