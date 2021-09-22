#include <iostream>

using namespace std;

void bills_busy();

int main() {
    bills_busy();
    return 0;
}

class Int
{
private:
    int arg;
public:

    Int() : arg(0) {};
    explicit Int(int x) : arg(x) {};

    static Int check(long double ans)
    {
        if(ans > INT_MAX || ans < INT_MIN)
            exit(0);
        return Int(int(ans));
    };

    Int operator + (Int arg_2) const
    {return check (arg + arg_2.arg);}
    Int operator - (int arg_2) const
    {return check (arg - arg_2);}
    Int operator * (Int arg_2) const
    {return check (arg * arg_2.arg);}
    Int operator / (Int arg_2) const
    {return check (arg / arg_2.arg);}
};

class bMoney
{
private:
    long double money;
public:
    // Constructors
    bMoney () : money() {};
    bMoney (long double new_bill) : money(new_bill) {};
    bMoney (string str_money) : money(stoi(str_money)) {};

    void money_add (bMoney m1, bMoney m2)
    {money = m1.money + m2.money;}
    void get_money ()
    {
        cout << "Enter bill: ";
        cin >> money;
    }
    void put_money ()
    {cout << "Bill: " << money << endl;}

    friend bMoney operator + (bMoney, bMoney);
    friend bMoney operator - (bMoney, bMoney);
    bMoney operator * (bMoney m1)
    {
        long double money_mul = money * m1.money;
        return bMoney(money_mul);
    }
    long double operator / (bMoney m1)
    {
        long double money_div = money / m1.money;
        return money_div;
    }
    friend bMoney operator / (bMoney, long double);
};
bMoney operator + (bMoney m1, bMoney m2)
{
    long double money_sum = m1.money + m2.money;
    return bMoney(money_sum);
}
bMoney operator - (bMoney m1, bMoney m2)
{
    long double money_dif = m1.money - m2.money;
    return bMoney(money_dif);
}
bMoney operator / (bMoney m1, long double prod_num)
{
    bMoney money_div = m1.money / prod_num;
    return bMoney(money_div);
}
void bills_busy()
{
    bMoney m1("123"), m2(123.32), m3, m4, m5, m6, m7;
    m3.get_money();
    m4 = m1 + m2;
    m5 = m1 - m2;
    m6 = m1 * m2;
    m7 = m1 / 123;
    long double m8 = m2 / m1;


    m1.put_money();
    m2.put_money();
    m3.put_money();
    m4.put_money();
    m5.put_money();
    m6.put_money();
    m7.put_money();
    cout << endl << m8;
}