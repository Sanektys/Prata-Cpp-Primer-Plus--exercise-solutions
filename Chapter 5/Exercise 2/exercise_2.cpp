#include <iostream>
#include <array>


const int ArSize = 101;

int main() {
    std::array<long double, ArSize> factorials{};
    factorials.at(1) = factorials.at(0) = 1.0;
    for (unsigned int i = 2; i < factorials.size(); i++)
        factorials.at(i) = i * factorials.at(i - 1);

    for (int i = 0; i < ArSize; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;


    return 0;
}