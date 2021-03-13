#include <iostream>
#include <fstream>


struct Patron
{
    std::string name;
    double contribution;
};

int main() {
    std::cout << "The program compiles a list of patrons.\n"
                 "The program will separately identify people "
                 "who have donated $10,000 or more.\n";
    char variant{'\0'};
    do {
      std::cout << R"(Enter "w" to type the data manually or)" << std::endl
                << R"(enter "f" to read data from the file: )";
      std::cin >> variant;
    } while (variant != 'w' && variant != 'f' &&
             variant != 'W' && variant != 'F');

    Patron* patron{nullptr};
    short patronsNumber{0};
    if (variant == 'w' || variant == 'W') {
        std::cout << "\nEnter the number of patrons and then "
                     "each patron's donation data.\n";
        std::cout << "Enter number of patrons: ___\b\b\b";;
        std::cin >> patronsNumber;
        if (patronsNumber > 0)
            patron = new Patron[patronsNumber];
        else
            return 0;

        for (short i = 0 ; i < patronsNumber; i++) {
            std::cout << "Enter patron's name: ";
            std::cin >> patron[i].name;
            std::cout << "Enter patron's contribution: $______\b\b\b\b\b\b";
            std::cin >> patron[i].contribution;
        }
    }
    else if (variant == 'f' || variant == 'F') {
        std::cout << "\nEnter name of the file whose data will be read: ________"
                                                              "\b\b\b\b\b\b\b\b";
        char fileName[32]{};
        std::cin >> fileName;
        std::ifstream inputFile(fileName);
        if (inputFile.is_open()) {
            inputFile >> patronsNumber;
            if (inputFile.fail()) {
                std::cout << "Incorrect data!\n";
                return 1;
            }
            patron = new Patron[patronsNumber];
            for (short i = 0; i < patronsNumber; i++) {
                std::string temp{};
                char nextChar{'\0'};
                while (((nextChar = inputFile.peek()) == ' ' ||
                       nextChar == '\n') && nextChar != EOF)
                       inputFile.get();
                while ((nextChar = inputFile.peek()) != '.' &&
                        nextChar != ',' &&
                       !(nextChar >= '0' && nextChar <= '9' )) {
                    if (EOF == nextChar)
                        break;
                    inputFile >> temp;
                    patron[i].name += temp + " ";
                    inputFile.get();
                }
                if (patron[i].name.size() == 0)
                    patron[i].name = "Anonymous";
                else
                    patron[i].name.pop_back();

                inputFile >> patron[i].contribution;
                if (inputFile.eof()) {
                    std::cout << "\n\aUnexpected end of file\n";
                    patronsNumber = i;
                    break;
                }
                if (inputFile.fail()) {
                    std::cout << "Incorrect data!\n";
                    delete[] patron;
                    patron = nullptr;
                    return 1;
                }
            }
        }
        else {
            std::cout << "Unable to open the file.\n";
            return 1;
        }
    }
    else
        return 1;

    std::cout << "\nGrand Patrons\n";
    bool isNone = true;
    for (int i = 0; i < patronsNumber; i++) {
        if (10000.0 <= patron[i].contribution) {
            std::cout << patron[i].name << " - $" << patron[i].contribution
                      << std::endl;
            isNone = false;
        }
    }
    if (isNone)
        std::cout << "none\n";
    std::cout << "\nPatrons\n";
    isNone = true;
    for (int i = 0; i < patronsNumber; i++) {
        if (10000.0 > patron[i].contribution) {
            std::cout << patron[i].name << " - $" << patron[i].contribution
                      << std::endl;
            isNone = false;
        }
    }
    if (isNone)
        std::cout << "none\n";
    if (nullptr != patron) {
        delete[] patron;
        patron = nullptr;
    }


    return 0;
}
