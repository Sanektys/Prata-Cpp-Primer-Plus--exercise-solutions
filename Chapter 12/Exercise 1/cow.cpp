#include <iostream>
#include <cstring>

#include "cow.h"


Cow::Cow(const char* name, const char* hobby, double weight) {
    std::strncpy(this->name, name, 20);
    this->hobby = new char[std::strlen(hobby) + 1];
    std::strcpy(this->hobby, hobby);
    this->weight = weight;
}

Cow::Cow(const Cow& copied) {
    std::strncpy(this->name, copied.name, 20);
    this->hobby = new char[std::strlen(copied.hobby) + 1];
    std::strcpy(this->hobby, copied.hobby);
    this->weight = copied.weight;
}

Cow::~Cow() { delete[] hobby; }


Cow& Cow::operator=(const Cow& copied) {
    if (this == &copied)
        return *this;
    std::strncpy(this->name, copied.name, 20);
    delete[] this->hobby;
    this->hobby = new char[std::strlen(copied.hobby) + 1];
    std::strcpy(this->hobby, copied.hobby);
    this->weight = copied.weight;

    return *this;
}

void Cow::showCow() const {
    std::cout << "Cow's name: " << name
              << "\n- hobby: " << hobby
              << "\n- weight: " << weight
              << std::endl;
}
