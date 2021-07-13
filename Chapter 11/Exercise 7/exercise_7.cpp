#include <iostream>

#include "complex.h"


int main() {
    Complex a{3.0, 4.0};
    Complex c{};
    std::cout << "Enter a complex number (q to quit):\n";
    while (std::cin >> c) {
        std::cout << "c is " << c << '\n'
                  << "complex conjugate is " << ~c << '\n';
        std::cout << "a is " << a << '\n'
                  << "a + c is " << a + c << '\n'
                  << "a - c is " << a - c << '\n'
                  << "a * c is " << a * c << '\n'
                  << "2 * c is " << 2 * c << '\n';
        std::cout << "Enter a complex number (q to quit):\n";
    }
    std::cout << "Done!\n";


    return 0;
}
