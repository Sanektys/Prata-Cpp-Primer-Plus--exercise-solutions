#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>


bool isPalindrome(const std::string&);

int main() {
    std::cout << "Enter a palindrome in lowercase letters without\n"
                 " spaces or signs and the program will check\n"
                 " if it is indeed a palindrome.\n\n";
    std::string string;

    do {
        std::cout << R"(Enter a palindrome (or enter "quit" for exit): )";
        std::getline(std::cin, string);

        if ((std::cin.good() || std::cin.eof()) && "quit" != string)
            if (isPalindrome(string))
                std::cout << " Entered string is a palindrome.\n";
            else
                std::cout << " Entered string isn't a palindrome.\n";
        if (!std::cin.good()) {
            if (std::cin.eof()) {
                std::cin.clear();
                std::cin.putback('\n');
                std::cin.get();
            }
            else {
                std::cout << "\nA fault during an enter, please try again...\n";
                std::cin.clear();
                while (std::cin.get() != '\n');
            }
        }
    } while (string != "quit");


    return 0;
}

bool isPalindrome(const std::string& string) {
    if (string.size() <= 1)
        return false;

    std::string origin;
    
    for (auto character : string)
        if (std::isalpha(character))
            origin.push_back(char(std::tolower(character)));

    std::string reverse(origin);
    std::reverse(reverse.begin(), reverse.end());

    if (0 == reverse.compare(origin))
        return true;

    return false;
}