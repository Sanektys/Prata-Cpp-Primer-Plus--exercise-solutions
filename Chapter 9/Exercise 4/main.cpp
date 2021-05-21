#include <iostream>

#include "sales.h"


int main(void) {
    SALES::Sales firstSummary{};
    SALES::Sales secondSummary{};

    SALES::setSales(firstSummary);

    std::cout << "\nEnter the number of income for the year\n"
              << "and the amount of these sales revenue:\n";
    std::cout << "Enter number of income: ";
    int incomeNum{0};
    while (true) {
        std::cin >> incomeNum;
        if (std::cin && incomeNum > 0)
            break;
        else {
            std::cout << "Incorrect entered number of income, try again: ";
            if (std::cin.eof()) {
                std::cin.clear();
                std::cin.putback('\n');
                continue;
            }
            std::cin.clear();
            while (std::cin.get() != '\n');
            continue;
        }
    }
    std::cout << "Fill in the income array:\n";
    double income[incomeNum];
    int i = 0;
    for (; i < incomeNum; i++) {
        std::cout << " - income " << i + 1 << ": ";
        std::cin >> income[i];
        if (std::cin.good() == false) {
            if (std::cin.eof()) {
                std::cout << "Enter terminated by EOF\n";
                std::cin.clear();
                break;
            }
            std::cout << "Incorrect enter, try again";
            std::cin.clear();
            while (std::cin.get() != '\n');
            --i;
            continue;
        }
    }
    if (i != incomeNum) {
        double realIncome[i];
        for (int k = 0; k < i; k++)
            realIncome[k] = income[k];
        SALES::setSales(secondSummary, realIncome, i);
    }
    else
        SALES::setSales(secondSummary, income, incomeNum);

    std::cout << "\n#1\n";
    SALES::showSales(firstSummary);
    std::cout << "\n#2\n";
    SALES::showSales(secondSummary);
    std::cout << "\n\nDone!\n";


    return 0;
}
