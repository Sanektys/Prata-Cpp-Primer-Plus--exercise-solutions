#include <iostream>

#include "stock.h"


const int STOCKS{4};


int main() {
    Stock stocks[STOCKS]{{"NanoSmart", 12, 20.0},
                         {"Boffo Objects", 200, 2.0},
                         {"Monolithic Obelisks", 130, 3.25},
                         {"Fleep Enterprises", 60, 6.5}};
    std::cout << "Stock holdings:\n";
    int stocksCount{};
    for ( ; stocksCount < STOCKS; stocksCount++)
        std::cout << stocks[stocksCount];
    const Stock* top = &stocks[0];
    for (stocksCount = 1; stocksCount < STOCKS; stocksCount++)
        top = &top->topValue(stocks[stocksCount]);

    std::cout << "\nMost valuable holding:\n" << *top;


    return 0;
}
