#include <iostream>


class Move
{
    public :
        Move(double x = 0.0, double y = 0.0) : x_(x), y_(y) {}

        void showMove() const {
            std::cout << "X: " << this->x_ << std::endl;
            std::cout << "Y: " << this->y_ << std::endl;
        };
        Move add(const Move& addict) const {
            double x{x_ + addict.x_}, y{y_ + addict.y_};

            return Move(x, y);
        }
        void reset(double x = 0.0, double y = 0.0) {
            x_ = x;
            y_ = y;
        }

    private :
        double x_;
        double y_;
};
