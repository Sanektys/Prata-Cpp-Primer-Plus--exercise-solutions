#include <iostream>
#include <string.h>


int main() {
    std::cout << "Enter your first name: ";
    char firstName[40]{};
    std::cin >> firstName;
    std::cout << "Enter your last name: ";
    char lastName[40]{};
    std::cin >> lastName;

    char resultString[82]{};
    strcat(resultString, lastName);
    strcat(resultString, ", ");
    strcat(resultString, firstName);
    std::cout << "Here's the information in a single string: "
              << resultString << std::endl;


    return 0;
}
