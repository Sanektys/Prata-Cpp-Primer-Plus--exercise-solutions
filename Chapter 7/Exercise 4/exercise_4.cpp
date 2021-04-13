#include <iostream>


long double probability(unsigned numbers, unsigned picks, unsigned mega);

int main() {
    using std::cout;
    unsigned total, choices, meganumber;
    cout << "Enter the total number of choices on the game card,\n"
            "the number of picks allowed,\n"
            "and total number of choices in the meganumber field\n"
            "Example: 47 5 27\n";
    while ((std::cin >> total >> choices >> meganumber) && total > 1
                                                        && choices <= total
                                                        && meganumber > 1) {
        cout << "You have one chance in ";
        cout << probability(total, choices, meganumber);
        cout << " of winning main prize.\n";
        cout << "\nNext three numbers (q to quit): ";
    }
    cout << "\nBye!\n";


    return 0;
}

long double probability(unsigned numbers, unsigned picks, unsigned mega) {
    long double result = 1.0l;
    for (; picks > 0; numbers--, picks--)
        result *= (long double)numbers / picks;
    result *= mega;

    return result;
}
