#include <iostream>
#include <cstring>

#include "classic.h"

////////////////////////////////////////////////////////////
// class Cd
Cd::Cd(const char *perf, const char *label, int select, double playtime)
       : performance_(), label_() {
    performance_ = new char[std::strlen(perf) + 1];
    std::strcpy(performance_, perf);
    label_ = new char[std::strlen(label) + 1];
    std::strcpy(label_, label);
    selections_ = select;
    playtime_ = playtime;
}

Cd::Cd(const Cd& copy) : performance_(), label_() {
    performance_ = new char[std::strlen(copy.performance_) + 1];
    std::strcpy(performance_, copy.performance_);
    label_ = new char[std::strlen(copy.label_) + 1];
    std::strcpy(label_, copy.label_);
    selections_ = copy.selections_;
    playtime_ = copy.playtime_;
}

Cd::Cd() {
    performance_ = label_ = nullptr;
    playtime_ = selections_ = 0;
}

Cd::~Cd() {
    delete[] performance_;
    delete[] label_;
}


void Cd::report() const {
    std::cout << "Performance: " << performance_
              << "\nLabel:       " << label_
              << "\nSelections:  " << selections_
              << "\nPlaytime:    " << playtime_ << std::endl;
}


const Cd& Cd::operator=(const Cd& copy) {
    if (this == &copy)
        return *this;
    delete[] performance_;
    performance_ = new char[std::strlen(copy.performance_) + 1];
    std::strcpy(performance_, copy.performance_);
    delete[] label_;
    label_ = new char[std::strlen(copy.label_) + 1];
    std::strcpy(label_, copy.label_);
    selections_ = copy.selections_;
    playtime_ = copy.playtime_;

    return *this;
}

////////////////////////////////////////////////////////////
// class Classic
Classic::Classic(const char* mainComp, const char* perf, const char* label,
                 int select, double playtime)
                 : Cd(perf, label, select, playtime), mainComposition_() {
    mainComposition_ = new char[std::strlen(mainComp) + 1];
    std::strcpy(mainComposition_, mainComp);
}

Classic::Classic(const Cd& cd, const char* mainComp)
                 : Cd(cd), mainComposition_() {
    mainComposition_ = new char[std::strlen(mainComp) + 1];
    std::strcpy(mainComposition_, mainComp);
}

Classic::Classic(const Classic& copy) : Cd(copy), mainComposition_() {
    mainComposition_ = new char[std::strlen(copy.mainComposition_) + 1];
    std::strcpy(mainComposition_, copy.mainComposition_);
}

Classic::Classic() : Cd() { mainComposition_ = nullptr; }

Classic::~Classic() { delete[] mainComposition_; }


void Classic::report() const {
    Cd::report();
    std::cout << "Main composition: " << mainComposition_ << std::endl;
}


const Classic& Classic::operator=(const Classic& copy) {
    if (this == &copy)
        return *this;
    Cd::operator=(copy);
    delete[] mainComposition_;
    mainComposition_ = new char[std::strlen(copy.mainComposition_) + 1];
    std::strcpy(mainComposition_, copy.mainComposition_);

    return *this;
}
