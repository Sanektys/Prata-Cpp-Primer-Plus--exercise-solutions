#include <iostream>


int main() {
    setlocale(LC_ALL, "");
    std::wcout << L"Программа рассчитывает процентное соотношение\n"
                  L"населения страны к общему населению земли\n";
    std::wcout << L"Введите численность населения Земли: __________"
                                              "\b\b\b\b\b\b\b\b\b\b";
    long long earthPopulation = 0;
    std::cin >> earthPopulation;
    std::wcout << L"Введите численность населения вашей страны: __________"
                                                     "\b\b\b\b\b\b\b\b\b\b";
    long long countryPopulation = 0;
    std::cin >> countryPopulation;

    float populationRatio = float(countryPopulation) / earthPopulation * 100.0f;
    std::wcout << L"Численность населения вашей страны составляет "
               << populationRatio << L"% от населения Земли\n";


    return 0;
}
