#include <iostream>


int main() {
    std::cout << "Enter your age and the program\n"
                 "will display your age in months.\n\n";
    std::cout << "Your age is: ";
    int age = 0;
    std::cin >> age;
    std::cout << "Your age in months is: " << age * 12 << std::endl;

    return 0;
}
