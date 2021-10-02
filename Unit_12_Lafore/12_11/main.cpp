#include <iostream>
#include <cmath>

using namespace std;

void bills_busy ();

int main () {
    bills_busy();
    return 0;
}


class Money {
private:
    long double money;
public:
    // Constructors
    Money () : money() {};

    explicit Money (long double new_bill) : money(new_bill) {};

    explicit Money (const string &str_money) : money(stoi(str_money)) {};

    void money_add (Money m1, Money m2) { money = m1.money + m2.money; }

    void get_money () {
        cout << "Enter bill: ";
        cin >> money;
    }

    void put_money () const { cout << "Bill: " << money << endl; }

    friend Money round (Money money_to_round);

    friend Money operator+ (Money, Money);

    friend Money operator- (Money, Money);

    Money operator* (Money m1) const {
        long double money_mul = money * m1.money;
        return Money(money_mul);
    }

    long double operator/ (Money m1) const {
        long double money_div = money / m1.money;
        return money_div;
    }

    friend Money operator/ (Money, long double);

    friend Money operator* (long double, Money);

    friend Money operator/ (long double, Money);

    friend ostream &operator<< (ostream &out, Money data) {
        out << "Bill: " << data.money << endl;
        return out;
    }

    friend istream &operator>> (istream &in, Money &data) {
        in >> data.money;
        return in;
    }
};

Money operator+ (Money m1, Money m2) {
    long double money_sum = m1.money + m2.money;
    return Money{money_sum};
}

Money operator- (Money m1, Money m2) {
    long double money_dif = m1.money - m2.money;
    return Money{money_dif};
}

Money operator/ (Money m1, long double prod_num) {
    Money money_div;
    money_div.money = m1.money / prod_num;
    return Money{money_div};
}

Money operator* (long double m1, Money m2) {
    Money money_mul;
    money_mul.money = m1 * m2.money;
    return money_mul;
}

Money operator/ (long double m1, Money m2) {
    Money money_div;
    money_div.money = m1 / m2.money;
    return money_div;
}

Money round (Money money_to_round) {
    long double whole_part, div_part;
    div_part = modf(money_to_round.money, &whole_part);
    return ((div_part >= 0.5) ? Money(++whole_part) : Money(whole_part));
}

void bills_busy () {
    Money m1("123"), m2(123.32), m3, m4;
    cout << "Enter bill data: ";
    cin >> m3;
    cout << m3;
    system("pause > 0");

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
