#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>


class BankAccount {
    public :
        BankAccount(const std::wstring& = L"пусто",
                    const std::wstring& = L"пусто",
                    double = 0.0);

        void showAccount(void) const;
        void deposit(double);
        void withdraw(double);

    private :
        std::wstring fullname_;
        std::wstring accountNumber_;
        double balance_;
};

#endif
