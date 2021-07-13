#include "time.h"


Time::Time() { hours_ = minutes_ = 0; }
Time::Time(int hours, int minutes) {
    hours_ = hours;
    minutes_ = minutes;
}

void Time::addMinutes(int minutes) {
    minutes_ += minutes;
    hours_ += minutes_ / 60;
    minutes_ %= 60;
}
void Time::addHours(int hours) { hours_ += hours; }

void Time::reset(int hours, int minutes) {
    hours_ = hours;
    minutes_ = minutes;
}

Time operator+(const Time& timeLeft, const Time& timeRight) {
    Time sum{};
    sum.minutes_ = timeLeft.minutes_ + timeRight.minutes_;
    sum.hours_ = timeLeft.hours_ + timeRight.hours_ + sum.minutes_ / 60;
    sum.minutes_ %= 60;

    return sum;
}
Time operator-(const Time& timeLeft, const Time& timeRight) {
    Time diff{};
    int totalLeft, totalRight;
    totalLeft = timeLeft.minutes_ + 60 * timeLeft.hours_;
    totalRight = timeRight.minutes_ + 60 * timeRight.hours_;
    diff.minutes_ = (totalLeft - totalRight) % 60;
    diff.hours_ = (totalLeft - totalRight) / 60;

    return diff;
}
Time operator*(const Time& timeLeft, double mult) {
    Time result{};
    long totalMinutes =  (timeLeft.hours_ * 60 + timeLeft.minutes_) * mult;
    result.hours_ = totalMinutes / 60;
    result.minutes_ = totalMinutes % 60;

    return result;
}

std::ostream& operator<<(std::ostream& stream, const Time& time) {
    stream << time.hours_ << " hours, " << time.minutes_ << " minutes";

    return stream;
}
