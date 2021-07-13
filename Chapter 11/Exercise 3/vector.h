#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>


namespace VECTOR {
    class Vector
    {
        public :
            enum Mode { RECTANGLE, POLAR };

        public :
            Vector();
            Vector(double, double, Mode = RECTANGLE);
            ~Vector();

            void reset(double, double, Mode = RECTANGLE);

            double xValue() const { return x_; }
            double yValue() const { return y_; }
            double magnitudeValue() const { return getMagnitude(); }
            double angleValue() const { return getAngle(); }

            void polarMode() { mode_ = POLAR; }
            void rectangleMode() { mode_ = RECTANGLE; }

            Vector operator+(const Vector&) const;
            Vector operator-(const Vector&) const;
            Vector operator-() const;
            Vector operator*(double) const;
            friend Vector operator*(double, const Vector&);
            friend std::ostream& operator<<(std::ostream&, const Vector&);

        private :
            double getMagnitude() const;
            double getAngle() const;
            void setX(double, double);
            void setY(double, double);

        private :
            double x_;
            double y_;

            Mode mode_;
    };
} // namespace VECTOR

#endif
