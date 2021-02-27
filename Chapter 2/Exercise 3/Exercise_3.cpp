#include <iostream>


void firstMessage(void);
void secondMessage();

int main() {
    firstMessage();
    firstMessage();
    secondMessage();
    secondMessage();


    return 0;
}

void firstMessage(void) {
    using namespace std;
    cout << "Three blind mice\n";
}

void secondMessage() {
    std::cout << "See how they run\n";
}
