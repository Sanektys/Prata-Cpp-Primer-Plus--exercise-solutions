#include <iostream>
#include <random>
#include <chrono>

#include "person.h"


static std::mt19937 randomizer(std::chrono::system_clock::to_time_t(
                                   std::chrono::system_clock::now()));

///////////////////////////////////////////////////////////
// class Person
void Person::show() const {
    std::cout << "Name: " << name_ << std::endl
              << "Surname: " << surname_ << std::endl;
}

void Person::set() {
    std::cout << "Enter person's name: ";
    std::getline(std::cin, name_);
    std::cout << "Enter person's surname: ";
    std::getline(std::cin, surname_);
}


///////////////////////////////////////////////////////////
// class Gunslinger
void Gunslinger::show() const {
    Person::show();
    info();
}

void Gunslinger::info() const {
    std::cout << "Time to ready: " << draw() << std::endl
              << "Number of notchings: " << numberOfNotchings_ << std::endl;
}

void Gunslinger::subSet() {
    std::cout << "Enter required preparation time in seconds: ";
    std::cin >> timeToReady_;
    std::cout << "Enter number of notches: ";
    std::cin >> numberOfNotchings_;
}


///////////////////////////////////////////////////////////
// class PokerPlayer
void PokerPlayer::show() const {
    Person::show();
    info();
}

void PokerPlayer::info() const {
    std::cout << "Card's number: " << draw() << std::endl;
}

int PokerPlayer::draw() const {
    return randomizer() % 52 + 1;
}


///////////////////////////////////////////////////////////
// class BadDude
void BadDude::show() const {
    Person::show();
    Gunslinger::info();
    PokerPlayer::info();
}