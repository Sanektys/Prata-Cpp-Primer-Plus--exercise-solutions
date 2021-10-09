#include <iostream>
#include <cmath>

#include "exc_mean.h"


double hmean(double a, double b);
double gmean(double a, double b);

int main(void) {
    double x{}, y{}, z{};
    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y) {
        try {
            z = hmean(x, y);
            std::cout << "Harmonic mean of " << x << " and " << y
                      << " is " << z << std::endl;
            z = gmean(x, y);
            std::cout << "Geometric mean of " << x << " and " << y
                      << " is " << z << std::endl;
            std::cout << "Enter next set of numbers <q to quit>: ";
        }
        catch (std::exception& e) {
            std::cout << e.what() << "Terminate the program.\a\n\n";
            break;
        }
    }
    std::cout << "Bye!\n";


    return 0;
}


double hmean(double a, double b) {
    if (a == -b)
        throw BadHmean("Harmonic mean arguments should be"
                       " not mutually negative", a, b);
    
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
    if (a < 0 || b < 0)
        throw BadGmean("Geometric mean arguments should be equally"
                       " or greater than zero", a, b);

    return std::sqrt(a * b);
}