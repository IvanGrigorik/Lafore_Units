#include <iostream>
#include <fstream>

using namespace std;

struct node {
    int data;
    node *next;
};

class Link_list {
private:
    node *head;
public:
    Link_list () : head(nullptr) {}

    void add_item (int new_data) {
        node *new_link = new node;
        new_link->data = new_data;
        new_link->next = head;
        head = new_link;
    }

    void file_write () {
        ofstream out("test.txt", ios::app | ios::trunc);
        node *current = head;
        while (current) {
            out << current->data << endl;
            current = current->next;
        }
        out.close();
    }

    void file_read () {
        ifstream in("test.txt");

        int data;
        while (true) {
            in >> data;
            if (in.eof())
                break;
            add_item(data);
        }
        add_item(data);
    }

    void display () {
        node *current = head;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int menu () {
    int x;
    cout << "Enter: " << endl
         << "1) To add link in the list" << endl
         << "2) To show all link's data" << endl
         << "3) To add link's to file" << endl
         << "4) To get add new link from file" << endl
         << ">> ";
    cin >> x;
    return x;
}

int main () {
    Link_list new_linklist;

    int data;

    while (true) {
        switch (menu()) {
            case 1: {
                cout << "Input data: ";
                cin >> data;
                new_linklist.add_item(data);
                break;
            }

            case 2: {
                new_linklist.display();
                break;
            }

            case 3: {
                new_linklist.file_write();
                break;
            }

            case 4: {
                new_linklist.file_read();
                break;
            }

            default:
                return 0;
        }
    }
}
