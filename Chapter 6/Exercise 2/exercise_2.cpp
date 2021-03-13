#include <iostream>
#include <array>


int main() {
    std::cout << "Enter up to ten donation amounts "
                 "and the program will calculate\n"
                 "the average value and the number "
                 "of donations above the average.\n\n";
    std::array<double, 10> donate{};

    short items = 1;
    do
        std::cout << "Enter donation amount #" << items << ": ";
    while ((std::cin >> donate.at(items - 1)).good() && ++items <= 10);
    --items;
    if (items == 0) {
        std::cout << "There are no donations\n\a";
        return 0;
    }

    double average = 0.0;
    for (short i = 0; i < items; ++i)
        average += donate[i];
    average /= items;

    short aboveAverageNumber{ 0 };
    for (double sum : donate)
        if (sum > average)
            ++aboveAverageNumber;

    std::cout << "\nThe average sum of donation: " << average << std::endl
              << "Number of sum higher than average: " << aboveAverageNumber
              << std::endl;


    return 0;
}
