#include <iostream>
#include <fstream>

using namespace std;

void Distance_in_file ();

int main () {

    Distance_in_file();

}

class Distance {
private:
    int feet;
    float inches;
public:
    Distance () : feet(0), inches(0.0) {}

    Distance (int ft, float inch) : feet(ft), inches(inch) {}

    void get_dist () {
        cout << endl << "Enter feet: ";
        cin >> feet;
        cout << endl << "Enter inches: ";
        cin >> inches;
    }

    void show_dist () const {
        cout << feet << "\'-" << inches << "\"";
    }

    void add_dist (Distance, Distance);
};

void Distance::add_dist (Distance dist1, Distance dist2) {
    inches = dist1.inches + dist2.inches;
    feet = 0;
    if (inches >= 12) {
        inches -= 12;
        feet++;
    }
    feet += dist1.feet + dist2.feet;
}

void Distance_in_file () {

    Distance new_dist(5, 11.2), dist_sum;

    fstream new_file;

    new_file.open("New_file.txt", ios::in | ios::out | ios::app | ios::binary);

    char ch;

    dist_sum.add_dist(new_dist, new_dist);
    new_file.write(reinterpret_cast <char *> (&new_dist), sizeof(new_dist));

    do {
        cout << "Enter data to put it in file: ";
        new_dist.get_dist();

        new_file.write(reinterpret_cast <char *> (&new_dist), sizeof(new_dist));

        cout << "Continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y');

    new_file.seekg(0);

    do {
        new_file.read(reinterpret_cast <char *>(&new_dist), sizeof(Distance));
        if (!new_file)
            break;
        new_dist.show_dist();
        cout << endl;
    } while (true);
}