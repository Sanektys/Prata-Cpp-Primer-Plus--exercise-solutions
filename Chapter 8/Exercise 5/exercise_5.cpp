#include <iostream>


template <typename T>
T max5(T[]);

int main() {
    std::cout << "Enter five integer elements:\n";
    int intArr[5]{};
    for (int i = 0; i < 5; i++) {
        std::cout << "- integer number #" << i + 1 << ": ";
        if (!(std::cin >> intArr[i])) {
            std::cout << "Error on input\n";
            return 1;
        }
    }
    std::cout << "Max input integer value is " << max5(intArr) << std::endl
              << std::endl;

    std::cout << "Enter five double elements:\n";
    double doubleArr[5]{};
    for (int i = 0; i < 5; i++) {
        std::cout << "- double number #" << i + 1 << ": ";
        if (!(std::cin >> doubleArr[i])) {
            std::cout << "Error on input\n";
            return 1;
        }
    }
    std::cout << "Max input double value is " << max5(doubleArr) << std::endl;


    return 0;
}

template <typename T>
T max5(T array[]) {
    T max = array[0];
    for (int i = 1; i < 5; i++)
        max = max < array[i] ? array[i] : max;

    return max;
}
