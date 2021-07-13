#include "stonewt.h"


Stonewt::Stonewt(double lbs) {
    stone_ = int(lbs) / LBS_PER_STN;
    pdsLeft_ = int(lbs) % LBS_PER_STN + lbs - int(lbs);
    pounds_ = lbs;
    type_ = FLOAT_POUNDS;
}
Stonewt::Stonewt(int stone, double lbs) {
    stone_ = stone;
    pdsLeft_ = lbs;
    pounds_ = stone * LBS_PER_STN + lbs;
    type_ = STONE;
}
Stonewt::Stonewt() {
    stone_ = pdsLeft_ = pounds_ = 0;
    type_ = INTEGER_POUNDS;
}

Stonewt::~Stonewt() {}

bool Stonewt::operator<(const Stonewt& rightValue) const {
    return (pounds_ < rightValue.pounds_ + 1E-15)
        && (pounds_ < rightValue.pounds_ - 1E-15) ? true : false;
}
bool Stonewt::operator>(const Stonewt& rightValue) const {
    return !(*this < rightValue);
}
bool Stonewt::operator<=(const Stonewt& rightValue) const {
    return *this < rightValue && !(*this > rightValue);
}
bool Stonewt::operator>=(const Stonewt& rightValue) const {
    return *this > rightValue && !(*this < rightValue);
}
bool Stonewt::operator==(const Stonewt& rightValue) const {
    return !(*this < rightValue) && !(*this > rightValue);
}
bool Stonewt::operator!=(const Stonewt& rightValue) const {
    return *this < rightValue || *this > rightValue;
}

Stonewt operator+(const Stonewt& leftValue, const Stonewt& rightValue) {
    return Stonewt(leftValue.pounds_ + rightValue.pounds_);
}
Stonewt operator-(const Stonewt& leftValue, const Stonewt& rightValue) {
    return Stonewt(leftValue.pounds_ - rightValue.pounds_);
}
Stonewt operator*(const Stonewt& leftValue, const Stonewt& rightValue) {
    return Stonewt(leftValue.pounds_ * rightValue.pounds_);
}

std::ostream& operator<<(std::ostream& stream, const Stonewt& value) {
    switch (value.type_) {
        case Stonewt::STONE :
            stream << value.stone_ << " stone, "
                   << value.pdsLeft_ << " pounds";
            break;
        case Stonewt::INTEGER_POUNDS :
            stream << int(value.pounds_) << " pounds";
            break;
        case Stonewt::FLOAT_POUNDS :
            stream << value.pounds_ << " pounds";
            break;
        default :
            stream << "Incorrect type of Stonewt value.";
    }

    return stream;
}
