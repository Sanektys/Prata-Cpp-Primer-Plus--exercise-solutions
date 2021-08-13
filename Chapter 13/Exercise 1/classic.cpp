#include <iostream>
#include <cstring>

#include "classic.h"

////////////////////////////////////////////////////////////
// class Cd
Cd::Cd(const char *perf, const char *label, int select, double playtime)
       : performance_(), label_() {
    std::strncpy(performance_, perf, 49);
    std::strncpy(label_, label, 19);
    selections_ = select;
    playtime_ = playtime;
}

Cd::Cd(const Cd& copy) : performance_(), label_() {
    std::strcpy(performance_, copy.performance_);
    std::strcpy(label_, copy.label_);
    selections_ = copy.selections_;
    playtime_ = copy.playtime_;
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
    std::strcpy(performance_, copy.performance_);
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
    std::strncpy(mainComposition_, mainComp, 39);
}

Classic::Classic(const Cd& cd, const char* mainComp)
                 : Cd(cd), mainComposition_(){
    std::strncpy(mainComposition_, mainComp, 39);
}

Classic::Classic(const Classic& copy) : Cd(copy), mainComposition_() {
    std::strcpy(mainComposition_, copy.mainComposition_);
}


void Classic::report() const {
    Cd::report();
    std::cout << "Main composition: " << mainComposition_ << std::endl;
}


const Classic& Classic::operator=(const Classic& copy) {
    if (this == &copy)
        return *this;
    Cd::operator=(copy);
    std::strcpy(mainComposition_, copy.mainComposition_);

    return *this;
}
