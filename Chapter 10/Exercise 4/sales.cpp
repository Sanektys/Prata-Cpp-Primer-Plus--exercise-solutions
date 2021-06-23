#include <iostream>
#include <cfloat>

#include "sales.h"


namespace SALES
{
    Sales::Sales(const double array[], int size) {
        if (0 >= size)
            min_ = {0.0};
        else
            min_ = {array[0]};
        max_ = {0.0};
        average_ = {0.0};
        for (int i = 0; i < size; i++) {
            if (min_ > array[i])
                min_ = array[i];
            if (max_ < array[i])
                max_ = array[i];
            average_ += array[i];
        }
        average_ /= size;
        sales_[0] = min_;
        sales_[1] = {0.0};
        sales_[2] = {0.0};
        sales_[3] = {0.0};
    }

    void Sales::setSales() {
        using std::cout;
        using std::endl;
        using std::cin;

        cout << "Enter the amount of sales revenue for each quarter:\n";
        min_ = DBL_MAX;
        max_ = 0.0;
        average_ = 0.0;
        int i = 0;
        for (; i < QUARTERS; i++) {
            cout << "  - for quarter " << i + 1 << ": ";
            cin >> sales_[i];
            if (!cin) {
                if (cin.eof()) {
                    cout << "Enter terminated by EOF\n\a";
                    cin.clear();
                    cin.putback('\n');    //Leave the character in the stream,
                    break;                //so that next time we don't have
                                          //to read it straight with EOF
                }
                cout << "Incorrect entered number, try again...\n";
                --i;
                cin.clear();
                while (cin.get() != '\n');
                continue;
            }
            if (min_ > sales_[i])
                min_ = sales_[i];
            if (max_ < sales_[i])
                max_ = sales_[i];
            average_ += sales_[i];
        }
        if (0 == i) {
            min_ = 0.0;
            average_ = 0.0;
            return;
        }
        average_ /= i;
    }
} // namespace SALES

void SALES::Sales::show() const {
    std::cout << "---== Summary of sales revenue during the year ==---\n";
    for (int i = 0; i < QUARTERS; i++) {
        std::cout << "      ->  " << i + 1 << " quarter: "
                  << sales_[i] << std::endl;
    }
    std::cout << "----- lowest income -----\n"
              << " -->  " << min_ << std::endl;
    std::cout << "----- highest income -----\n"
              << " -->  " << max_ << std::endl;
    std::cout << "--=== average income ===--\n"
              << "  -->  " << average_ << std::endl;
}
