#include "move.h"


int main() {
    Move move;
    Move other{10.0, 5.5};
    Move another{other.add(other)};

    std::cout << "Show objects:\n";
    std::cout << "move:\n";
    move.showMove();
    std::cout << "other:\n";
    other.showMove();
    std::cout << "another:\n";
    another.showMove();

    std::cout << "\nreset other:\n";
    other.reset();
    other.showMove();
    std::cout << "reset move:\n";
    move.reset(1.5, 2.6);
    move.showMove();
    std::cout << "\nDone.\n";


    return 0;
}
