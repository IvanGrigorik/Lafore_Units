#include <iostream>

template<class TYPE>
void swap (TYPE &arg1, TYPE &arg2) {
    TYPE temp = arg1;
    arg1 = arg2;
    arg2 = temp;
}

int main () {
    int i1{1}, i2{3};
    swap(i1, i2);
    std::cout << i1 << ' ';
    std::cout << i2 << std::endl;

    char c1{'1'}, c2{'2'};
    swap(c1, c2);
    std::cout << c1 << ' ';
    std::cout << c2 << std::endl;

    float f1{1.2}, f2{2.3};
    swap(f1, f2);
    std::cout << f1 << ' ';
    std::cout << f2 << std::endl;

    std::string str1{"Hello world!"}, str2{"Hello programming!!!"};
    swap(str1, str2);
    std::cout << str1 << ' ';
    std::cout << str2 << std::endl;
}
