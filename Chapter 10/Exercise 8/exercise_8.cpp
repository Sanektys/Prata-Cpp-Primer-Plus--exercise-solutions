#include <iostream>

#include "list.h"

inline void showItem(const Item&);
void setItem(Item&);
void multiplyItem(Item&);

int main() {
    List list;
    list.add(100500);
    list.add(146);
    list.add(228);
    list.visit(showItem);
    std::cout << "\b\b \n";
    list.visit(setItem);
    list.visit(showItem);
    std::cout << "\b\b \n";
    list.visit(multiplyItem);
    list.visit(showItem);
    std::cout << "\b\b \nTerminate.\n";


    return 0;
}

inline void showItem(const Item &item) { std::cout << item << ", "; }

void setItem(Item& item) {
    std::cout << "Enter new value of item " << item << ": ";
    std::cin >> item;
    if (!std::cin)
        std::cin.clear();
    while (std::cin.get() != '\n');
}

void multiplyItem(Item& item) {
    std::cout << "Enter multiplier for item " << item << ": ";
    float mult = 1.0f;
    std::cin >> mult;
    if (!std::cin)
        std::cin.clear();
    while (std::cin.get() != '\n');
    std::cout << "Item " << item;
    item *= mult;
    std::cout << ", now " << item << std::endl;
}
