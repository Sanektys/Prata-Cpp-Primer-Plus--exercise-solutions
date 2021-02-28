#include <iostream>


const int INCHES_PER_FEET = 12;

int main() {
    std::cout << "Program converts height in inches\n"
                 "to height in feet and inches.\n";
    std::cout << "Enter your height in inches: ______\b\b\b\b\b\b";
    int inches = 0;
    std::cin >> inches;

    int feet = inches / INCHES_PER_FEET;
    inches = inches % INCHES_PER_FEET;

    std::cout << "Your height: " << feet << " feet, "
              << inches << " inches.\n";


    return 0;
}