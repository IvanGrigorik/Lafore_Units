#include <iostream>
using namespace std;

void telephone();
void coords_sum();

int main() {
//    telephone();
    coords_sum();
    return 0;
}

struct phone
{
    int code;
    int station;
    int subscriber;
};
void telephone()
{
    phone my_number = {80, 225, 704481}, your_number;

    cout << "Enter telephone number with code, station number and subscriber number, like \"80 225 704481\""
    << endl;
    cin >> your_number.code >> your_number.station >> your_number.subscriber;

    cout << "Your number: (" << your_number.code << ") " << your_number.station << " " << your_number.subscriber
    << endl;
    cout << "My number: (" << my_number.code << ") " << my_number.station << " " << my_number.subscriber
    << endl;
}

struct point
{
    int x;
    int y;
};
void coords_sum()
{
    point dot_1, dot_2, sum_dot;
    char dummy_char;
    cout << "Enter 1-st point \"x, y\" coordinates, like 5, 2" << endl;
    cin >> dot_1.x >> dummy_char >> dot_1.y;
    cout << "Enter 2-nd point \"x, y\" coordinates, like 5, 2" << endl;
    cin >> dot_2.x >> dummy_char >> dot_2.y;

    sum_dot.x = dot_1.x + dot_2.x;
    sum_dot.y = dot_1.y + dot_2.y;
    cout << "Point_1 + point_2 = " << sum_dot.x << "," << sum_dot.y;


}