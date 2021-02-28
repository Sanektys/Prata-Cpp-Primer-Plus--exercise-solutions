#include <iostream>


const int INCHES_PER_FEET = 12;
const float METERS_PER_INCHES = 0.0254F;
const float KILOGRAMS_PER_POUNDS = 2.20462F;

int main() {
    std::cout << "Program calculates the body mass index.\n";
    std::cout << "Enter your feet ___\b\b\b";
    int feet = 0;
    std::cin >> feet;
    std::cout << "\tand inches _____\b\b\b\b\b";
    int inches = 0;
    std::cin >> inches;
    std::cout << "Also enter your weight in pounds ____\b\b\b\b";
    int pounds = 0;
    std::cin >> pounds;

    inches = inches + feet * INCHES_PER_FEET;
    float meters = inches * METERS_PER_INCHES;
    float kilograms = pounds / KILOGRAMS_PER_POUNDS;

    float bmi = kilograms / (meters * meters);
    std::cout << "Your body mass index equals " << bmi << std::endl;


    return 0;
}