#include <iostream>


const short RESULT_COUNT{10};

void setArray(int[], short);
float getAverage(const int[], short);
void showArray(const int[], short);

int main() {
    std::cout << "Enter up to ten results of golf game"
              << "and program will calculate the average result.\n";
    int results[RESULT_COUNT]{};
    setArray(results, RESULT_COUNT);
    showArray(results, RESULT_COUNT);


    return 0;
}

void setArray(int* array, short size) {
    std::cout << "For terminate enter 'q'\n";
    for (short i = 0; i < size; i++) {
        std::cout << "Result #" << i + 1 << ": ";
        if (!(std::cin >> *(array + i))) {
            *(array + i) = -1;
            break;
        }
    }
}

float getAverage(const int arr[], short size) {
    if (0 > *arr) {
        std::cout << "Array is empty... ";
        return 0.0f;
    }
    float sum{0.0f};
    short realSize{0};
    for (short i = 0; i < size; ++i) {
        if (0 > arr[i])
            break;
        sum += arr[i];
        ++realSize;
    }

    return sum / realSize;
}

void showArray(const int arr[], short size) {
    std::cout << std::endl;
    for (short i = 0; i < size; i++) {
        if (arr[i] < 0)
            break;
        std::cout << "Result #" << i + 1 << "--" << arr[i] << ", ";
    }
    std::cout << "\nAverage result - " << getAverage(arr, size) << std::endl;
}
