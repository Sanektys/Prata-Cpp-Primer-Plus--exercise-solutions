#include <iostream>
#include <cstring>

#include "vintagePort.h"


VintagePort::VintagePort() : Port() {
    nickname_ = nullptr;
    year_ = 0;
}

VintagePort::VintagePort(const char* brand, int bottles, const char* nick,
                         int year) : Port(brand, "vintage", bottles) {
    nickname_ = new char[std::strlen(nick) + 1];
    std::strcpy(nickname_, nick);
    year_ = year;
}

VintagePort::VintagePort(const VintagePort& copy) : Port(copy) {
    nickname_ = new char[std::strlen(copy.nickname_) + 1];
    std::strcpy(nickname_, copy.nickname_);
    year_ = copy.year_;
}


void VintagePort::show() const {
    Port::show();
    std::cout << "Nickname: " << nickname_
              << "\nYear: " << year_ << std::endl;
}


VintagePort& VintagePort::operator=(const VintagePort& copy) {
    if (this == &copy)
        return *this;
    Port::operator=(copy);
    delete[] nickname_;
    nickname_ = new char[std::strlen(copy.nickname_) + 1];
    std::strcpy(nickname_, copy.nickname_);
    year_ = copy.year_;

    return *this;
}


std::ostream& operator<<(std::ostream& output, const VintagePort& object) {
    output << (const Port&)object << "\b, " << object.nickname_ << ", "
           << object.year_ << ' ';

    return output;
}
