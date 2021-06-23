#include <iostream>
#include <cstring>

#include "golf.h"


Golf::Golf(const char* fullname, int handicap) {
    std::strcpy(fullname_, fullname);
    handicap_ = handicap;
}

int Golf::setGolf() {
    std::cout << "Enter player full name(or not for exit): ";
    char fullname[LEN]{};
    if (std::cin.getline(fullname, LEN) && std::strlen(fullname) == 0) {
        std::cout << "Enter terminated\n";

        return 0;
    }
    else if (!std::cin) {
        std::cin.clear();
        char temp{'\0'};
        while (std::cin.get(temp) && (temp != '\n' && temp != EOF));
        std::cout << "Enter terminated by EOF or something\a\n";

        return 0;
    }
    std::cout << "Enter player handicap: ";
    int handicap{};
    if ((std::cin >> handicap).good() == false) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Incorrect entered handicap.\a\n";

        return 0;
    }
    if (std::cin.get() != '\n')  //to take remaining symbol '\n'
        while (std::cin.get() != '\n');

    *this = Golf(fullname, handicap);

    return 1;
}

void Golf::show() const {
    std::cout << "Player full name:  " << fullname_ << std::endl;
    std::cout << "Player handicap:  " << handicap_ << std::endl;
    std::cout << std::endl;
}
