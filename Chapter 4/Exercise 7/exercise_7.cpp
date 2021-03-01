#include <iostream>


struct pizza {
    char companyName[40];
    int diameter;
    float weight;
};

int main() {
    std::cout << "Enter pizza parameters:\n";
    pizza currentPizza{};
    std::cout << " - name of manufacturer: ";
    std::cin.get(currentPizza.companyName, 40).get();
    std::cout << " - pizza diameter: ";
    std::cin >> currentPizza.diameter;
    std::cout << " - weight of the pizza: ";
    std::cin >> currentPizza.weight;

    std::cout << "\nYou entered follow pizza parameters: "
              << "\nManufacturer's name: " << currentPizza.companyName
              << "\nPizza diameter: " << currentPizza.diameter
              << "\nPizza weight: " << currentPizza.weight << std::endl;


    return 0;
}
