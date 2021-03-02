#include <iostream>


int main() {
    const char* month[12]{
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    int amount[12]{};

    std::cout << "Enter the number of books sold for each month\n"
                 "and the program will summarize the total number\n\n";
    int totalAmount{};
    std::cout << "Enter the amount of books sold...\n";
    for (int i = 0; i < 12; ++i) {
        std::cout << "\t\t\t\t...in " << *(month + i) << ": ";
        std::cin >> amount[i];
        totalAmount += amount[i];
    }
    std::cout << "\n\t\aTotal amount of sold books: " << totalAmount << std::endl;


    return 0;
}