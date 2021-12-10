#pragma once

#include <cstdlib>


class Customer {
    public :
        Customer() {};

        void set(long when);
        long when() const { return arrive_; }
        int processTime() const { return processTime_; }

    private :
        long arrive_{};
        int processTime_{};
};

void Customer::set(long when) {
    processTime_ = std::rand() % 3 + 1;
    arrive_ = when;
}