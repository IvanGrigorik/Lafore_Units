#include <iostream>
#include <fstream>

using namespace std;

class Employee {
private:
    string name{};
    string patronymic{};
    int number;

public:
    Employee () : name(), patronymic(), number() {};w

    friend istream &operator>> (istream &in, Employee &data) {
        in >> data.name >> data.patronymic >> data.number;
        return in;
    }

    friend ostream &operator<< (ostream &out, Employee &data) {
        out << data.name << " " << data.patronymic << " " << data.number << endl;
        return out;
    }

    void write_file () {
        ofstream out("test.txt", ios::app);
        out << *this;
        out.close();
    }

    void read_file (int number_to_search) {
        ifstream in("test.txt");

        for(int i = 0; i < number_to_search; i++)
            in >> *this;
        in.close();
    }
};

int main(){
    Employee emp;

    char dummy_char = 'y';
    while(true){
        cout << "Enter name, patronymic and number: ";
        cin >> emp;
        emp.write_file();

        cout << "Continue? (y/n): ";
        cin >> dummy_char;
        if(dummy_char != 'y')
            break;
    }

    int num = 0;
    cout << "Enter number to find: ";
    cin >> num;
    emp.read_file(num);
    cout << emp;
}