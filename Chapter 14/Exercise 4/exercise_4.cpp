#include <iostream>
#include <cstring>

#include "person.h"


const int SIZE{5};


int main() {
    Person* dudes[SIZE]{};
    int ct{};
    for (ct = 0; ct < SIZE; ct++) {
        char choice{'\0'};
        std::cout << "\nEnter the kind of person:\n"
                  << "c: common person  g: gunslinger\n"
                  << "p: poker player   b: bad dude\n"
                  << "q: quit\n"
                  << " >> ";
        std::cin >> choice;

        while (std::strchr("cgpbq", choice) == NULL) {
            std::cout << R"(Please enter "c", "g", "p", "b" or "q": )";
            std::cin >> choice;
        }
        if (choice == 'q')
            break;
        
        switch (choice) {
            case 'c' :
                dudes[ct] = new Person;
                break;
            case 'g' :
                dudes[ct] = new Gunslinger;
                break;
            case 'p' :
                dudes[ct] = new PokerPlayer;
                break;
            case 'b' :
                dudes[ct] = new BadDude;
                break;
        }
        
        std::cin.get();
        dudes[ct]->set();
    }
    std::cout << "\nHere is your dudes:\n";
    int i{};
    for (i = 0; i < ct; i++) {
        std::cout << std::endl;
        dudes[i]->show();
    }
    for (i = 0; i < ct; i++)
        delete dudes[i];
    std::cout << "\nBye.\n";


    return 0;
}
