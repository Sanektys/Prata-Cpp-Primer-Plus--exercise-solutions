#include <cmath>

#include "vector.h"


namespace VECTOR {
    const double RAD_TO_DEG = 45.0 / std::atan(1.0);


    double Vector::getMagnitude() const {
        return double(std::sqrt(x_ * x_ + y_ * y_));
    }
    double Vector::getAngle() const {
        double angle{};
        if (0.0 == x_ && 0.0 == y_)
            angle = 0.0;
        else
            angle = std::atan2(y_, x_);

        return angle;
    }

    void Vector::setX(double magnitude, double angle) {
        x_ = magnitude * std::cos(angle / RAD_TO_DEG);
    }
    void Vector::setY(double magnitude, double angle) {
        y_ = magnitude * std::sin(angle / RAD_TO_DEG);
    }

    Vector::Vector() {
        x_ = y_ = 0.0;
        mode_ = RECTANGLE;
    }
    Vector::Vector(double firstValue, double secondValue, Mode form) {
        reset(firstValue, secondValue, form);
    }
    Vector::~Vector() {}

    void Vector::reset(double firstValue, double secondValue, Mode form) {
        mode_ = form;
        if (RECTANGLE == form) {
            x_ = firstValue;
            y_ = secondValue;
        } else if (POLAR == form) {
            setX(firstValue, secondValue);
            setY(firstValue, secondValue);
        } else {
            std::cout << "Incorrect 3rd argument to Vector() -- "
                      << "vector set to 0\n";
            x_ = y_ = 0.0;
            mode_ = RECTANGLE;
        }
    }

    Vector Vector::operator+(const Vector& vector) const {
        return Vector(x_ + vector.x_, y_ + vector.y_);
    }
    Vector Vector::operator-(const Vector& vector) const {
        return Vector(x_ - vector.x_, y_ - vector.y_);
    }
    Vector Vector::operator-() const {
        return Vector(-x_, -y_);
    }
    Vector Vector::operator*(double mult) const {
        return Vector(x_ * mult, y_ * mult);
    }
} // namespace VECTOR

VECTOR::Vector operator*(double mult, const VECTOR::Vector& vector) {
    return vector * mult;
}

namespace VECTOR {
    std::ostream& operator<<(std::ostream& stream, const Vector& vector) {
        if (Vector::RECTANGLE == vector.mode_)
            stream << "(x.y) = (" << vector.x_ << ", " << vector.y_ << ")";
        else if (Vector::POLAR == vector.mode_) {
            stream << "(m,a) = (" << vector.getMagnitude() << ", "
                   << vector.getAngle() * RAD_TO_DEG << ")";
        } else
            stream << "Vector object mode is invalid\a\n";

        return stream;
    }
}
