#include <iostream>


const short DAFNA_PERCENT = 10;
const short CLEO_PERCENT = 5;

void delay(int);

int main() {
    double balanceDafna{100};
    double baseBalanceDafna = balanceDafna;
    double balanceCleo{100};
    short year{};
    do {
        delay(1);
        ++year;
        std::cout << "Sum of balances for year " << year << ":\n";
        delay(2);
        balanceDafna += DAFNA_PERCENT / 100.0 * baseBalanceDafna;
        balanceCleo += CLEO_PERCENT / 100.0 * balanceCleo;
        std::cout << "Dafna - " << balanceDafna << "  |  "
                  << "Cleo - " << balanceCleo << std::endl << std::endl;
    } while (!(balanceCleo > balanceDafna));


    return 0;
}

void delay(int seconds) {
    clock_t delay = seconds * CLOCKS_PER_SEC;
    clock_t start = clock();
    while (clock() - start < delay);
}