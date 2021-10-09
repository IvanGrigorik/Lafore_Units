#include <iostream>

template<class TYPE>
class safe_array {
private:
    static const int size{10};
    TYPE arr[size];

public:

    class Index_exception {
    };

    safe_array () : arr() {};

    TYPE &operator[] (int n) {
        if (n < 0 || n >= size) {
            throw Index_exception();
        }
        return arr[n];
    }
};

int main () {
    safe_array<float> arr_f;
    int i;

    try {
        for (i = 0; i < 10; i++) {
            arr_f[i] = static_cast<float>(i) * 10;
        }
        for (i = 0; i < 12; i++) {
            std::cout << arr_f[i] << ' ';
        }
//        std::cout << std::endl;
//
//        safe_array<char> arr_c;
//        for (i = 0; i < 10; i++) {
//            arr_c[i] = static_cast<char>('a' + i);
//        }
//        for (i = 0; i < 10; i++) {
//            std::cout << arr_c[i] << ' ';
//        }
    }
    catch (safe_array<float>::Index_exception){
        std::cout << "Incorrect array index" << std::endl;
    }
}