#include <iostream>
#include <math.h>

using namespace std;

void library();
void english_calculator();
void array_madness();
void bills_busy();

int main()
{
    library();
    english_calculator();
    array_madness();
    bills_busy();
}

class publication {
protected:
    string name;
    float price;
public:
    // Constructors
    publication() : name(), price() {};
    //publication(string book_name, float book_price) :
    // name(std::move(book_name)), price(book_price) {};


    void get_info() {
        cout << "Enter book name: ";
        cin >> name;
        cout << "Enter book price: ";
        cin >> price;
    }

    void put_info() const {
        cout << "Book name: " << name << endl;
        cout << "Book price: " << price << endl;
    }

    virtual void get_data() = 0;
    virtual void put_data() const = 0;
    virtual bool is_oversize() = 0;
};
class book : public publication {
private:
    int pages_num;
public:
    // Constructors
    book() : pages_num() {};
//    book (string book_name, float book_price, int num_of_pages) :
//            publication(std::move(book_name), book_price), pages_num(num_of_pages){};

    // Functions to get and put data
    void get_data() override {
        publication::get_info();
        cout << "Enter pages number: ";
        cin >> pages_num;
    }

    void put_data() const override {
        publication::put_info();
        cout << "Pages number: " << pages_num << endl;
    }

    bool is_oversize() override {
        return (pages_num > 800);
    }
};
class tape : public publication {
private:
    float minutes;
public:
    // Constructors
    tape() : minutes() {};
//
//    tape(const string &book_name, float book_price, float book_minutes) :
//            publication(book_name, book_price), minutes(book_minutes) {};

    void get_data() override {
        publication::get_info();
        cout << "Enter minutes: ";
        cin >> minutes;
    }

    void put_data() const override {
        publication::put_info();
        cout << "Minutes: " << minutes << endl;
    }
    bool is_oversize() override {
        return (minutes > 90);
    }
};
void library() {
    const int ARR_SIZE = 4;
    publication *product[ARR_SIZE];
    char choice = 'b';

    for (int i = 0; i < ARR_SIZE; i++) {
        cout << "Book or tape (b/t): ";
        cin >> choice;
        if (choice == 'b')
            product[i] = new book;
        else
            product[i] = new tape;
        product[i]->get_data();
    }

    for (int i = 0; i < ARR_SIZE; i++) {
        product[i]->put_data();
        if(product[i]->is_oversize())
            cout << "Size excess!" << endl;
    }
}

class Distance
{
private:
    int feet;
    float inches;
public:
    // Constructors
    Distance()
    {feet = 0; inches = 0.0;}
    Distance(float float_feet){
        feet = int(float_feet);
        inches = 12 * (float_feet - float(feet));}
    Distance(int new_feet, float new_inches) : feet(new_feet), inches(new_inches){};

    //Methods
    void show_dist() const
    {cout << feet << "\'-" << inches << "\"" << endl;}
    friend Distance operator + (Distance, Distance);
    friend Distance operator * (Distance, Distance);
};
Distance operator + (Distance dist_1, Distance dist_2)
{
    float dist_1_all = float(dist_1.feet) + dist_1.inches / 12;
    float dist_2_all = float(dist_2.feet) + dist_2.inches / 12;
    return Distance(dist_1_all + dist_2_all);
}
Distance operator * (Distance dist_1, Distance dist_2) {
    float dist_1_all = float(dist_1.feet) + dist_1.inches / 12;
    float dist_2_all = float(dist_2.feet) + dist_2.inches / 12;
    return Distance(dist_1_all * dist_2_all);
}
void english_calculator()
{
    Distance d1(6, 7);
    Distance d2(6, 7);

    (d1 + d2).show_dist();
    (d1 + 12.4).show_dist();
    (12.4 + d2).show_dist();
    cout << endl;
    (d1 * d2).show_dist();
    (d1 * 12.4).show_dist();
    (12.4 * d2).show_dist();
}

class Array
{
private:
    int *ptr;
    int size;
public:
    Array(int s)
    {
        size = s;
        ptr = new int[s];
    }
    Array(Array &exist_array)
    {
        delete [] ptr;
        ptr = new int[exist_array.size];
        for(int i = 0; i < size; i++)
        {ptr[i] = exist_array[i];}
    }

    ~Array()
    {delete[] ptr;}

    int& operator [] (int j)
    {return *(ptr+j);}

    Array &operator = (Array &exist_array)
    {
        delete [] ptr;
        size = exist_array.size;
        ptr = new int[exist_array.size];
        for(int i = 0; i < size; i++)
        {ptr[i] = exist_array[i];}
        return *this;
    }
};
void array_madness()
{
    const int ARR_SIZE = 10;
    Array arr1(ARR_SIZE);
    for(int i = 0; i < ARR_SIZE; i++)
    {arr1[i] = i * i;}

    Array arr2(10);
    arr2 = arr1;
    for(int i = 0; i < ARR_SIZE; i++)
    {cout << arr2[i] << ' ';}
    // 2 seconds delay
    Sleep(2000);
}

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
    friend bMoney round (bMoney money_to_round);

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
    friend bMoney operator * (long double, bMoney);
    friend bMoney operator / (long double, bMoney);
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
bMoney operator * (long double m1, bMoney m2)
{
    bMoney money_mul = m1 * m2.money;
    return money_mul;
}
bMoney operator / (long double m1, bMoney m2)
{
    bMoney money_div = m1 / m2.money;
    return money_div;
}
bMoney round (bMoney money_to_round)
{
    long double whole_part, div_part;
    div_part = modf( money_to_round.money , &whole_part);
    return ( (div_part >= 0.5) ? bMoney(++whole_part) : bMoney(whole_part));
}
void bills_busy()
{
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
