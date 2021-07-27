#include <iostream>

#include "cow.h"


int main() {
    Cow muggy("Muggy", "Running at a gallop", 340.9);
    std::cout << "First cow:\n";
    muggy.showCow();
    Cow dally(muggy);
    std::cout << "Second cow:\n";
    dally.showCow();
    Cow torra;
    torra = Cow("Torra", "A melodious mooning in the morning", 428.25);
    std::cout << "Third cow:\n";
    torra.showCow();
    

    return 0;
}
