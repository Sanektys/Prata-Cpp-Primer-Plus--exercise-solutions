#pragma once

#include <iostream>
#include <cstring>


class String
{
    public :
        String();
        String(const char*);
        String(const String&);
        ~String();

        int length() const { return length_; }
        void stringUp();
        void stringLow();
        int has(char);

        const String& operator=(const String&);
        const String& operator=(const char*);
        char& operator[](int i) { return string_[i]; }
        const char& operator[](int i) const { return string_[i]; }
        String operator+(const String&) const;
        String operator+(const char*) const;

        friend String operator+(const char* str1, const String& str2);
        friend bool operator<(const String& str1, const String& str2) {
            return std::strcmp(str1.string_, str2.string_) < 0;
        }
        friend bool operator>(const String& str1, const String& str2) {
            return str2 < str1;
        }
        friend bool operator==(const String& str1, const String& str2) {
            return std::strcmp(str1.string_, str2.string_) == 0;
        }
        friend std::ostream& operator<<(std::ostream& os, const String& str);
        friend std::istream& operator>>(std::istream& is, String& str);

        static int howMany() { return numStrings_; }

    private :
        char* string_;
        int length_;
        static int numStrings_;
        static const int CIN_LIMIT{80};
};
