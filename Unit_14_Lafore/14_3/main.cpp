#include <iostream>

using namespace std;

template<class TYPE>

class Queue {
private:
    static const int size = 3;
    int head{};
    int tail{};
    TYPE arr[size]{};

public:
    class Full {
    };

    class Empty {
    };

    Queue () : head(), tail() {};

    void push (TYPE data) {
        if (tail + 1 > size)
            throw Full();
        arr[tail++] = data;
    }

    TYPE pop () {
        if (head + 1 > size)
            throw Empty();
        return arr[head++];
    }

};

int main () {
    char choice = 'y';
    Queue<int> q1;
    int data;

    do {
        try {
            cout << "Enter data: ";
            cin >> data;
            q1.push(data);

            cout << endl << "Continue? (y/n): ";
            cin >> choice;
        }
        catch (Queue<int>::Full) {
            cout << "Queue full!" << endl;
            break;
        }
    } while (choice == 'y');
    while(true){
        try { cout << q1.pop() << endl; }
        catch (Queue<int>::Empty) {
            cout << "Queue empty!" << endl;
            break;
        }
    }
}
