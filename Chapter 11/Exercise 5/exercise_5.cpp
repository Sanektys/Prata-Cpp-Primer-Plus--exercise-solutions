#include "stonewt.h"


int main() {
    Stonewt supply(12.86);
    Stonewt scale{16, 1.8};
    std::cout << "Supply value: " << supply << std::endl;
    std::cout << "Scale value:  " << scale << std::endl;

    Stonewt total{};
    total = supply + scale;
    std::cout << "Total value after \"supply + scale\": " << total << std::endl;
    total = supply - 6;
    std::cout << "Total value after \"supply - 6\": " << total << std::endl;
    total.inStone();
    std::cout << "Total in stone: " << total << std::endl;
    total.inFloatPounds();
    total = 8.2f * 2;
    std::cout << "Total value after \"8.2f * 2\": " << total << std::endl;
    total = 12.0 + scale;
    std::cout << "Total value after \"12.0 + scale\": " << total << std::endl;
    total.inIntPounds();
    std::cout << "Total in integer pounds: " << total << std::endl;


    return 0;
}
