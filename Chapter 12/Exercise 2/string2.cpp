#include <cctype>

#include "string2.h"


int String::numStrings_ = 0;


String::String(const char* str) {
    length_ = std::strlen(str);
    string_ = new char[length_ + 1];
    std::strcpy(string_, str);
    numStrings_++;
}

String::String() {
    length_ = 0;
    string_ = new char[1];
    string_[0] = '\0';
    numStrings_++;
}

String::String(const String& str) {
    length_ = str.length_;
    string_ = new char[length_ + 1];
    std::strcpy(string_, str.string_);
    numStrings_++;
}

String::~String() {
    numStrings_--;
    delete[] string_;
}


void String::stringUp() {
    for (int i = 0; i < length_; i++)
        string_[i] = std::toupper(string_[i]);
}

void String::stringLow() {
    for (int i = 0; i < length_; i++)
        string_[i] = std::tolower(string_[i]);
}

int String::has(char letter) {
    int counter = 0;
    for (int i = 0; i < length_; i++)
        if (letter == string_[i])
            counter++;

    return counter;
}


const String& String::operator=(const String& str) {
    if (this == &str)
        return *this;
    delete[] string_;
    length_ = str.length_;
    string_ = new char[length_ + 1];
    std::strcpy(string_, str.string_);

    return *this;
}

const String& String::operator=(const char* str) {
    delete[] string_;
    length_ = std::strlen(str);
    string_ = new char[length_ + 1];
    std::strcpy(string_, str);

    return *this;
}

String String::operator+(const String& str) const {
    String concat;
    concat.length_ = std::strlen(string_) + std::strlen(str.string_);
    concat.string_ = new char[concat.length_ + 1];
    std::strcat(concat.string_, string_);
    std::strcat(concat.string_, str.string_);

    return concat;
}

String String::operator+(const char* str) const {
    String concat;
    concat.length_ = std::strlen(string_) + std::strlen(str);
    concat.string_ = new char[concat.length_ + 1];
    std::strcat(concat.string_, string_);
    std::strcat(concat.string_, str);

    return concat;
}


String operator+(const char* str1, const String& str2) {
    String concat;
    concat.length_ = std::strlen(str1) + std::strlen(str2.string_);
    concat.string_ = new char[concat.length_ + 1];
    std::strcat(concat.string_, str1);
    std::strcat(concat.string_, str2.string_);

    return concat;
}

std::ostream& operator<<(std::ostream& output, const String& str) {
    output << str.string_;

    return output;
}

std::istream& operator>>(std::istream& input, String& str) {
    char temp[String::CIN_LIMIT];
    input.get(temp, String::CIN_LIMIT);
    if (input.good())
        str = temp;
    while (input.good() && input.get() != '\n')
        continue;

    return input;
}
