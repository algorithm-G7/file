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