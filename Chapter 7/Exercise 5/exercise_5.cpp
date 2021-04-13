#include <iostream>


long double factor(short);

int main() {
    std::cout << "The program counts the factorial of a number\n";
    std::cout << "Enter the positive number (or type any letter to exit): ";
    short number{};
    while ((std::cin >> number).good() && number >= 0) {
        std::cout << "The factorial of number " << number
                  << " is " << factor(number) << std::endl;
        std::cout << "\nEnter another positive number "
                     "(or type any letter to exit): ";
    }
    std::cout << "Terminate...\n";


    return 0;
}

long double factor(short number) {
    if (0 == number)
        return 1.0l;

    return number * factor(number - 1);
}
