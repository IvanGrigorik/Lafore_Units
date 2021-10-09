#include <iostream>

template<class TYPE>
class safe_array {
private:
    static const int size{10};
    TYPE arr[size];

public:
    safe_array () : arr() {};

    TYPE &operator[] (int n) {
        if (n < 0 || n >= size) {
            std::cout << "Invalid size";
            exit(1);
        }
        return arr[n];
    }
};

int main () {
    safe_array<float> arr_f;
    int i;
    for (i = 0; i < 10; i++) {
        arr_f[i] = static_cast<float>(i) * 10;
    }
    for (i = 0; i < 10; i++) {
        std::cout << arr_f[i] << ' ';
    }
    std::cout << std::endl;

    safe_array<char> arr_c;
    for(i = 0; i < 10; i++){
        arr_c[i] = static_cast<char>('a' + i);
    }
    for (i = 0; i < 10; i++) {
        std::cout << arr_c[i] << ' ';
    }

}
