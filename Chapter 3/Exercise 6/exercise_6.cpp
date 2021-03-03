#include <iostream>


int main() {
    setlocale(LC_ALL, "");
    std::wcout << L"Программа рассчитывает расход топлива на 100км\n";
    std::wcout << L"Введите количество пройденных километров: ______"
                                                            "\b\b\b\b\b\b";
    int kilometers{ 0 };
    std::cin >> kilometers;
    std::wcout << L"Введите объём затраченного бензина: ____\b\b\b\b";
    int liters{ 0 };
    std::cin >> liters;

    float fuelConsumption = (float(liters) / kilometers) * 100.0f;
    std::wcout << L"Расход топлива на 100 километров - "
               << fuelConsumption << L" литров бензина\n";


    return 0;
}
