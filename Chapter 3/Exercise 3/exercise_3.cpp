#include <iostream>


int main() {
    const int SECONDS_PER_MINUTE = 60;
    const int MINUTES_PER_DEGREE = 60;

    std::cout << "Enter a latitude in degrees, minutes, and seconds:\n";
    std::cout << "First, enter the degrees: ___\b\b\b";
    float degrees = 0.0f;
    std::cin >> degrees;
    degrees = int(degrees);
    std::cout << "Next, enter the minutes of arc: __\b\b";
    int minutes = 0;
    std::cin >> minutes;
    std::cout << "Finally, enter the seconds of arc: __\b\b";
    int seconds = 0;
    std::cin >> seconds;

    std::cout << degrees << " degrees, ";
    degrees = degrees + (float(minutes) / MINUTES_PER_DEGREE)
                      + (float(seconds) / (SECONDS_PER_MINUTE * MINUTES_PER_DEGREE));
    std::cout << minutes << " minutes, " << seconds << " seconds = "
              << degrees << " degrees\n";


    return 0;
}