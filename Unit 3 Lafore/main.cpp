#include <iostream>
#include <conio.h>
using namespace std;

void multiply();
void celsius();
void char_to_int();
void f_calculator();
void pyramid();
void factorial();

int main()
{
    multiply();
    celsius();
    char_to_int();
    f_calculator();
    pyramid();
factorial();
}

void multiply()
{
    int x;
    cout << "Enter number: ";
    cin >> x;

    for(int i = 1; i < 200; i++)
    {
        cout << i*x;
        if(i % 10 == 0)
            cout << endl;
    }
}

void celsius()
{
    int choice;
    cout << "Enter 1 to convert Fahrenheit to Celsius"<< endl
    << "Enter 2 to convert Celsius to Fahrenheit" << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
            cout << "Len\'";
            break;
        case 2:
            cout << "-//-";
            break;
        default:
            exit(0);
    }
}

void char_to_int()
{
    char c;
    int x = 0;

    while((c = getche()) != '\r')
    {
        x *= 10;
        x += (c-48);
    }
    cout << x;
}

void f_calculator()
{
    float x, y;
    char operand;

    cout << "Enter x, operand, y, like \"x + y\"" << endl;

    cin >> x >> operand >> y;
    switch(operand)
    {
        case '+':
            cout << x + y;
            break;
        case '-':
            cout << x - y;
            break;
        case '*':
            cout << x * y;
            break;
        case '/':
            cout << x / y;
            break;
        default:
            exit(0);
    }
}

void pyramid()
{
    for(int i = 0; i < 40; i+=2)
    {
        for(int space = 40 - i; space > 0; space--)
            cout << " ";
        for(int j = i + 1; j > 0; j--)
            cout << "x";
        cout  << endl;
    }
}

void factorial()
{
    int x = 1, result = 1;
    while(1)
    {
        cout << "Enter number to calculate factorial" << endl;
        cin >> x;
        if(x <= 0)
            exit(0);
        while(x)
        {
            result += result * (x-1);
            --x;
        }
        cout << result << endl;
        result = 1;
    }
}