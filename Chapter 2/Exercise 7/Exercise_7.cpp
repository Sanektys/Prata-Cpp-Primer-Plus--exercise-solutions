#include <iostream>


void showTime(int, int);

int main() {
    std::cout << "Enter the number of hours: ";
    int hour = 0;
    std::cin >> hour;
    std::cout << "Enter the number of minutes: ";
    int minute = 0;
    std::cin >> minute;

    showTime(hour, minute);


    return 0;
}

void showTime(int hour, int minute) {
    std::cout << "Time: " << hour << ':' << minute << std::endl;
}