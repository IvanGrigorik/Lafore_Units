#include <iostream>

template<class Type>
Type avg (Type *arr, int size) {
    Type avg{};
    for (int i = 0; i < size; i++) {
        avg += arr[i];
    }
    return (avg /= size);
}

int main () {
    int arr_i[]{1, 2, 3, 4, 5, 10, 12};
    std::cout << avg(arr_i, 7) << std::endl;


    long arr_l[]{111111111, 222222222, 433333333};
    std::cout << avg(arr_l, 3) << std::endl;

    double arr_d[]{1.3, 2.3, 4.4, 2.23};
    std::cout << avg(arr_d, 4) << std::endl;

    char arr_c[]{1, 2, 3, 4, 5};
    std::cout << static_cast<int>(avg(arr_c, 5)) << std::endl;
}