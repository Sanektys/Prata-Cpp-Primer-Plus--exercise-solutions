#include <iostream>

#include "wine.h"


int main() {
    std::cout << "Enter name of wine: ";
    char lab[50]{};
    std::cin.getline(lab, 50);
    std::cout << "Enter number of years: ";
    int years{};
    std::cin >> years;

    Wine holding(lab, years);
    holding.getBottles();
    holding.show();

    const int YEARS{3};
    int y[YEARS]{1993, 1995, 1998};
    int b[YEARS]{48, 60, 72};

    Wine more("Gushing Grape Red", YEARS, y, b);
    more.show();
    std::cout << "Total bottles for " << more.label()
              << ": " << more.sum()
              << "\nBye!\n";


    return 0;
}
