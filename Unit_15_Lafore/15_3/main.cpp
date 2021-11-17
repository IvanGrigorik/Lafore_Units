#include <iostream>
#include <algorithm>
#include <list>

int main() {

    std::list<int> i_list;

    std::list<int>::iterator iter1, iter2;

    i_list.push_back(1);
    i_list.push_back(2);
    i_list.push_back(3);
    i_list.push_back(4);
    i_list.push_back(5);

    iter1 = i_list.begin();
    iter2 = i_list.end();

    std::cout << "Before flip: " << std::endl;
    while (iter1 != iter2) {
        std::cout << *iter1++ << ' ';
    }

    iter1 = i_list.begin();
    iter2 = --i_list.end();

    while (*iter1 != *iter2) {
        std::swap(*iter1++, *iter2);
        if(iter1 == iter2)
            break;
        iter2--;
    }


    iter1 = i_list.begin();
    iter2 = i_list.end();

    std::cout << std::endl << "After flip: " << std::endl;
    while (iter1 != iter2) {
        std::cout << *iter1++ << ' ';
    }
}
