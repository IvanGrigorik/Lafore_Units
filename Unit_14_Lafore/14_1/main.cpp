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
    float arr_f[] = {1.2, 2.3, 4.2};
    std::cout << avg(arr_f, 3) << std::endl;

    int arr_i[] = {1, 2, 3, 4, 5, 10, 12};
    std::cout << avg(arr_i, 7) << std::endl;
}