#include <iostream>
#include <cstring>


template <typename T>
T maxn(T[], int);
template <>
const char* maxn<const char*>(const char*[], int);

int main() {
    int intArr[6]{12, 23, 18, 16, 11, 24};
    std::cout << " --Integer array:  ";
    for (int i = 0; i < 6; i++)
        std::cout << intArr[i] << ", ";
    std::cout << "\b\b.\n"
              << " --Max element - " << maxn(intArr, 6)
              << std::endl << std::endl;

    double doubleArr[4]{44.86, 42.18, 44.87, 24.5};
    std::cout << " --Double array:  ";
    for (int i = 0; i < 4; i++)
        std::cout << doubleArr[i] << ", ";
    std::cout << "\b\b.\n"
              << " --Max element - " << maxn(doubleArr, 4)
              << std::endl << std::endl;

    const char* charPtrArr[5]{
                              "You're breathtaking!!!",
                              "Have a nice day!",
                              "I wish to become a programmer",
                              "I want to become a programmer",
                              "Shahidzhanyan - blind typing"
                             };
    std::cout << " --Pointer to char array:\n";
    for (int i = 0; i < 5; i++)
        std::cout << "        " << *(charPtrArr + i) << std::endl;
    std::cout << " --The most length string is:\n        "
              << maxn(charPtrArr, 5) << std::endl << std::endl;


    return 0;
}

template <typename T>
T maxn(T array[], int size) {
    T max = array[0];
    for (int i = 1; i < size; i++)
        if (max < array[i])
            max = array[i];

    return max;
}

template <>
const char* maxn<const char*>(const char* arrayStrings[], int amount) {
    int maxLength = strlen(*arrayStrings);
    int index {0};
    for (int i = 1; i < amount; i++) {
        int currentLength = strlen(arrayStrings[i]);
        if (maxLength < currentLength) {
            maxLength = currentLength;
            index = i;
        }
    }

    return arrayStrings[index];
}
