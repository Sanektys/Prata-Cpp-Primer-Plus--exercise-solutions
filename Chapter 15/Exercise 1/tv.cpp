#include <iostream>

#include "tv.h"


///////////////////////////////////////////////////////////////////////////////
// class Remote

void Remote::showInteractiveState() const {
    std::cout << "Interactive mode is " << (isInteractive_ ? "on" : "off")
              << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// class Tv

void Tv::switchRemoteInteractive(Remote& r) const {
    if (isOn())
        r.isInteractive_ = r.isInteractive_ ? false : true;
}

bool Tv::volumeUp() {
    if (volume_ < MAX_VALUE) {
        volume_++;
        return true;
    }
    else
        return false;
}

bool Tv::volumeDown() {
    if (volume_ > MIN_VALUE) {
        volume_--;
        return true;
    }
    else
        return false;
}

void Tv::channelUp() {
    if (channel_ < maxChannel_)
        channel_++;
    else
        channel_ = 1;
}

void Tv::channelDown() {
    if (channel_ > 1)
        channel_--;
    else
        channel_ = maxChannel_;
}

void Tv::settings() const {
    using std::cout;
    using std::endl;

    cout << "TV is " << (state_ == OFF ? "Off" : "On") << endl;

    if (state_ == ON)
        cout << "Volume setting = " << volume_ << endl
             << "Channel setting = " << channel_ << endl
             << "Mode = " << (mode_ == ANTENNA ? "antenna" : "cable") << endl
             << "Input = " << (input_ == TV ? "TV" : "DVD") << endl;
}