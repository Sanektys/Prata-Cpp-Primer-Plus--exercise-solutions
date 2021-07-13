#include <ctime>
#include <random>
#include <fstream>

#include "vector.h"


void showResult(std::ostream&, VECTOR::Vector&, unsigned long);

int main() {
    std::random_device random;
    std::ofstream outputFile{"log.txt", std::ios::app};

    double direction{0.0};
    VECTOR::Vector step;
    VECTOR::Vector result(0.0, 0.0);
    unsigned long steps{0};
    double target{0.0};
    double deltaStep{0.0};

    std::cout << "Enter target distance (q to quit): ";
    while (std::cin >> target) {
        std::cout << "Enter step length: ";
        if (!(std::cin >> deltaStep))
            break;
        if (outputFile.is_open()) {
            time_t currentTime = std::time(nullptr);
            outputFile << "Time: " << std::ctime(&currentTime)
                       << "Target Distance: " << target
                       << ", Step Size: " << deltaStep
                       << "\n0: " << result << std::endl;
        }
        while (result.magnitudeValue() < target) {
            direction = random() % 360;
            step.reset(deltaStep, direction, VECTOR::Vector::POLAR);
            result = result + step;
            steps++;
            if (outputFile.is_open())
                outputFile << steps << ": " << result << std::endl;
        }
        showResult(std::cout, result, steps);
        showResult(outputFile, result, steps);
        steps = 0;
        result.reset(0.0, 0.0);
        std::cout << "Enter target distance (q to quit): ";
    }
    std::cout << "Bye!\n";
    std::cin.clear();
    while (std::cin.get() != '\n');


    return 0;
}

void showResult(std::ostream& stream, VECTOR::Vector& result,
                unsigned long steps) {
    stream << "After " << steps << " steps, the subject "
           << "has the following location:\n"
           << result << std::endl;
    result.polarMode();
    stream << " or\n" << result
           << "\nAverage outward distance per step = "
           << result.magnitudeValue() / steps << std::endl << std::endl;
    result.rectangleMode();
}
