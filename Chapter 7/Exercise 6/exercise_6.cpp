#include <iostream>


int fillArray(double[], int);
void showArray(const double[], int);
void reverseArray(double[], int);

int main() {
    std::cout << "Enter size of array: ";
    int size{};
    while (!(std::cin >> size).good() || 0 >= size) {
        if (!std::cin) {
            std::cin.clear();
            while (std::cin.get() != '\n');
        }
        std::cout << "Incorrect entered size, try again: ";
    }
    double array[size];
    size = fillArray(array, size);
    reverseArray(array, size);
    showArray(array, size);


    return 0;
}

int fillArray(double array[], int size) {
    std::cout << "Fill array by entering numbers:\n";
    int count = 0;
    for (int i = 0; i < size; i++) {
        std::cout << "Element #" << i + 1 << " = ";
        if (!(std::cin >> array[i]).good())
            break;
        count++;
    }

    return count;
}

void showArray(const double array[], int size) {
    if (0 == size)
        std::cout << "\nArray is empty.\n";

    std::cout << "\nAll element of array below:\n";
    for (int i = 0; i < size; ++i)
        std::cout << "Element [" << i << "] = " << array[i] << std::endl;
    std::cout << std::endl;
}

void reverseArray(double array[], int size) {
    double temp{};
    for (int i = 1; i < size / 2; i++) {
        temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}
