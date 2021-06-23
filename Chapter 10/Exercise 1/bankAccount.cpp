#include <iostream>

#include "bankAccount.h"


BankAccount::BankAccount(const std::wstring& fullname,
                         const std::wstring& accNumb,
                         double balance) {
    balance_ = balance;
    fullname_ = fullname;
    accountNumber_ = accNumb;
}

void BankAccount::showAccount() const {
    std::ios_base::fmtflags previousFlags(std::wcout.setf(
                                                     std::ios_base::fixed,
                                                     std::ios_base::floatfield));
    std::streamsize previousPrecision(std::wcout.precision(2));
    std::wcout << L"---== Счёт под номером " << accountNumber_ << L" ==---\n";
    std::wcout << L"-> Владелец счёта:    " << fullname_ << std::endl;
    std::wcout << L"-> Средства на счету: " << balance_ << std::endl;
    std::wcout << L"---================================---\n";
    std::wcout.setf(previousFlags, std::ios_base::floatfield);
    std::wcout.precision(previousPrecision);
}

void BankAccount::deposit(double sum) {
    balance_ += sum;
}

void BankAccount::withdraw(double sum) {
    if (balance_ <= 0.0 || balance_ < sum) {
        std::wcout << L"Недостаточно денег для снятия средств!\n";
    }
    else
        balance_ -= sum;
}
