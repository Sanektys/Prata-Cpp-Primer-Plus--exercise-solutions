#include <iostream>


int main() {
    std::cout << "Enter your income and the program will calculate\n"
                 "how much tax you have to pay.\n";
    std::cout << "To stop typing enter any letter or negative number\n";
    int income = 0;
    double tax = 0.0;
    while (true) {
        std::cout << "Enter income: ";
        std::cin >> income;
        if (!std::cin.good() || income < 0)
            break;

        tax = 0.0;
        if (income > 5000)
            income -= 5000;
        else {
            std::cout << "Your income is tax-free\n";
            continue;
        }
        if (income >= 10000) {
            income -= 10000;
            tax += 1000;
        }
        else {
            tax += income / 100.0 * 10.0;
            std::cout << "You shall pay following tax(10%): "
                      << tax << std::endl;
            continue;
        }
        if (income >= 20000) {
            income -= 20000;
            tax += 3000;
        }
        else {
            tax += income / 100.0 * 15.0;
            std::cout << "You shall pay following tax(10% + 15%): "
                      << tax << std::endl;
            continue;
        }
        while (income >= 35000) {
            income -= 35000;
            tax += 7000;
        }
        tax += income / 100.0 * 20.0;
        std::cout << "You shall pay following tax(10% + 15% + 20%): "
                  << tax << std::endl;
    }
    

    return 0;
}
