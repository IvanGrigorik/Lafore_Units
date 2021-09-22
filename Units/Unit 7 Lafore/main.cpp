#include <iostream>
#include <string>
using namespace std;

void reverse_test();
void array_of_soldiers();

int main()
{
    //reverse_test();
    array_of_soldiers();
}

class employee
{
private:
    string name{};
    long number{};

public:

    employee() : name{}, number(0) {};
//    std::move позволяет перемещать строку без её копирования. Позволяет ещё кое-что делать, но  пока что рано.
    //explicit employee(string new_string, int num) : name(std::move(new_string)), number(num){};
    void get_data()
    {
        cout << "Enter name:";
        cin >> name;
        cout << "Enter number:";
        cin >> number;
    }

    void put_data()const
    {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};
void array_of_soldiers()
{
    employee soldiers[100];
    char one_char;
    unsigned int count = 0;

    for(int i = 0; i < 100; i++)
    {
        soldiers[i].get_data();
        cout << "Continue the process? (y/n)";
        cin >> one_char;
        if(one_char != 'y')
            break;
        count++;
    }

    for(int i = 0; i < count + 1; i++) {
        soldiers[i].put_data();
        cout << endl;
    }
}

void reverse(char str[], int size)
{
    char temp;
    for(int i = 0; i < size/2; i++)
    {
        temp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = temp;
    }
}
void reverse_test()
{
    char str[] = {"argentina"};
    reverse(str, 21);
    cout << str;
}

class distance
{
private:
    int feet;
    float inches;
public:
    void get_distance ()
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void show_distance () const
    {cout << feet << "\'-" << inches << "\"";}
};

class bMoney
{
private:
    double long money;
public:
    // Constructors
    bMoney () : money() {};
    bMoney (string str_money) : money(stoi(str_money)) {};

    void money_add (bMoney m1, bMoney m2)
    {money = m1.money + m2.money;}
    void get_money ()
    {
        cout << "Enter bill: ";
        cin >> money;
    }
    void put_money ()
    {cout << "Bill: " << money;}
};