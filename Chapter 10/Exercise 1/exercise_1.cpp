#include <iostream>

#include "bankAccount.h"


int main() {
    BankAccount accounts[]{{L"Александр Чепига", L"892748", 1200000.0},
                           {L"Пётр Дегтярёв",    L"892912", 2828146.88},
                           {L"Максим Воложилов", L"901822", 12845000.0}};
    std::setlocale(LC_ALL, "");
    std::wcout << L"Инициализированный список счетов:\n";
    for (int i = 0; i < 3; i++) {
        accounts[i].showAccount();
        std::wcout << std::endl;
    }
    std::wcout << L"Добавление к счёту Максима 1800 у.е.\n";
    accounts[2].deposit(1800.0);
    std::wcout << L"Снятие средств со счёта Петра(3'000'000 y.e.)\n";
    accounts[1].withdraw(3000000.0);
    std::wcout << L"Повторное снятие средств со счёта Петра(2'500'000 y.e.)\n";
    accounts[1].withdraw(2500000.0);
    std::wcout << L"\nОбновлённый список счетов:\n";
    for (int i = 0; i < 3; i++) {
        accounts[i].showAccount();
        std::wcout << std::endl;
    }
    std::wcout << L"Завершение...\n";


    return 0;
}
