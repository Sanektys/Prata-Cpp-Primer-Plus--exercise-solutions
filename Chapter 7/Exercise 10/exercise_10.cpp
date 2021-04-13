#include <iostream>


double calculate(double, double, double (*)(double, double));
double add(double, double);
double sub(double, double);
double mul(double, double);
double div(double, double);

int main(void) {
    double (*operation[])(double, double){add, sub, mul, div, nullptr};
    std::cout << "Enter two numbers and the program will perform\n"
                 "basic arithmetic operations on them: ";
    double firstNum{0.0};
    double secondNum{0.0};
    int i = 0;
    while ((std::cin >> firstNum >> secondNum).good()) {
        i = 0;
        while (operation[i]) {
            std::cout << calculate(firstNum, secondNum, operation[i])
                      << std::endl;
            ++i;
        }
        std::cout << "Enter another two number if you want to continue\n"
                  << "or enter any letter to exit: ";
    }
    std::cout << "Terminate.\n";


    return 0;
}

double calculate(double a, double b, double(*operation)(double, double)) {
    return operation(a, b);
}

double add(double a, double b) {
    std::cout << a << " + " << b << " = ";
    return a + b;
}

double sub(double a, double b) {
    std::cout << a << " - " << b << " = ";
    return a - b;
}

double mul(double a, double b) {
    std::cout << a << " * " << b << " = ";
    return a * b;
}

double div(double a, double b) {
    std::cout << a << " / " << b << " = ";
    return a / b;
}
