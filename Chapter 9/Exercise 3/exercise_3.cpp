#include <iostream>
#include <cstring>


struct shaff {
    char dross[20];
    int slag;
};

static char buffer[48];

int main () {
    //std::cout << "Structure align is " << alignof(shaff) << std::endl;
    //std::cout << "Structure size is " << sizeof(shaff) << std::endl;
    std::cout << "Choose type of 'new' placement\n"
                 "(1 - in static buffer; 2 - in heap buffer): ";
    short choice{};
    while (true) {
        std::cin >> choice;
        if (!std::cin.good()) {
            if (std::cin.eof()) {
                std::cout << "EOF is entered, terminate...\n";

                return 0;
            }
            std::cout << "Incorrect enter, try type 1 or 2 again: ";
            std::cin.clear();
            while (std::cin.get() != '\n');
            continue;
        }
        if (choice < 1 || choice > 2) {
            std::cout << "Enter only 1 or 2: ";
            continue;
        }
        while (std::cin.get() != '\n');
        break;
    }
    shaff* twoElement{nullptr};
    switch (choice) {
        case 1 :
            twoElement = new (buffer) shaff[2];
            break;
        case 2 :
            char* newBuffer = new char[48];
            twoElement = new (newBuffer) shaff[2];
            break;
    }

    std::strcpy(twoElement[0].dross, "cinder");
    twoElement[0].slag = 146;
    std::strcpy(twoElement[1].dross, "sinter");
    twoElement[1].slag = 7111972;

    std::cout << std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << "dross: " << twoElement[i].dross << std::endl;
        std::cout << "slag: " << twoElement[i].slag << std::endl;
        std::cout << std::endl;
    }

    if (2 == choice)
        delete[] twoElement;

    
    return 0;
}
