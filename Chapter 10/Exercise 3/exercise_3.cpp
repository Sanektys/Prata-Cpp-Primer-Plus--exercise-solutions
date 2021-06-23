#include <iostream>

#include "golf.h"


int main(void) {
    std::cout << "Enter information about 5 players in a golf.\n"
                 "Their full name and handicap...\n\n";
    Golf players[5]{};
    int i = 0;
    for (; i < 5; i++) {
        if (!players[i].setGolf())
            break;
    }
    std::cout << "\nYou entered the following data:\n\n";
    if (0 == i) {
        std::cout << "*Null*\n\nTerminate\n";

        return 0;
    }
    for (int j = 0; j < i; j++)
        players[j].show();
    std::cout << "\nTerminate.\n";


    return 0;
}
