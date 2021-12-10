#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>

                
int main() {
    std::srand(std::time(nullptr));

    std::vector<std::string> wordlist{};
    {
        std::string word{};
        std::ifstream file("words.txt");
        if (file.is_open()) {
            file >> word;
            while (!file.eof()) {
                wordlist.push_back(word);
                file >> word;
            }
            file.close();
        }
        else {
            std::cout << "The file which containing the words is missing"
                        " (words.txt).\n";
            std::cout << "Bye.\n";

            return 1;
        }
    }
    const std::size_t NUM{wordlist.size()};

    char play{};
    std::cout << "Will you play a word game? <y/n> ";
    std::cin >> play;
    play = std::tolower(play);

    while (play == 'y') {
        std::string target = wordlist[std::rand() % NUM];
        int length = target.length();

        std::string attempt(length, '-');
        std::string badchars{};
        int guesses{6};

        std::cout << "Guess my secret word. It has " << length
                  << " letters, and you guess\n"
                  << "one letter at a time. You get " << guesses
                  << " wrong guesses.\n";
        std::cout << "Your word: " << attempt << std::endl;

        while (guesses > 0 && attempt != target) {
            char letter{};
            std::cout << "Guess a letter: ";
            std::cin >> letter;

            if (badchars.find(letter) != std::string::npos
                || attempt.find(letter) != std::string::npos) {
                    std::cout << "You already guessed that. Try again.\n";
                    continue;
            }

            std::size_t loc = target.find(letter);
            if (loc == std::string::npos) {
                std::cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter;
            }
            else {
                std::cout << "Good guess!\n";
                attempt[loc] = letter;
                loc = target.find(letter, loc + 1);
                while (loc != std::string::npos) {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }

            std::cout << "Your word: " << attempt << std::endl;
            if (attempt != target) {
                if (badchars.length() > 0)
                    std::cout << "Bad choices: " << badchars << std::endl;
                std::cout << guesses << " bad guesses left\n";
            }
        }

        if (guesses > 0)
            std::cout << "That's right!\n";
        else
            std::cout << "Sorry, the word is " << target << ".\n";
        
        std::cout << "Will you play another? <y/n> ";
        std::cin >> play;
        play = std::tolower(play);
    }

    std::cout << "Bye\n";


    return 0;
}