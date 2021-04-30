#include <iostream>
#include <cctype>


void toUpper(std::string&);

int main() {
    std::cout << "Enter a string (q to quit): ";
    std::string message;
    while (std::cin.good()) {
        std::getline(std::cin, message);
        if ('q' == message[0] && '\0' == message[1])
            break;
        toUpper(message);
        std::cout << message << std::endl;
        std::cout << "Next string (q to quit): ";
    }
    std::cout << "Bye.\n";


    return 0;
}


void toUpper(std::string& string) {
    int i{0};
    while (string[i]) {
        string[i] = toupper(string[i]);
        i++;
    }
}
