#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<std::string> words_arr{};
    std::string word;

    char dummy_char{};

    int i{};
    while (dummy_char != 'n') {

        std::cout << "Enter " << i << " word: ";
        std::cin >> word;

        words_arr.push_back(word);

        std::cout << "Continue? (y/n)" << std::endl << ">> ";
        std::cin >> dummy_char;
        i++;
    }

    std::sort(words_arr.begin(), words_arr.end());

    for (int j = 0; j < words_arr.size(); j++) {
        std::cout << words_arr[j] << ' ';
    }

    return 0;
}
