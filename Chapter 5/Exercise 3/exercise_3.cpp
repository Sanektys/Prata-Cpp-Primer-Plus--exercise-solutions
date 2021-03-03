#include <iostream>


int main() {
     setlocale(LC_ALL, "");

    std::wcout << L"Программа суммирует поочерёдно вводимые числа\n";
    std::wcout << L"Начните вводить по одному числу, "
                  L"для остановки введите ноль\n";
    int number{};
    long long sum{};
    do {
        std::wcout << L"Текущая сумма значений: " << sum << std::endl;
        std::wcout << L"Введите следующее число: ";
        std::cin >> number;
        sum += number;
    } while (number != 0);


    return 0;
}
