#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>


const int SIZE{20};

int reduce(long[], int);

int main(void) {
    std::mt19937 random{};
    random.seed(std::chrono::system_clock::now().time_since_epoch().count());

    std::cout << "Random array below:\n";
    long array[SIZE]{};
    for (long& element : array) {
        element = random() % 10;
        std::cout << element << ' ';
    }
    std::cout << '\n';

    std::cout << "\nArray after reduce() function:\n";
    const int NEW_SIZE{reduce(array, SIZE)};
    for (int i{}; i < NEW_SIZE; i++)
        std::cout << array[i] << ' ';
    std::cout << '\n';

    std::cout << "\nBye.\n";


    return 0;
}


int reduce(long array[], int n) {
    std::sort(array, array + n);
    long* newBorder{nullptr};
    newBorder = std::unique(array, array + n);

    return newBorder - array;
}