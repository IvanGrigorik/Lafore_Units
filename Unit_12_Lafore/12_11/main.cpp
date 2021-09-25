#include <iostream>
#include <cmath>

using namespace std;

void bills_busy ();

int main () {
    bills_busy();
    return 0;
}


class bMoney {
private:
    long double money;
public:
    // Constructors
    bMoney () : money() {};

    explicit bMoney (long double new_bill) : money(new_bill) {};

    explicit bMoney (const string &str_money) : money(stoi(str_money)) {};

    void money_add (bMoney m1, bMoney m2) { money = m1.money + m2.money; }

    void get_money () {
        cout << "Enter bill: ";
        cin >> money;
    }

    void put_money () const { cout << "Bill: " << money << endl; }

    friend bMoney round (bMoney money_to_round);

    friend bMoney operator+ (bMoney, bMoney);

    friend bMoney operator- (bMoney, bMoney);

    bMoney operator* (bMoney m1) const {
        long double money_mul = money * m1.money;
        return bMoney(money_mul);
    }

    long double operator/ (bMoney m1) const {
        long double money_div = money / m1.money;
        return money_div;
    }

    friend bMoney operator/ (bMoney, long double);

    friend bMoney operator* (long double, bMoney);

    friend bMoney operator/ (long double, bMoney);
};

bMoney operator+ (bMoney m1, bMoney m2) {
    long double money_sum = m1.money + m2.money;
    return bMoney{money_sum};
}

bMoney operator- (bMoney m1, bMoney m2) {
    long double money_dif = m1.money - m2.money;
    return bMoney{money_dif};
}

bMoney operator/ (bMoney m1, long double prod_num) {
    bMoney money_div;
    money_div.money = m1.money / prod_num;
    return bMoney{money_div};
}

bMoney operator* (long double m1, bMoney m2) {
    bMoney money_mul;
    money_mul.money = m1 * m2.money;
    return money_mul;
}

bMoney operator/ (long double m1, bMoney m2) {
    bMoney money_div;
    money_div.money = m1 / m2.money;
    return money_div;
}

bMoney round (bMoney money_to_round) {
    long double whole_part, div_part;
    div_part = modf(money_to_round.money, &whole_part);
    return ((div_part >= 0.5) ? bMoney(++whole_part) : bMoney(whole_part));
}

void bills_busy () {
    bMoney m1("123"), m2(123.32), m3, m4;
    m3.get_money();

    m4 = m1 + m2;
    m4.put_money();

    m4 = m1 - m2;
    m4.put_money();

    m4 = m1 * m2;
    m4.put_money();

    m4 = m1 / 123;
    m4.put_money();

    long double m8 = m2 / m1;
    cout << "Bill: " << m8 << endl;

    m4.money_add(m1, m2);
    m4.put_money();

    m4 = round(m3);
    m4.put_money();
}
