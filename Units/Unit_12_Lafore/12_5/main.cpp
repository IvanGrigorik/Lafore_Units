#include <iostream>

using namespace std;

class Time {
private:
    static int number;
    int hours{};
    int minutes{};
    int seconds{};

public:
    Time () = default;

    void get_time ();

    void put_time () const;

    static int get_amount ();
};

int Time::number;



// rofl lmao
void Time::get_time () {
    while (true) {
        cout << "Enter hours: ";
        cin >> hours;
        if (cin.fail() || hours > 23 || hours < 0) {
            cout << "Invalid hours input!";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        break;
    }

    while (true) {
        cout << "Enter minutes: ";
        cin >> minutes;
        if (cin.fail() || minutes > 59 || minutes < 0) {
            cout << "Invalid minutes input!";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        break;
    }
    while (true) {
        cout << "Enter seconds: ";
        cin >> seconds;
        if (cin.fail() || seconds > 59 || seconds < 0) {
            cout << "Invalid seconds input!";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        break;
    }

    cin.ignore(1000, '\n');
    number++;
}


void Time::put_time () const {
    cout << endl << hours << ":" << minutes << ":" << seconds << endl;
}

int Time::get_amount () {
    return Time::number;
}

int main () {
    Time time_arr[30];
    char dummy_char;
    for (auto &i: time_arr) {
        i.get_time();
        cout << "Continue? (y/n): ";
        cin >> dummy_char;
        if (dummy_char != 'y')
            break;
    }
    for (int i = 0; i < time_arr->get_amount(); i++) {
        cout << i + 1;
        time_arr[i].put_time();
    }
    system("pause > 0");

}
