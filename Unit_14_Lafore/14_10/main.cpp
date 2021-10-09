#include <iostream>

using namespace std;

//bool isFeet (const string &);

class Distance {
private:
    int feet{};
    float inches{};

public:

    class Ex_feet {
    };

    class Ex_inches {
    };

    Distance () = default;

//    Distance (int new_feet, float new_inches) : feet(new_feet), inches(new_inches) {};

    void show_dist () const {
        cout << feet << "\'" << inches << "\"" << endl;
    }

    void get_dist ();
};

void Distance::get_dist () {

    cout << "Enter feet: ";
    int new_feet;

    cin >> new_feet;

    if (cin.fail())
        throw Ex_feet();

    feet = new_feet;

    cout << "Enter inches: ";
    cin >> inches;

    if (inches >= 12.0 || inches < 0 || cin.fail()) {
        throw Ex_inches();
    }

    if (cin.good()) {
        cin.ignore(10, '\n');
    }

}
//
//bool isFeet (const string &str) {
//    unsigned int len = str.size();
//    if (len == 0 || len > 5) {
//        return false;
//    }
//
//    for (int i = 0; i < len; i++) {
//        if ((str[i] < '0' || str[i] > '9') && str[i] != '-') {
//            return false;
//        }
//    }
//
//    double n = atof(str.c_str());
//
//    if (n < -999 || n > 999)
//        return false;
//    return true;
//}

int main () {
    Distance d;
    char choice;

    try {

        do{
            d.get_dist();
            cout << endl;
            d.show_dist();
            cout << "Enter another? (y/n): ";
            cin >> choice;
        }while(choice == 'y');
    }
    catch (Distance::Ex_inches) {
        cout << "Invalid inches input";
    }
    catch (Distance::Ex_feet) {
        cout << "Invalid feet input";
    }
}