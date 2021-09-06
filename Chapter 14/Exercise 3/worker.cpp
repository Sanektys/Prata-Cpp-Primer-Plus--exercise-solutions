#include <iostream>

#include "worker.h"


////////////////////////////////////////////////////////////
// class Worker
Worker::~Worker() {}

void Worker::data() const {
    std::cout << "Name: " << fullname << std::endl;
    std::cout << "Employee ID: " << id << std::endl;
}

void Worker::get() {
    std::getline(std::cin, fullname);
    std::cout << "Enter worker's ID: ";
    std::cin >> id;
    while (std::cin.get() != '\n')
        continue;
}


////////////////////////////////////////////////////////////
// class Waiter
void Waiter::set() {
    std::cout << "Enter waiter's name: ";
    Worker::get();
    get();
}

void Waiter::show() const {
    std::cout << "Category: waiter\n";
    Worker::data();
    data();
}

void Waiter::data() const {
    std::cout << "Panache rating: " << panache << std::endl;
}

void Waiter::get() {
    std::cout << "Enter waiter's panache rating: ";
    std::cin >> panache;
    while (std::cin.get() != '\n')
        continue;
}


////////////////////////////////////////////////////////////
// class Singer
const char* Singer::pv[Singer::Vtypes]{"other", "alto", "contralto", "soprano",
                                 "bass", "baritone", "tenor"};

void Singer::set() {
    std::cout << "Enter singer's name: ";
    Worker::get();
    get();
}

void Singer::show() const {
    std::cout << "Category: singer\n";
    Worker::data();
    data();
}

void Singer::data() const {
    std::cout << "Vocal range: " << pv[voice] << std::endl;
}

void Singer::get() {
    std::cout << "Enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < Vtypes; i++) {
        std::cout << i << ": " << pv[i] << " ";
        if (i % 4 == 3)
            std::cout << std::endl;
    }
    if (i % 4 != 0)
        std::cout << std::endl;
    std::cin >> voice;
    while (std::cin.get() != '\n')
        continue;
}


////////////////////////////////////////////////////////////
// class SingingWaiter
void SingingWaiter::data() const {
    Singer::data();
    Waiter::data();
}

void SingingWaiter::get() {
    Waiter::get();
    Singer::get();
}

void SingingWaiter::set() {
    std::cout << "Enter singing waiter's name: ";
    Worker::get();
    get();
}

void SingingWaiter::show() const {
    std::cout << "Category: singing waiter\n";
    Worker::data();
    data();
}
