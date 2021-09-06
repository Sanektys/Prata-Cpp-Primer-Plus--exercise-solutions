#include <iostream>
#include <cstring>

#include "worker.h"
#include "queue.hpp"


const int SIZE{5};

int main() {
    Queue<Worker*> lolas(SIZE);
    Worker *temp{nullptr};
    for (int ct = 0; ct < SIZE; ct++) {
        char choice{};
        std::cout << "Enter the employee category:\n"
                  << "w: waiter s: singer "
                  << "t: singing waiter q: quit\n";
        std::cin >> choice;
        while (std::strchr("wstq", choice) == NULL) {
            std::cout << "Please enter a w, s, t, or q: ";
            std::cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice) {
            case 'w' : temp = new Waiter;
                break;
            case 's' : temp = new Singer;
                break;
            case 't' : temp = new SingingWaiter;
                break;
        }
        std::cin.get();
        temp->set();
        lolas.enqueue(temp);
    }
    std::cout << "\nHere is your staff:\n";
    while (!lolas.isEmpty()) {
        std::cout << std::endl;
        lolas.dequeue(temp);
        temp->show();
        delete temp;
    }
    std::cout << "Bye.\n";


    return 0;
}
