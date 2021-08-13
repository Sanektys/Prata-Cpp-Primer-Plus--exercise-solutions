#include <iostream>

#include "classic.h"


inline void bravo(const Cd& disk) { disk.report(); }

int main() {
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17);
    Cd* pcd = &c1;

    std::cout << "\nUsing object directly:\n";
    c1.report();
    c2.report();
    std::cout << "\nUsing type cd* pointer to objects:\n";
    pcd->report();
    pcd = &c2;
    pcd->report();
    std::cout << "\nCalling a function with a Cd reference argument:\n";
    bravo(c1);
    bravo(c2);
    std::cout << "\nTesting assignment:\n";
    Classic copy;
    copy = c2;
    copy.report();


    return 0;
}
