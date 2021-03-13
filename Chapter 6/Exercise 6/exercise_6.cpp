#include <iostream>


struct Patron
{
    std::string name;
    double contribution;
};

int main() {
    std::cout << "The program compiles a list of patrons.\n"
                 "Enter the number of patrons and then "
                 "each patron's donation data.\n"
                 "The program will separately identify people "
                 "who have donated $10,000 or more.\n";
    std::cout << "\nEnter number of patrons: ___\b\b\b";
    short patronsNumber{0};
    std::cin >> patronsNumber;
    Patron* patron{nullptr};
    if (patronsNumber > 0)
        patron = new Patron[patronsNumber];
    else
        return 0;

    for (int i = 0 ; i < patronsNumber; i++) {
        std::cout << "Enter patron's name: ";
        std::cin >> patron[i].name;
        std::cout << "Enter patron's contribution: $______\b\b\b\b\b\b";
        std::cin >> patron[i].contribution;
    }
    std::cout << "\nGrand Patrons\n";
    bool isNone = true;
    for (int i = 0; i < patronsNumber; i++) {
        if (10000.0 <= patron[i].contribution) {
            std::cout << patron[i].name << " - $" << patron[i].contribution
                      << std::endl;
            isNone = false;
        }
    }
    if (isNone)
        std::cout << "none\n";
    std::cout << "\nPatrons\n";
    isNone = true;
    for (int i = 0; i < patronsNumber; i++) {
        if (10000.0 > patron[i].contribution) {
            std::cout << patron[i].name << " - $" << patron[i].contribution
                      << std::endl;
            isNone = false;
        }
    }
    if (isNone)
        std::cout << "none\n";
    delete[] patron;
    patron = nullptr;


    return 0;
}
