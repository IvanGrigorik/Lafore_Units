#include <iostream>

template<class TYPE>

class queue {
private:
    static const int size = 10;
    int head{};
    int tail{};
    TYPE arr[size]{};

public:
    queue () : head(), tail() {};

    void push (TYPE data) {
        arr[tail++] = data;
    }

    TYPE pop () {
        return arr[head++];
    }

};


int main () {
    queue<int> q_i;
    q_i.push(1);
    q_i.push(2);
    q_i.push(3);
    q_i.push(4);

    std::cout << q_i.pop() << std::endl;
    std::cout << q_i.pop() << std::endl;
    std::cout << q_i.pop() << std::endl;
    std::cout << q_i.pop() << std::endl << std::endl;

    queue<double> q_d;
    q_d.push(1.2);
    q_d.push(3.4);
    q_d.push(5.6);
    q_d.push(7.8);

    std::cout << q_d.pop() << std::endl;
    std::cout << q_d.pop() << std::endl;
    std::cout << q_d.pop() << std::endl;
    std::cout << q_d.pop() << std::endl;

}
