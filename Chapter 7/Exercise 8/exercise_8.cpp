#include <iostream>


const int SEASONS = 4;
const char* snames[SEASONS]{"Spring", "Summer", "Fall", "Winter"};

struct expenses
{
    double exp[SEASONS];
};

void fill(expenses*);
void show(expenses);

int main(void) {
    expenses expenses{};
    fill(&expenses);
    show(expenses);


    return 0;
}

void fill(expenses* expenses) {
    for (int i = 0; i < SEASONS; i++) {
        std::cout << "Enter " << snames[i] << " expenses: ";
        std::cin >> expenses->exp[i];
    }
}

void show(expenses expenses) {
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < SEASONS; i++) {
        std::cout << snames[i] << ": $" << expenses.exp[i] << std::endl;
        total += expenses.exp[i];
    }
    std::cout << "Total Expenses: $" << total << std::endl;
}
