#include <iostream>


struct CandyBar {
    char name[20];
    float weight;
    int calorie;
};

int main() {
    CandyBar candyBarPack[3]{ {"Rot Front", 0.8f, 210}, 
                              {"Red October", 0.5f, 90}, 
                              {"Spanky Monkey", 1.2f, 280} };

    std::cout << R"(Name of the first candy is ")" << candyBarPack[0].name
              << R"(", weight: )" << candyBarPack[0].weight
              << " and calorie: " << candyBarPack[0].calorie << std::endl;
    std::cout << R"(Name of the second candy is ")" << (*(candyBarPack + 1)).name
              << R"(", weight: )" << (*(candyBarPack + 1)).weight
              << " and calorie: " << (*(candyBarPack + 1)).calorie << std::endl;
    std::cout << R"(Name of the third candy is ")" << (candyBarPack + 2)->name
              << R"(", weight: )" << (candyBarPack + 2)->weight
              << " and calorie: " << (candyBarPack + 2)->calorie << std::endl;


    return 0;
}