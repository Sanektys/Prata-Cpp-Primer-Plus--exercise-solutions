#include <iostream>


struct CandyBar
{
    char name[20];
    double weight;
    int calorie;
};

void setCandyBar(CandyBar&, const char* = "Millennium Munch",
                 const double = 2.85, const int = 350);

void showCandyBar(const CandyBar&);

int main(void) {
    std::cout << "Candy bar with default specifications:\n";
    CandyBar candy;
    setCandyBar(candy);
    showCandyBar(candy);

    std::cout << "Candy bar with custom specifications:\n";
    setCandyBar(candy, "Red October", 1.91);
    showCandyBar(candy);


    return 0;
}


void setCandyBar(CandyBar& candy, const char* name, const double weight,
                 const int calorie) {
    int i{0};
    while (*name) {
        candy.name[i++] = *name++;
        if (19 == i)
            break;
    }
    candy.name[i] = '\0';
    candy.weight = weight;
    candy.calorie = calorie;
}

void showCandyBar(const CandyBar& candy) {
    std::cout << "Candy bar name - " << candy.name    << std::endl
              << "...weight - "      << candy.weight  << std::endl
              << "...calorie - "     << candy.calorie << std::endl;
}
