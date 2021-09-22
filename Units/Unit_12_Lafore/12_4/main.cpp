#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main () {
    string name;
    string last_name;
    unsigned long number;
    char dummy_char;

    ofstream out_file("test.txt", ios::trunc);

    while (true) {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter last name: ";
        cin >> last_name;
        cout << "Enter number: ";
        cin >> number;

        out_file << name << " " << last_name << " " << number << endl;

        cout << endl << "Do you want to continue? (y/n): ";
        cin >> dummy_char;
        if (dummy_char == 'n')
            break;
    }

    ifstream in_file("test.txt");

    while(in_file){
        in_file >> name >> last_name >> number;
        if(!in_file)
            break;
        cout << name << " " << last_name << " " << number << endl;
    }
}