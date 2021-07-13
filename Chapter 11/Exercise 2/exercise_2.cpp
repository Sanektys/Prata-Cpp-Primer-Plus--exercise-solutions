#include <ctime>
#include <random>

#include "vector.h"


int main() {
    std::mt19937 random;
    random.seed(time(nullptr));

    double direction{0.0};
    VECTOR::Vector step{};
    VECTOR::Vector result{0.0, 0.0};
    unsigned long steps{0};
    double target{0.0};
    double deltaStep{0.0};

    std::cout << "Enter target distance (q to quit): ";
    while (std::cin >> target) {
        std::cout << "Enter step length: ";
        if (!(std::cin >> deltaStep))
            break;
        while (result.magnitudeValue() < target) {
            direction = random() % 360;
            step.reset(deltaStep, direction, VECTOR::Vector::POLAR);
            result = result + step;
            steps++;
        }
        std::cout << "After " << steps << " steps, the subject "
               << "has the following location:\n"
               << result << std::endl;
        result.polarMode();
        std::cout << " or\n"
               << result << "\nAverage outward distance per step = "
               << result.magnitudeValue() / steps << std::endl
               << std::endl;
        steps = 0;
        result.reset(0.0, 0.0);
        std::cout << "Enter target distance (q to quit): ";
    }
    std::cout << "Bye!\n";
    std::cin.clear();
    while (std::cin.get() != '\n');


    return 0;
}
