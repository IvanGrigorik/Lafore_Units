#include <iostream>
#include <algorithm>

int main() {

    float arr[10];

    char dummy_char{};

    int i{};
    while(dummy_char != 'n') {

        std::cout << "Enter " << i << " element: ";
        std::cin >> arr[i];

        std::cout << "Continue enter? (y/n)" << std::endl << ">> ";
        std::cin >> dummy_char;

        i++;
    }

    std::sort(arr, arr + i);

    for (int j = 0; j < i; j++) {
        std::cout << arr[j] << ' ';
    }
}
