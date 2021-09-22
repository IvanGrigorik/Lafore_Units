#include <iostream>
#include <fstream>

using namespace std;

struct link {
    int data;
    link *next;
};

class Link_list {
private:
    link *head;//
public:
    Link_list () : head(nullptr) {}

    friend ostream &operator<< (ostream &out, Link_list out_link_list) {
        link *current = out_link_list.head;
        while (current) {
            out << current->data << endl;
            current = current->next;
        }

        return out;
    }

    void add_item () {
        int new_data;
        cout << "Enter new data: ";
        cin >> new_data;
        link *new_link = new link;
        new_link->data = new_data;
        new_link->next = head;
        head = new_link;
    }

    void display () {
        link *current = head;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    void file_write () {

    }
};

int menu () {
    int x;
    cout << "Enter: " << endl
         << "1) To add link in the list" << endl
         << "2) To show all link's data" << endl
         << "3) To add link's to file" << endl
         << "4) To get new link list from file" << endl
         << ">> ";
    cin >> x;
    return x;
}

int main () {
    Link_list new_linklist;

    new_linklist.add_item();
    new_linklist.add_item();
    new_linklist.add_item();

    cout << new_linklist;


//    while (true) {
//        switch (menu()) {
//            case 1: {
//                new_linklist.add_item();
//            }
//
//            case 2: {
//                new_linklist.display();
//            }
//
//            default:
//                return 0;
//        }
//    }
}
