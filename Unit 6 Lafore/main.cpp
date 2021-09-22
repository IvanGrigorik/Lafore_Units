#include <iostream>
using namespace std;

void number_moment();
void car_payment();


int main()
{
    number_moment();
    car_payment();
}

class Int
{
private:
    int number;
public:
    // Конструктор создания объекта класса, присваивающий
    // всем новосозданным объектам значение поля number равное 0
    Int() : number(0){};

    // Перегруженный конструктор, при вводе которого надо укзывать
    // величину поля number()
    explicit Int(int x) : number(x){};
    // слово explicit ставится, когда в конструкторе объявляется 0/2/3 и более параметров,
    // при чём даже если со второго они имеют значения по умолчанию (uniform initialization 2011 year)

    void get_number()
    {
        cout << "Enter number: ";
        cin >> number;
    }
    void show_number() const // const метод, потому что не изменяется значение поля number
    {cout << number << endl;}

    void add_number(Int number1, Int number2);
};
void Int::add_number(Int number1, Int number2)
{number = number1.number + number2.number;}
void number_moment()
{
    Int number1(3), number2, number3;
    number2.get_number();
    number3.add_number(number1, number2);
    number1.show_number();
    number2.show_number();
    number3.show_number();
}

class tollBoth
{
private:
    unsigned int amount{}; // фигурными скобками мы заменяем выражениие tollBoth() : amount(0){}; в public-е.
    double proceeds{};
public:
    void pay_car()
    {
        amount++;
        proceeds += .5;
    }
    void no_pay_car()
    {amount++;}
    void display()const
    {cout << amount << endl << proceeds;};
};
void car_payment()
{
    tollBoth check;
    char button;
    while((button = getchar()) != '\n')
    {
        if(button == 'y')
            check.pay_car();
        else
            check.no_pay_car();
    }
    check.display();
}
