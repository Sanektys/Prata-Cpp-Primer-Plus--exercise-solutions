#include <iostream>
#include <array>


int main() {
    std::cout << "Enter three results of the race in seconds:\n";
    std::array<float, 3> results = {};
    std::cout << "First result: ";
    std::cin >> results[0];
    std::cout << "Second result: ";
    std::cin >> results[1];
    std::cout << "Third result: ";
    std::cin >> results.at(2);

    std::cout << "\n\aYou entered follow results:"
              << "\nFirst - " << results.at(0)
              << "\nSecond - " << results[1]
              << "\nThird - " << results.at(2) << std::endl;
    std::cout << "Average result is - "
              << (results[0] + results[1] + results[2]) / results.size()
              << std::endl;


    return 0;
}