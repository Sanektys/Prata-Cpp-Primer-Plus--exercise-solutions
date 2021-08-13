#include <cstring>

#include "port.h"


Port::Port(const char* brand, const char* style, int bottles) {
    brand_ = new char[std::strlen(brand) + 1];
    std::strcpy(brand_, brand);
    std::strncpy(style_, style, 19);
    style_[19] = '\0';
    bottles_ = bottles;
}

Port::Port(const Port& copy) {
    brand_ = new char[std::strlen(copy.brand_) + 1];
    std::strcpy(brand_, copy.brand_);
    std::strcpy(style_, copy.style_);
    bottles_ = copy.bottles_;
}


void Port::show() const {
    std::cout << "Brand: " << brand_
              << "\nKind: " << style_
              << "\nBottles: " << bottles_ << std::endl;
}


Port& Port::operator=(const Port& copy) {
    if (this == &copy)
        return *this;
    delete[] brand_;
    brand_ = new char[std::strlen(copy.brand_) + 1];
    std::strcpy(brand_, copy.brand_);
    std::strcpy(style_, copy.style_);
    bottles_ = copy.bottles_;

    return *this;
}

Port& Port::operator+=(int bottles) {
    bottles_ += bottles;

    return *this;
}

Port& Port::operator-=(int bottles) {
    if (bottles_ < bottles)
        return *this;
    bottles_ -= bottles;

    return *this;
}


std::ostream& operator<<(std::ostream& output, const Port& object) {
    output << object.brand_ << ", " << object.style_ << ", "
           << object.bottles_ << ' ';

    return output;
}
