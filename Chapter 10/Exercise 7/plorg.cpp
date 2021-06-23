#include "plorg.h"


Plorg::Plorg(const char name[], short contIndex) : name_(),
                                                   contentmentIndex_(contIndex) {
    int i{0};
    while (name[i] != '\0' && i < 19) {
        name_[i] = name[i];
        i++;
    }
    name_[i] = '\0';
}
