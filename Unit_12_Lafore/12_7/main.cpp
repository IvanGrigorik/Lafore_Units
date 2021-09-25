#include <iostream>
#include <fstream>

using namespace std;

class Employee {
private:
    string name{};
    string last_name{};
    string patronymic{};
    int number{};
    static fstream file;

public:

    Employee () : name(), last_name(), patronymic(), number() {};

    static void open_file () {
        file.open("test.txt", ios::in | ios::out | ios::app);
    }

    static void dump_file () {
        file.seekg(0);
    }

    static void close_file () {
        file.close();
    }

    friend istream &operator>> (istream &in, Employee &data) {
        in >> data.name >> data.last_name >> data.patronymic >> data.number;
        return in;
    }

    friend ostream &operator<< (ostream &out, Employee &data) {
        out << data.name << " " << data.last_name << " " << data.patronymic << " " << data.number << endl;
        return out;
    }

    void write_file () {
        file << *this;
    }

    void read_file (int number_to_search) {
        dump_file();
        for (int i = 0; i < number_to_search; i++)
            file >> *this;
    }
};

fstream Employee::file;

int main () {
    Employee emp;
    Employee::open_file();

    char dummy_char = 'y';
    while (true) {
        cout << "Enter name, last name, patronymic and number: ";
        cin >> emp;
        emp.write_file();

        cout << "Continue? (y/n): ";
        cin >> dummy_char;
        if (dummy_char != 'y')
            break;
    }

    int num = 0;
    cout << "Enter number to find: ";
    cin >> num;
    emp.read_file(num);
    cout << emp;

    Employee::close_file();
}
