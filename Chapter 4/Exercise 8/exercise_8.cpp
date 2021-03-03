#include <iostream>


struct Pizza {
    char companyName[40];
    float weight;
    int diameter;
};

int main() {
    std::cout << "Enter pizza parameters:\n";
    Pizza* currentPizza = new Pizza;
    std::cout << " - pizza diameter: ";
    (std::cin >> (*currentPizza).diameter).get();
    std::cout << " - name of manufacturer: ";
    std::cin.get(currentPizza->companyName, 40);
    std::cout << " - weight of the pizza: ";
    std::cin >> currentPizza->weight;

    std::cout << "\nYou entered follow pizza parameters: "
              << "\nManufacturer's name: " << (*currentPizza).companyName
              << "\nPizza diameter: " << currentPizza->diameter
              << "\nPizza weight: " << currentPizza->weight << std::endl;
    delete currentPizza;


    return 0;
}
