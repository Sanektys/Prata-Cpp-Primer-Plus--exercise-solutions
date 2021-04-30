#include <iostream>
#include <iomanip>


void printString(const char* string, int commonArg = 0);

int main() {
    const char* string = "Hello World!";
    //----------------------------------------
    std::cout << std::setfill('-') << std::setw(40) << ' ' << std::endl;
    printString(string);
    printString(string);
    //----------------------------------------
    std::cout << std::setw(40) << ' ' << std::endl;
    printString(string, 1);
    //----------------------------------------
    std::cout << std::setw(40) << ' ' << std::endl;
    printString(string);
    printString(string);
    //----------------------------------------
    std::cout << std::setw(40) << ' ' << std::endl;
    printString(string, -1);
    //----------------------------------------
    std::cout << std::setw(40) << ' ' << std::endl << std::setfill(' ');
    

    return 0;
}

void printString(const char* string, int commonArg) {
    static short numberOfCall;  //zero by declaration
    using std::cout;
    using std::endl;
    if (0 == commonArg)
        cout << string << endl;
    else
        for (short i{0}; i < numberOfCall; i++)
            cout << string << endl;
    ++numberOfCall;
}
