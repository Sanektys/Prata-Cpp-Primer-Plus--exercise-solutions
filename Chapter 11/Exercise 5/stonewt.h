#pragma once

#include <iostream>


class Stonewt
{
    public :
        Stonewt();
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        ~Stonewt();

        //void showLbs() const;
        //void showStn() const;

        void inStone() { type_ = STONE; }
        void inIntPounds() { type_ = INTEGER_POUNDS; }
        void inFloatPounds() { type_ = FLOAT_POUNDS; }

        friend Stonewt operator+(const Stonewt&, const Stonewt&);
        friend Stonewt operator-(const Stonewt&, const Stonewt&);
        friend Stonewt operator*(const Stonewt&, const Stonewt&);

    private :
        friend std::ostream& operator<<(std::ostream&, const Stonewt&);

    private :
        enum { LBS_PER_STN = 14 };
        enum { STONE, INTEGER_POUNDS, FLOAT_POUNDS } type_;
        int stone_;
        double pdsLeft_;
        double pounds_;
};
