#include <iostream>

#include "sales.h"


int main() {
    double valuesOne[12] { 1220, 1100, 1122, 2212, 1232, 2334,
                           2884, 2393, 3302, 2922, 3002, 3544 };
    double valuesTwo[12] { 12, 11, 22, 21, 32, 34,
                           28, 29, 33, 29, 32, 35 };

    Sales salesOne(2011, valuesOne, 12);
    LabeledSales salesTwo("Blogstar", 2012, valuesTwo, 12);

    std::cout << "First try block:\n";
    try {
        int i{};
        std::cout << "Year = " << salesOne.year() << std::endl;
        for (i = 0; i < 12; i++) {
            std::cout << salesOne[i] << ' ';
            if (i % 6 == 5)
                std::cout << std::endl;
        }
        std::cout << "Year = " << salesTwo.year() << std::endl;
        std::cout << "Label = " << salesTwo.label() << std::endl;
        for (i = 0; i <= 12; i++) {
            std::cout << salesTwo[i] << ' ';
            if (i % 6 == 5)
                std::cout << std::endl;
        }
        std::cout << "End of try block 1.\n";
    }
    catch (Sales::BadIndex& bad) {
        std::cout << bad.what();
        LabeledSales::LabelBadIndex* labelBad{nullptr};
        if (bool(labelBad = dynamic_cast<LabeledSales::LabelBadIndex*>(&bad)))
            std::cout << "Company: " << labelBad->labelValue() << std::endl;
        std::cout << "bad index: " << bad.badIndexValue() << std::endl;
    }

    std::cout << "\nNext try block:\n";
    try {
        salesTwo[2] = 37.5;
        salesOne[20] = 23345.0;
        std::cout << "End of try block 2.\n";
    }
    catch (Sales::BadIndex& bad) {
        std::cout << bad.what();
        LabeledSales::LabelBadIndex* labelBad{nullptr};
        if (bool(labelBad = dynamic_cast<LabeledSales::LabelBadIndex*>(&bad)))
            std::cout << "Company: " << labelBad->labelValue() << std::endl;
        std::cout << "bad index: " << bad.badIndexValue() << std::endl;
    }
    std::cout << "Done!\n";


    return 0;
}