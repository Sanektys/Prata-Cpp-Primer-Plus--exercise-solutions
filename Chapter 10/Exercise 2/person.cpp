#include <iostream>
#include <cstring>

#include "person.h"


Person::Person (const std::string& lastName, const char* firstName) {
    lname = lastName;
    std::strncpy(fname, firstName, LIMIT);
}

void Person::show() const {
  std::cout << fname << " " << lname << " \n";
}

void Person::formalShow() const {
    std::cout << lname << " " << fname << " \n";
}
