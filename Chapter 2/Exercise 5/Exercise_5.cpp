#include <iostream>


double celsToFaren(int);

int main() {
    std::cout << "The program converts degrees Celsius to Fahrenheit\n";
    std::cout << "Please enter a Celsius value: ";
    int celsius = 0;
    std::cin >> celsius;

    std::cout << celsius <<  " degrees Celsius is "
              << celsToFaren(celsius) << " degrees Fahrenheit.\n";


    return 0;
}

double celsToFaren(int celsius) {
    return celsius * (9.0 / 5.0) + 32;
}