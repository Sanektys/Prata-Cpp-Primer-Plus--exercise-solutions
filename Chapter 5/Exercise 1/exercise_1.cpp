#include <iostream>


int main() {
    setlocale(LC_ALL, "");

    std::wcout << L"Введите два целых числа(от меньшего к большему)\n"
                  L"и программа вычислит сумму всех чисел, "
                  L"лежащих в данном диапазоне.\n";
    std::wcout << L"Нижнее число: ";
    int lowNumber{};
    std::cin >> lowNumber;
    std::wcout << L"Верхнее число: ";
    int highNumber{};
    std::cin >> highNumber;

    long long result{};
    for (int i = lowNumber; i <= highNumber; ++i)
        result += i;
    std::wcout << L"Сумма всех чисел в диапазоне: " << result << std::endl;


    return 0;
}
