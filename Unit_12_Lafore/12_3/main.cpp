#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {
    if(argc != 2){
        cerr << "Invalid input";
        return -1;
    }

    ifstream check_size_file;

    check_size_file.open(argv[1]);
    if(!check_size_file){
        cerr << "Invalid file name input";
        return -1;
    }

    check_size_file.seekg(0, ios::end);
    cout << endl << "File length: " << check_size_file.tellg() << endl;

    check_size_file.close();
    return 0;
}