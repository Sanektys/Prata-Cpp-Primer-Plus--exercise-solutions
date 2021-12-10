#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>


std::vector<int> lotto(int, int);


int main() {
    std::srand(std::time(nullptr));

    std::cout << "The program displays the winning numbers\n"
                 "in the lottery ticket\n";
    int numbers{}, picked{};
    do {
        std::cout << "Enter the total number of numbers in lottery ticket:"
                  << "___\b\b\b";
        std::cin >> numbers;
        std::cout << "Enter the number of picked numbers: __\b\b";
        std::cin >> picked;

        if (!std::cin.good()) {
            std::cout << "Incorrect enter, please, try again.\n";
            if (std::cin.eof()) {
                std::cin.clear();
                std::cin.putback('\n');
                std::cin.get();
            }
            else {
                std::cin.clear();
                while (std::cin.get() != '\n');
            }
            continue;
        }
        else if (picked >= numbers || picked <= 0 || numbers <= 0) {
            std::cout << "The selectable numbers are greater than the total\n"
                         "number, or any of these are less than "
                         "or equal to zero.\n\n\a"
                         "Try again.\n";
            continue;
        }
        else
            break;
    } while (true);

    std::cout << "\nThe prize sequence is as follows:\n";
    std::vector<int> prize(lotto(numbers, picked));
    for (int number : prize)
        std::cout << number << ' ';
    
    std::cout << "\n\nTerminate.\n";


    return 0;
}


std::vector<int> lotto(int amountOfNumbers, int amountOfPicks) {
    std::vector<int> allNumbers;
    for (int i{1}; i <= amountOfNumbers; i++)
        allNumbers.push_back(i);
    
    std::random_shuffle(allNumbers.begin(), allNumbers.end());

    std::vector<int> pickedNumbers(allNumbers.begin(),
                                   allNumbers.begin() + amountOfPicks);
    std::sort(pickedNumbers.begin(), pickedNumbers.end());

    return pickedNumbers;
}