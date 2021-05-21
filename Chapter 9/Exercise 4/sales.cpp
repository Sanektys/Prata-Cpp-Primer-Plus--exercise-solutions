#include <iostream>
#include <cfloat>

#include "sales.h"


namespace SALES
{
    void setSales(Sales& sales, const double array[], int size) {
        if (0 == size)
            return;
        sales.min = {array[0]};
        sales.max = {0.0};
        sales.average = {0.0};
        for (int i = 0; i < size; i++) {
            if (sales.min > array[i])
                sales.min = array[i];
            if (sales.max < array[i])
                sales.max = array[i];
            sales.average += array[i];
        }
        sales.average /= size;
        sales.sales[0] = sales.min;
        sales.sales[1] = {0.0};
        sales.sales[2] = {0.0};
        sales.sales[3] = {0.0};
    }

    void setSales(Sales& sales) {
        using std::cout;
        using std::endl;
        using std::cin;

        cout << "Enter the amount of sales revenue for each quarter:\n";
        sales.min = DBL_MAX;
        sales.max = 0.0;
        sales.average = 0.0;
        int i = 0;
        for (; i < QUARTERS; i++) {
            cout << "  - for quarter " << i + 1 << ": ";
            cin >> sales.sales[i];
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
            if (sales.min > sales.sales[i])
                sales.min = sales.sales[i];
            if (sales.max < sales.sales[i])
                sales.max = sales.sales[i];
            sales.average += sales.sales[i];
        }
        if (0 == i) {
            sales.min = 0.0;
            sales.average = 0.0;
            return;
        }
        sales.average /= i;
    }
} // namespace SALES

void SALES::showSales(const Sales& sales) {
    std::cout << "---== Summary of sales revenue during the year ==---\n";
    for (int i = 0; i < QUARTERS; i++) {
        std::cout << "      ->  " << i + 1 << " quarter: "
                  << sales.sales[i] << std::endl;
    }
    std::cout << "----- lowest income -----\n"
              << " -->  " << sales.min << std::endl;
    std::cout << "----- highest income -----\n"
              << " -->  " << sales.max << std::endl;
    std::cout << "--=== average income ===--\n"
              << "  -->  " << sales.average << std::endl;
}
