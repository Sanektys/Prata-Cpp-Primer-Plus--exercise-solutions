#include "complex.h"


std::istream& operator>>(std::istream& stream, Complex& value) {
    std::cout << "real: ";
    while (!(stream >> value.real_)) {
        if (stream.eof()) {
            std::cout << "Input terminate...\n";
            stream.clear();
            stream.putback('\n');
            stream.putback('\n');
            return stream;
        }
        stream.clear();
        char quit{char(std::cin.peek())};
        if (quit == 'q' || quit == 'Q') {
            stream.clear(std::ios::failbit);
            return stream;
        }
        std::cout << "Incorrect entered real part... try again: ";
        while (stream.get() != '\n');
    }
    std::cout << "imaginary: ";
    while (!(stream >> value.imagine_)) {
        if (stream.eof()) {
            std::cout << "Input terminate...\n";
            stream.clear();
            stream.putback('\n');
            stream.putback('\n');
            return stream;
        }
        stream.clear();
        char quit{char(std::cin.peek())};
        if (quit == 'q' || quit == 'Q') {
            stream.clear(std::ios::failbit);
            return stream;
        }
        std::cout << "Incorrect entered imaginary part... try again: ";
        while (stream.get() != '\n');
    }

    return stream;
}
