#include <iostream>


int main() {
    setlocale(LC_ALL, "");

    const float MILES_IN_KILOMETER = 0.621371f;
    const float LITERS_IN_GALLON = 3.78541f;

    std::wcout << L"Программа рассчитывает расход топлива\n"
                   "по американской системе (миль на галлон)\n\n";
    std::wcout << L"Введите количество пройденных километров: ______"
                                                            "\b\b\b\b\b\b";
    float kilometers{ 0.0f };
    std::cin >> kilometers;
    std::wcout << L"Введите объём затраченного бензина в литрах: ____\b\b\b\b";
    float liters{ 0.0f };
    std::cin >> liters;

    float miles = MILES_IN_KILOMETER * kilometers;
    float gallons = liters / LITERS_IN_GALLON;
    float fuelConsumption = miles / gallons;
    std::wcout << "Number of miles per gallon - "
               << fuelConsumption << std::endl;


    return 0;
}
