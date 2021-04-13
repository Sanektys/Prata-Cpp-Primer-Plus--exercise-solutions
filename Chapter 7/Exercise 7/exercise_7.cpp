#include <iostream>


const int MAX = 5;

double* fillArray(double*, double*);
void showArray(const double*, const double*);
void revalue(double r, double* arBeg, double* arEnd);

int main() {
    double properties[MAX];
    double* arrayEnd = fillArray(properties, properties + MAX);
    showArray(properties, arrayEnd);
    if (properties != arrayEnd) {
        std::cout << "Enter revaluation factor: ";
        double factor;
        while (!(std::cin >> factor)) {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, arrayEnd);
        showArray(properties, arrayEnd);
    }
    std::cout << "Done.\n";


    return 0;
}

double* fillArray(double* array, double* arrayEnd) {
    using namespace std;
    double temp{};
    int i{1};
    while (array != arrayEnd) {
        cout << "Enter value #" << i++ << ": ";
        cin >> temp;
        if (!cin) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)
            break;
        *array++ = temp;
    }

    return array;
}

void showArray(const double* array, const double* arrayEnd) {
    short size = arrayEnd - array + 1;
    while (array != arrayEnd) {
        std::cout << "Property #" << size - (arrayEnd - array) << ": $";
        std::cout << *array++ << std::endl;
    }
}

void revalue(double revalue, double* array, double* arrayEnd) {
    while (array != arrayEnd)
        *array++ *= revalue;
}
