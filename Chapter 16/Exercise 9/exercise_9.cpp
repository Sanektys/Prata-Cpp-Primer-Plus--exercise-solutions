#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>


const int SIZE{100000000};

int main() {
    std::vector<int> vi0(SIZE);
    for (auto& number : vi0)
        number = rand() % 1000;

    std::vector<int> vectorInt(vi0.begin(), vi0.end());
    std::list<int> listInt(vi0.begin(), vi0.end());

    std::cout << "Time, required to sort an vector of "
              << SIZE << " elements: ";
    std::clock_t start{std::clock()};
    std::sort(vectorInt.begin(), vectorInt.end());
    std::clock_t end{std::clock()};
    std::cout << double(end - start) / CLOCKS_PER_SEC
              << " seconds.\n";
    
    std::cout << "Time, required to sort an list of "
              << SIZE << " elements: ";
    start = std::clock();
    listInt.sort();
    end = std::clock();
    std::cout << double(end - start) / CLOCKS_PER_SEC
              << " seconds.\n";

    std::copy(vi0.begin(), vi0.end(), listInt.begin());
    std::cout << "Time, required to copy list into a vector, "
              << "sort the vector,\nand copy the final vector into the list: ";
    start = std::clock();
    std::copy(listInt.begin(), listInt.end(), vectorInt.begin());
    std::sort(vectorInt.begin(), vectorInt.end());
    std::copy(vectorInt.begin(), vectorInt.end(), listInt.begin());
    end = std::clock();
    std::cout << double(end - start) / CLOCKS_PER_SEC
              << " seconds.\n";

    std::cout << "\nTerminate.\n";


    return 0;
}