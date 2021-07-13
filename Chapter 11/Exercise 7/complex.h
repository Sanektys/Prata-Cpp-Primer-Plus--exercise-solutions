#include <iostream>


class Complex
{
    public :
        Complex() : real_(0.0), imagine_(0.0) {}
        Complex(double real, double imagine) : real_(real), imagine_(imagine) {}

        Complex operator+(const Complex& rightValue) const {
            return Complex{real_ + rightValue.real_,
                           imagine_ + rightValue.imagine_};
        }
        Complex operator-(const Complex& rightValue) const {
            return Complex{real_ - rightValue.real_,
                           imagine_ - rightValue.imagine_};
        }
        Complex operator*(const Complex& rightValue) const {
            return Complex{real_ * rightValue.real_ -
                           imagine_ * rightValue.imagine_,
                           real_ * rightValue.imagine_ +
                           rightValue.real_ * imagine_};
        }
        Complex operator*(double mult) const {
            return Complex{real_ * mult, imagine_ * mult};
        }
        friend Complex operator*(double mult, const Complex& rightValue) {
            return rightValue * mult;
        }
        Complex operator~() const { return Complex{real_, -imagine_}; }

        friend std::ostream& operator<<(std::ostream& stream,
                                        const Complex& value) {
            stream << '(' << value.real_ << ',' << value.imagine_ << "i)";

            return stream;
        }
        friend std::istream& operator>>(std::istream&, Complex&);

    private :
        double real_;
        double imagine_;
};
