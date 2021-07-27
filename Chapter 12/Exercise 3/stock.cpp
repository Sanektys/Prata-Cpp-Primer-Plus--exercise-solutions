#include <iostream>
#include <cstring>

#include "stock.h"


Stock::Stock() {
    char defaultName[]{"no name"};
    company_ = new char[std::strlen(defaultName) + 1];
    std::strcpy(company_, defaultName);
    shares_ = 0;
    shareValue_ = 0.0;
    totalValue_ = 0.0;
}

Stock::Stock(const std::string& company, long number, double price) {
    company_ = new char[company.length() + 1];
    std::strcpy(company_, company.c_str());
    if (number < 0) {
        std::cout << "Number of shares can't be negative; "
                  << company_ << " shares set to 0.\n";
        shares_ = 0;
    }
    else
        shares_ = number;
    shareValue_ = price;
    setTotal();
}

Stock::~Stock() {
    delete[] company_;
}

void Stock::buy(long number, double price) {
    if (number < 0)
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    else {
        shares_ += number;
        shareValue_ = price;
        setTotal();
    }
}

void Stock::sell(long number, double price) {
    if (number < 0)
        std::cout << "Number of shares sold can't be negative. "
                  << "Transaction is aborted.\n";
    else if (number > shares_)
        std::cout << "You can't sell more than you have! "
                  << "Transaction is abored.\n";
    else {
        shares_ -= number;
        shareValue_ = price;
        setTotal();
    }
}

void Stock::update(double price) {
    shareValue_ = price;
    setTotal();
}

void Stock::show() const {
    std::cout << *this;
}


std::ostream& operator<<(std::ostream& output, const Stock& stock) {
    std::ios_base::fmtflags orig =
        output.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::streamsize prec = std::cout.precision(3);
    output << "Company: " << stock.company_
           << " Shares: " << stock.shares_ << '\n'
           << " Share Price: $" << stock.shareValue_;
    output.precision(2);
    output << " Total Worth: $" << stock.totalValue_ << '\n';
    output.setf(orig, std::ios_base::floatfield);
    output.precision(prec);

    return output;
}


const Stock& Stock::topValue(const Stock& stock) const {
    if (stock.totalValue_ > totalValue_)
        return stock;
    else
        return *this;
}

