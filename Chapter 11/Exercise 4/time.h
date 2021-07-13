#pragma once

#include <iostream>


class Time
{
    public :
        Time();
        Time(int h, int m = 0);

        void addMinutes(int m);
        void addHours(int h);
        void reset(int h = 0, int m = 0);

        //Time operator+(const Time& t) const;
        //Time operator-(const Time& t) const;
        //Time operator*(double mult) const;

        friend Time operator+(const Time&, const Time&);
        friend Time operator-(const Time&, const Time&);
        friend Time operator*(const Time& t, double mult);
        friend Time operator*(double m, const Time& t) { return t * m; }
        friend std::ostream& operator<<(std::ostream& os, const Time& t);

    private :
        int hours_;
        int minutes_;
};
