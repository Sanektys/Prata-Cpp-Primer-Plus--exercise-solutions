#include <iostream>


double harmonicMean(float, float);

int main(void) {
    setlocale(LC_ALL, "");

    std::wcout << L"Вводите по два числа, и программа рассчитает\n"
                  L"их среднее гармоническое значение:\n";
    float firstNumber{};
    float secondNumber{};
    do {
        std::wcout << L"Два числа через пробел (для выхода введите ноль): ";
        if (!(std::cin >> firstNumber) || 0.0f == firstNumber)
            break;
        if (!(std::cin >> secondNumber) || 0.0f == secondNumber)
            break;
        std::wcout << L"Среднее гармоническое равно "
                   << harmonicMean(firstNumber, secondNumber) << std::endl;
    } while (std::cin.good());
    std::wcout << L"Завершение...\n";


    return 0;
}

double harmonicMean(float x, float y) {
    return 2.0 * x * y / (x + y);
}
