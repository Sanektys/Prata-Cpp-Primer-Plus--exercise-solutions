#include <iostream>
#include <fstream>


int main() {
    std::cout << "Enter file name and the program will calculate\namount "
                 "of characters in this file.\n";
    char filename[32]{};
    std::cout << "File name: ";
    std::cin >> filename;
    std::ifstream inputFile;
    inputFile.open(filename);
    int charCount = 0;
    if (inputFile.is_open()) {
        char dummy = '\0';
        bool isMoreOneByte = false;
        while (!inputFile.eof()) {
            dummy = inputFile.get();
            if (!isMoreOneByte && dummy < 0) {
                isMoreOneByte = true;
                continue;
            }
            else if (isMoreOneByte)
                isMoreOneByte = false;
            charCount += inputFile.gcount();
        }
        --charCount;
    }
    else {
        std::cout << "File not found!\n";
        return 1;
    }
    std::cout << charCount << " characters in the file.\n";
    inputFile.close();


    return 0;
}
