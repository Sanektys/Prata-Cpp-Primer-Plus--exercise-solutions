#include <iostream>


struct CandyBar {
    char name[20];
    float weight;
    int calorie;
} snack{ "Mocha Munch", 2.3f, 350 };


int main() {
    std::cout << R"(Name of your snack is ")" << snack.name
              << R"(", weight: )" << snack.weight
              << " and calorie: " << snack.calorie << std::endl;


    return 0;
}
