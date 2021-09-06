#include <iostream>

#include "wine.h"


Wine::Wine() : std::string("null"), PairArray({0, 0}, {0, 0}) {}

Wine::Wine(const char* label, size_t yearsAmount, const int years[],
           const int bottles[])
    : std::string(label), PairArray(ArrayInt(years, yearsAmount),
                                    ArrayInt(bottles, yearsAmount)) {}

Wine::Wine(const char *label, int yearsAmount)
    : std::string(label), PairArray(ArrayInt(yearsAmount),
                                    ArrayInt(yearsAmount)) {}


void Wine::getBottles() {
    std::cout << "Enter " << *((std::string*)this);
    size_t years = ((PairArray*)this)->first().size();
    std::cout << " data for " << years << " year(s):\n";
    int year{};
    int bottles{};
    for (size_t i{}; i < years; i++) {
        std::cout << "Enter year: ";
        std::cin >> year;
        if (!std::cin.good())
            break;
        first()[i] = year;
        std::cout << "Enter bottles for that year: ";
        std::cin >> bottles;
        if (!std::cin.good())
            break;
        second()[i] = bottles;
    }
    if (!std::cin.good()) {
        std::cout << "Incorrect entered data.\n";
        std::cin.clear();
        while (std::cin.get() == '\n');
    }
}

void Wine::show() const {
    std::cout << "Wine: " << (const std::string&)(*this) << '\n'
              << '\t' << "Year" << '\t' << "Bottles" << '\n';
    size_t size = first().size();
    for (size_t i{}; i < size; i++)
        std::cout << '\t' << first()[i]
                  << '\t' << second()[i]
                  << '\n';
}
