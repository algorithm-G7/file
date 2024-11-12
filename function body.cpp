int partition(vector<File>& files, int low, int high, bool sortByName) {
    File pivot = files[high];
    int i = low - 1;

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