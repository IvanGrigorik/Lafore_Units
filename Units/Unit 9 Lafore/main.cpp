#include <iostream>
using namespace std;


void book_company();

int main()
{
    book_company();
}

enum disk_format {CD, DVD};
class publication
{
protected:
    string name;
    float price;
public:
    // Constructors
    publication() : name(" "), price() {};
    publication(string book_name, float book_price) : name(std::move(book_name)), price(book_price) {};

    void get_data()
    {
        cout << "Enter book name: ";
        cin >> name;
        cout << "Enter book price: ";
        cin >> price;
    }

    void put_data() const
    {
        cout << "Book name: " << name << endl;
        cout << "Book price: " << price << endl;
    }
};
class sale
{
protected:
    float month_sale[3];
public:
    // Constructs
    sale () : month_sale() {};
    sale (float x1, float x2, float x3) : month_sale() {month_sale[0] = x1; month_sale[1] = x2; month_sale[2] = x3;};
    void get_data()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Enter sales in " << i+1 << " month:";
            cin >> month_sale[i];
        }
    }
    void put_data () const
    {
        for(int i = 0; i < 3; i++)
            cout << "Sales in " << i << "month: " << month_sale[i] << endl;
    }
};
class book : public publication, public sale
{
private:
    int num_pages;
public:
    // Constructors
    book () : publication(), num_pages() {};
    book (string book_name, float book_price, int num_of_pages, float x1, float x2, float x3) :
            publication(std::move(book_name), book_price), num_pages(num_of_pages), sale(x1, x2, x3){};

    void get_data()
    {
        publication::get_data();
        sale::get_data();
        cout << "Enter the number of pages of the book: ";
        cin >> num_pages;
    }
    void put_data() const
    {
        publication::put_data();
        cout << "Number of book pages: " << num_pages << endl;
        sale::put_data();
        cout << endl;
    }
};
class type : public publication, public sale
{
private:
    float minutes;
public:
    // Constructors
    type () : publication(), minutes(), sale() {} ;
    type (string book_name, float book_price, float book_in_minutes, float x1, float x2, float x3) :
    publication(std::move(book_name), book_price), minutes(book_in_minutes), sale(x1, x2, x3){};

    void get_data()
    {
        publication::get_data();
        sale::get_data();
        cout << "Enter the book in minutes: ";
        cin >> minutes;
    }
    void put_data() const
    {
        publication::put_data();
        cout << "Book in minutes: " << minutes << endl;
        sale::put_data();
        cout << endl;
    }

};
class disk : public publication, public sale
{
private:
    disk_format disk_chose;
public:
    // Constructors
    disk () : publication(), disk_chose(), sale() {};
    disk (string book_name, float book_price, disk_format ds, float x1, float x2, float x3) :
    publication(std::move(book_name), book_price), sale(x1, x2, x3){ disk_chose = ds; };

    void get_data()
    {
        publication::get_data();
        char c;
        cout << "Enter disk format (c/d): ";
        cin >> c;
        disk_chose = (c == 'c') ? CD: DVD;
        sale::get_data();
    }
    void put_data () const
    {
        publication::put_data();
        cout << "Disk format: " << ((disk_chose == CD ) ? "CD" : "DVD") << endl;
        sale::put_data();
    }
};
void book_company()
{
    book book1("Name_1", 123.1, 3, 1, 2, 3), book2;
    type book3("Name_3", 123.4, 1312, 1, 2, 3), book4;
    disk disk1("Name_disk", 3, DVD, 1, 2, 4), disk2;
    book2.get_data();
    book4.get_data();
    disk2.get_data();
    cout << endl;

    book1.put_data();
    book2.put_data();
    book3.put_data();
    book4.put_data();
    disk1.put_data();
    disk2.put_data();
}

const int LEN = 80;
class employee
{
private:
    char last_name[ LEN ];
    unsigned long number;
public:
    // Constructor
    employee() : last_name(" "), number() {};

    void get_data ()
    {
        cout << "Enter last name: ";
        cin >> last_name;
        cout << "Enter number: ";
        cin >> number;
    }
    void put_data() const
    {
        cout << "Last name: " << last_name << endl;
        cout << "Number: " << number << endl;
    }
};
class manager : public employee
{
private:
    char title[ LEN ];
    double dues;
public:

};
