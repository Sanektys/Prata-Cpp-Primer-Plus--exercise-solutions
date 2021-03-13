#include <iostream>
#include <cctype>
#include <cstring>


int main() {
    std::cout << "Enter words (q to quit)\n";
    short vowels{0};
    short consonants{0};
    short others{};
    char word[20]{};
    while ((std::cin >> word).good() && !('q' == word[0] && strlen(word) == 1)) {
        if (isalpha(word[0]))
            switch (word[0]) {
            case 'a' :
            case 'A' :
            case 'e' :
            case 'E' :
            case 'i' :
            case 'I' :
            case 'o' :
            case 'O' :
            case 'u' :
            case 'U' :
            case 'y' :
            case 'Y' :
                ++vowels;
                break;
            default :
                ++consonants;
            }
        else
            ++others;
    }
    std::cout << vowels << " words beginning with vowels\n";
    std::cout << consonants << " words beginning with consonants\n";
    std::cout << others << " others\n";


    return 0;
}
