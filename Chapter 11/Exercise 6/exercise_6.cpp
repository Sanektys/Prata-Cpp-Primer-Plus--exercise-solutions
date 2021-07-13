#include "stonewt.h"


int main() {
    Stonewt stones[6]{{11, 2.47}, {11, 0.0}, {11}};
    std::cout << "Enter three last stones value:\n";
    for (int i{}; i < 3; i++) {
        stones[i].inFloatPounds();
        std::cout << "Element " << i + 1 << " is: " << stones[i] << std::endl;
    }
    for (int i{3}; i < 6; i++) {
        std::cout << "Element " << i + 1 << " is: ";
        double pounds{};
        std::cin >> pounds;
        if (!std::cin.good()) {
            if (std::cin.eof()) {
                std::cin.clear();
                std::cin.putback('\n');
                std::cin.putback('\n');
                break;
            }
            std::cout << "Incorrect enter, try again...\n";
            std::cin.clear();
            while (std::cin.get() != '\n');
            i--;
            continue;
        }
        stones[i] = pounds;
    }
    Stonewt sample{11, 0.0};
    short numberOfElements{};
    double max{stones[0]}, min{stones[0]};
    for (int i{}; i < 6; i++) {
        if (stones[i] >= sample)
            numberOfElements++;
        if (stones[i] < min)
            min = double(stones[i]);
        else if (stones[i] > max)
            max = double(stones[i]);
    }
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(2);
    std::cout << "Number of elements more or equal than " << sample;
    sample.inFloatPounds();
    std::cout << '(' << sample << "): " << numberOfElements << std::endl;
    std::cout << "Mininum element: " << min << std::endl
              << "Maximum element: " << max << std::endl;
    std::cout << "Terminate...\n";


    return 0;
}
