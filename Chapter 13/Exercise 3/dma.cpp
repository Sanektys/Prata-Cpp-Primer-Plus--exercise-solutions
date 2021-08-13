#include <cstring>

#include "dma.h"


////////////////////////////////////////////////////////////
// class AbstractDma
AbstractDma::AbstractDma(const char* label, int rating) {
    label_ = new char[std::strlen(label) + 1];
    std::strcpy(label_, label);
    rating_ = rating;
}

AbstractDma::AbstractDma(const AbstractDma& copy) {
    label_ = new char[std::strlen(copy.label_) + 1];
    std::strcpy(label_, copy.label_);
    rating_ = copy.rating_;
}

AbstractDma::~AbstractDma() { delete[] label_; }


AbstractDma& AbstractDma::operator=(const AbstractDma& copy) {
    if (this == &copy)
        return *this;
    delete[] label_;
    label_ = new char[std::strlen(copy.label_) + 1];
    std::strcpy(label_, copy.label_);
    rating_ = copy.rating_;

    return *this;
}


void AbstractDma::view() const {
    std::cout << "Label: " << label_
              << "\nRating: " << rating_ << std::endl;
}


////////////////////////////////////////////////////////////
// class BaseDma
BaseDma::BaseDma(const char* label, int rating) : AbstractDma(label, rating) {}


void BaseDma::view() const { AbstractDma::view(); }


std::ostream& operator<<(std::ostream& stream, const BaseDma& object) {
    dynamic_cast<const AbstractDma&>(object).view();

    return stream;
}


////////////////////////////////////////////////////////////
// class LackDma
LackDma::LackDma(const char* color, const char* label, int rating)
                : AbstractDma(label, rating) {
    std::strncpy(color_, color, COLOR_LENTH - 1);
    color_[COLOR_LENTH - 1] = '\0';
}


void LackDma::view() const {
    AbstractDma::view();
    std::cout << "Color: " << color_ << std::endl;
}


std::ostream& operator<<(std::ostream& stream, const LackDma& object) {
    dynamic_cast<const AbstractDma&>(object).view();
    stream << "Color: " << object.color_ << std::endl;

    return stream;
}


////////////////////////////////////////////////////////////
// class HasDma
HasDma::HasDma(const char* style, const char* label, int rating)
              : AbstractDma(label, rating) {
    style_ = new char[std::strlen(style) + 1];
    std::strcpy(style_, style);
}

HasDma::HasDma(const HasDma& copy) : AbstractDma(copy) {
    style_ = new char[std::strlen(copy.style_) + 1];
    std::strcpy(style_, copy.style_);
}

HasDma::~HasDma() { delete[] style_; }


HasDma& HasDma::operator=(const HasDma& copy) {
    if (this == &copy)
        return *this;
    AbstractDma::operator=(copy);
    delete[] style_;
    style_ = new char[std::strlen(copy.style_) + 1];
    std::strcpy(style_, copy.style_);

    return *this;
}


void HasDma::view() const {
    AbstractDma::view();
    std::cout << "Style: " << style_ << std::endl;
}


std::ostream& operator<<(std::ostream& stream, const HasDma& object) {
    dynamic_cast<const AbstractDma&>(object).view();
    stream << "Style: " << object.style_ << std::endl;

    return stream;
}
