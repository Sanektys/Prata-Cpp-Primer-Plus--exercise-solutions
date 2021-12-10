#include <iostream>
#include <string>
#include <algorithm>


bool isPalindrome(const std::string&);

int main() {
    std::cout << "Enter a palindrome in lowercase letters without\n"
                 " spaces or signs and the program will check\n"
                 " if it is indeed a palindrome.\n\n";
    std::string string;

    do {
        std::cout << R"(Enter a palindrome (or enter "quit" for exit): )";
        std::cin >> string;

        if (std::cin.good() && "quit" != string)
            if (isPalindrome(string))
                std::cout << "Entered string is a palindrome.\n";
            else
                std::cout << "Entered string isn't a palindrome.\n";
        else if (!std::cin.good()) {
            std::cout << "\nA fault during an enter, please try again...\n";
            if (std::cin.eof()) {
                std::cin.clear();
                std::cin.putback('\n');
                std::cin.putback('\n');
            }
            else {
                std::cin.clear();
                while (std::cin.get() != '\n');
            }
        }
    } while (string != "quit");


    return 0;
}

bool isPalindrome(const std::string& string) {
    std::string reverse(string);
    std::reverse(reverse.begin(), reverse.end());
    if (0 == reverse.compare(string))
        return true;

    return false;
}