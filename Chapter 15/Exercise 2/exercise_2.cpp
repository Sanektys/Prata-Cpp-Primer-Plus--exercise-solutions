#include <iostream>
#include <string>
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
            std::cout << e.what() << "Try again.\n";
            continue;
        }
    }
    std::cout << "Bye!\n";


    return 0;
}


double hmean(double a, double b) {
    if (a == -b) {
        std::string message;
        message = std::string("Harmonic mean(") + std::to_string(a) + ", "
                  + std::to_string(b) + "): "
                  + "invalid arguments: a = -b\n";
        throw BadHmean(message);
    }
    
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
    if (a < 0 || b < 0) {
        std::string message;
        message = std::string("Geometric mean arguments should be >= 0\n")
                  + "Values used: " + std::to_string(a) + ", " 
                  + std::to_string(b) + '\n';
        throw BadGmean(message);
    }

    return std::sqrt(a * b);
}