#include <iostream>

#include "stack.h"


int main(void) {
    Stack plates;
    std::cout << "Filling first stack('plates'):\n";
    for (int i{}; i < 12; i++) {
        if (!plates.isFull()) {
            plates.push(i);
            std::cout << i << ", ";
        }
        else
            std::cout << "stack is full! ";
    }

    std::cout << "\n\nFilling second stack('potatos'):\n";
    Stack potatos(6);
    for (int i{}; i < 12; i++) {
        if (!potatos.push(i)) {
            std::cout << "Stack is full!";
            break;
        }
        std::cout << i << ", ";
    }

    std::cout << "\n\nRelease an stack('potatos'):\n";
    unsigned long item{};
    for (int i{}; i < 4; i++) {
        if (!potatos.pop(item)) {
            std::cout << "Stack is empty!";
            break;
        }
        std::cout << item << ", ";
    }

    std::cout << "\n\nPotatos in plates('plates = potatos'):\n";
    plates = potatos;
    while (plates.pop(item))
        std::cout << item << ", ";

    std::cout << "\n\nTapinambur from potato('tapinambut(potato)'):\n";
    Stack tapinambur(potatos);
    {
        int i{};
        while (tapinambur.push(++i));
    }
    while (tapinambur.pop(item))
        std::cout << item << ", ";
    std::cout << "\n\nBye!\n";


    return 0;
}
