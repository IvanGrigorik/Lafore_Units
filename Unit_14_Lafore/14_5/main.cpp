#include <iostream>

template<class TYPE>
TYPE max_arr (TYPE *arr, int size) {
    TYPE max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main () {
    int arr_i[]{1, 3, 2, 32, 3, 1832, 3223, 23, 3222};
    std::cout << max_arr(arr_i, 8) << std::endl;

    double arr_d[]{1.2, 2.3, 4.5, -1.3, 8.9, 1};
    std::cout << max_arr(arr_d, 6) << std::endl;

    char arr_c[]{1, 2, 3, 4, 5, 39, 32, 1, 23};
    std::cout << static_cast<int>(max_arr(arr_c, 8)) << std::endl;
}
