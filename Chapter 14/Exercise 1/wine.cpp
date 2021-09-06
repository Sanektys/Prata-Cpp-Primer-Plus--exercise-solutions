#include <iostream>

#include "wine.h"


Wine::Wine() : label_("null"), value_({0, 0}, {0, 0}) {}

Wine::Wine(const char* label, size_t yearsAmount, const int years[],
           const int bottles[])
    : label_(label), value_(ArrayInt(years, yearsAmount),
                            ArrayInt(bottles, yearsAmount)) {}

Wine::Wine(const char *label, int yearsAmount)
    : label_(label), value_(ArrayInt(yearsAmount),
                            ArrayInt(yearsAmount)) {}


void Wine::getBottles() {
    std::cout << "Enter " << this->label_;
    size_t years = value_.first().size();
    std::cout << " data for " << years << " year(s):\n";
    int year{};
    int bottles{};
    for (size_t i{}; i < years; i++) {
        std::cout << "Enter year: ";
        std::cin >> year;
        if (!std::cin.good())
            break;
        value_.first()[i] = year;
        std::cout << "Enter bottles for that year: ";
        std::cin >> bottles;
        if (!std::cin.good())
            break;
        value_.second()[i] =  bottles;
    }
    if (!std::cin.good()) {
        std::cout << "Incorrect entered data.\n";
        std::cin.clear();
        while (std::cin.get() == '\n');
    }
}

void Wine::show() const {
    std::cout << "Wine: " << label_ << '\n'
              << '\t' << "Year" << '\t' << "Bottles" << '\n';
    size_t size = value_.first().size();
    for (size_t i{}; i < size; i++)
        std::cout << '\t' << value_.first()[i]
                  << '\t' << value_.second()[i]
                  << '\n';
}
