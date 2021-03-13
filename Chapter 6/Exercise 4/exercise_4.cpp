#include <iostream>
#include <array>


const short STRSIZE = 40;
const short LISTSIZE = 6;

enum class Preference {
    FULLNAME,
    TITLE,
    BOPNAME
};

struct Bop {
    char fullname[STRSIZE];
    char title[STRSIZE];
    char bopname[STRSIZE];
    Preference preference;
};

bool choice(char, Bop*, short);

int main() {
    std::cout << "Benevolent Order of Programmers Report\n";
    std::cout << "a. display by name      b. display by title\n"
              << "c. display by bopname   d. display by preference\n"
              << "q. quit\n";

    Bop personList[LISTSIZE]{
        { "Wimp Macho", "Senior programmer", "LOVEFIST", Preference::FULLNAME },
        { "Raki Rhodes", "Junior programmer", "Sandevic", Preference::TITLE },
        { "Celia Laiter", "CEO", "MIPS", Preference::BOPNAME },
        { "Hoppy Hipman", "Analyst Trainee", "Catalyst", Preference::TITLE },
        { "Pat Hand", "Middle programmer", "LOOPY", Preference::BOPNAME },
        { "Ilya Shesterov", "Inter programmer", "Sanektys", Preference::BOPNAME }
    };

    char select = 0;
    bool isRun = true;
    while (isRun) {
        std::cin >> select;
        isRun = choice(select, personList, LISTSIZE);
    }


    return 0;
}

bool choice(char choice, Bop* list, const short SIZE) {
    switch (choice) {
        case 'a' :
        case 'A' :
            for (short i = 0; i < SIZE; i++)
                std::cout << list[i].fullname << std::endl;
            return true;
        case 'b' :
        case 'B' :
            for (short i = 0; i < SIZE; i++)
                std::cout << (*(list + i)).title << std::endl;
            return true;
        case 'c' :
        case 'C' :
            for (short i = 0; i < SIZE; i++)
                std::cout << list[i].bopname << std::endl;
            return true;
        case 'd' :
        case 'D' :
            for (short i = 0; i < SIZE; i++)
                switch (list[i].preference) {
                    case Preference::FULLNAME :
                        std::cout << list[i].fullname << std::endl;
                        break;
                    case Preference::TITLE :
                        std::cout << list[i].title << std::endl;
                        break;
                    case Preference::BOPNAME :
                        std::cout << list[i].bopname << std::endl;
                }
            return true;
        case 'q' :
        case 'Q' :
            std::cout << "Bye!\n";
            return false;
        default :
            std::cout << "You entered incorrect option, try: a, b, c, d: ";
            return true;
    }
}