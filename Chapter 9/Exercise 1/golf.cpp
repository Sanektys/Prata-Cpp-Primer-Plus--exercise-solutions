#include <iostream>
#include <cstring>

#include "golf.h"


void setgolf(golf& golf, const char* fullname, int handicap) {
    std::strcpy(golf.fullname, fullname);
    golf.handicap = handicap;
}

int setgolf(golf& golf) {
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

    setgolf(golf, fullname, handicap);

    return 1;
}

inline void handicap(golf& golf, int handicap) { golf.handicap = handicap; }

void showgolf(const golf& golf) {
    std::cout << "Player full name:  " << golf.fullname << std::endl;
    std::cout << "Player handicap:  " << golf.handicap << std::endl;
    std::cout << std::endl;
}
