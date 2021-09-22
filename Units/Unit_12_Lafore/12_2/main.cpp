#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {

    if (argc > 3) {
        cout << "Invalid input";
        return 0;
    }

    fstream file_to_copy, file_to_enter;

    file_to_copy.open(argv[1], ios::in);
    if (!file_to_copy) {
        cout << "Invalid input of " << argv[1] << " file";
        return 0;
    }
    file_to_copy.seekg(0);

    file_to_enter.open(argv[2], ios::out | ios::app);
    if (!file_to_enter) {
        cout << "Invalid input" << argv[2] << " file";
        return 0;
    }
    file_to_enter.seekg(0);

    char dummy_char;

    while(true){
        file_to_copy.get(dummy_char);

        if(!file_to_copy)
            break;

        file_to_enter.put(dummy_char);
    }

    cout << "Copied";
    return 0;
}
