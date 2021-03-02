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
    int amount[3][12]{};

    std::cout << "Enter the number of books sold for each month during "
                 "three years\n"
                 "and the program will summarize the total number of it\n\n";

    int totalAmount[3]{};
    for (int j = 0; j < 3; ++j) {
        std::cout << "Enter the amount of books sold for year "
                  << j + 1 << "...\n";

        for (int i = 0; i < 12; ++i) {
            std::cout << "\t\t\t\t...in " << *(month + i) << ": ";
            std::cin >> *(*(amount + j) + i);
            *(totalAmount + j) += amount[j][i];
        }
    }

    std::cout << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << "\tAmount of sold books for year "
                  << i + 1 << ": " << totalAmount[i] << std::endl;
    std::cout << "\n\t\aTotal amount of sold books: "
              << totalAmount[0] + totalAmount[1] + totalAmount[2] << std::endl;
    


    return 0;
}
