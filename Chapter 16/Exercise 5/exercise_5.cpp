#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <string>
#include <iterator>


const int SIZE{20};
const char* const TEMPLATES[SIZE]{"Grass", "Soil", "Vehicle", "General",
                                  "Glass", "Estimate", "Enormous", 
                                  "Column", "Abandoned", "Completed"};

template <typename T>
int reduce(T[], int);

int main(void) {
    std::mt19937 random{};
    random.seed(std::chrono::system_clock::now().time_since_epoch().count());

    std::cout << "Random arrays below:\n";
    long arrayOfLongs[SIZE]{};
    std::string arrayOfStrings[SIZE]{};

    for (int i{}; i < SIZE; i++) {
        arrayOfLongs[i] = random() % 10;
        arrayOfStrings[i] = TEMPLATES[random() % 10];
    }

    std::ostream_iterator<std::string, char> stringOstream(std::cout, ", ");
    std::ostream_iterator<long, char> longOstream(std::cout, " ");
    
    std::copy(arrayOfLongs, arrayOfLongs + SIZE, longOstream);
    std::cout << '\n';
    std::copy(arrayOfStrings, arrayOfStrings + SIZE, stringOstream);
    std::cout << '\n';

    std::cout << "\nArrays after reduce() function:\n";
    const int NEW_LONG_SIZE{reduce(arrayOfLongs, SIZE)};
    std::copy(arrayOfLongs, arrayOfLongs + NEW_LONG_SIZE, longOstream);
    std::cout << '\n';
    const int NEW_STRING_SIZE{reduce(arrayOfStrings, SIZE)};
    std::copy(arrayOfStrings, arrayOfStrings + NEW_STRING_SIZE, stringOstream);
    std::cout << '\n';

    std::cout << "\nBye.\n";


    return 0;
}


template <typename T>
int reduce(T array[], int n) {
    std::sort(array, array + n);
    T* newBorder{nullptr};
    newBorder = std::unique(array, array + n);

    return newBorder - array;
}