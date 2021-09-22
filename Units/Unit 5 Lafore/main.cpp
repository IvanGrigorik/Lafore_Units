#include <iostream>
using namespace std;

int power(double n, int p = 2);
int power(char n = '3', char p = '2');
void zero_smaller(int& first_arg, int& second_arg);
long hms_to_sec(int hours, int minutes, int seconds);
void swap(int& x, int& y);

int main()
{
    int x = 4, y = 3, z = 30;
    power(x, y);
    zero_smaller(x, y);
    cout << hms_to_sec(x, y, z) << endl;

    cout << power('5', '3') << endl;


    swap(x, y);
    cout << x << endl << y << endl << z;
}

int power(double n, int p)
{
    static double s_n = n, s_p = p;
    if(p > 1)
        return power(n*s_n, --p);

    cout << s_n << "^" << s_p << "=" << n;
    return 1;
}

void zero_smaller(int& first_arg, int& second_arg)
{
    if(first_arg > second_arg)
        second_arg = 0;
    else
        first_arg = 0;
}

long hms_to_sec(int hours, int minutes, int seconds)
{
    long avg_seconds = hours * 3600 + minutes * 60 + seconds;
    return avg_seconds;
}

int power(char n, char p)
{
    int x = n - '0';
    p = p -'0';
    static int s_x = x;
    while(p > 1)
    {
        x *= s_x;
        p--;
    }
    return x;
}

void swap(int& x, int& y)
{
    int temp = y;
    y = x;
    x = temp;
}