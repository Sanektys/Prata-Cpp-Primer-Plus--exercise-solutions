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
    short attempts{0};

    std::cout << "Enter target distance (q to quit): ";
    while (std::cin >> target && target > 0.0) {
        std::cout << "Enter step length: ";
        if (!(std::cin >> deltaStep) || deltaStep <= 0.0)
            break;
        std::cout << "Enter number of attempts: ";
        if (!(std::cin >> attempts) || attempts < 1)
            break;

        unsigned long minSteps{0};
        unsigned long maxSteps{0};
        unsigned long totalSteps{0};
        for (int i{0}; i < attempts; i++) {
            while (result.magnitudeValue() < target) {
                direction = random() % 360;
                step.reset(deltaStep, direction, VECTOR::Vector::POLAR);
                result = result + step;
                steps++;
            }
            if (0 == i)
                minSteps = maxSteps = steps;
            else {
                if (minSteps > steps)
                    minSteps = steps;
                else if (maxSteps < steps)
                    maxSteps = steps;
            }
            totalSteps += steps;

            steps = 0;
            result.reset(0.0, 0.0);
        }
        unsigned long averageSteps{totalSteps / attempts};

        std::cout << "For " << attempts << " attempts, the following results"
                  << " were obtained:\n";
        std::cout << " --> average number of steps: " << averageSteps
                  << "\n --> mininum number of steps: " << minSteps
                  << "\n --> maximum number of steps: " << maxSteps
                  << std::endl;

        std::cout << "\nEnter target distance (q to quit): ";
    }
    std::cout << "Bye!\n";
    std::cin.clear();
    while (std::cin.get() != '\n');


    return 0;
}
