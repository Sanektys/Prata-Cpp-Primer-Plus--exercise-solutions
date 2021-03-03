#include <iostream>


int main() {
    std::cout << "Enter number of strings: ";
    short amount = 0;
    std::cin >> amount;

    for (short i = 1; i <= amount; ++i) {
        for (short j = 1; j <= amount - i; ++j)
            std::cout << '.';
        for (short j = amount - i + 1; j <= amount; ++j)
            std::cout << '*';
        std::cout << std::endl;
    }
    

    return 0;
}
