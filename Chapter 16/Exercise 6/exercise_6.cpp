#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

#include "customer.h"


const int MIN_PER_HR{60};

inline bool newCustomer(double);


int main() {
    std::srand(std::time(nullptr));

    std::cout << "Case Study: Bank of Heather Automatic Teller\n"
              << "Enter maximum size of queue: ";
    
    std::size_t queueSize{};
    std::cin >> queueSize;
    std::queue<Customer> line;

    std::cout << "Enter the number of simulation hours: ";
    int hours{};
    std::cin >> hours;
    long cycleLimit{MIN_PER_HR * hours};

    std::cout << "Enter the average number of customers per hour: ";
    double perHour{};
    std::cin >> perHour;

    double minutesPerCustomer{};
    minutesPerCustomer = MIN_PER_HR / perHour;

    Customer temp;
    long turnaways{};
    long customers{};
    long served{};
    std::size_t sumLine{};
    int waitTime{};
    long lineWait{};

    for (long cycle{}; cycle < cycleLimit; cycle++) {
        if (newCustomer(minutesPerCustomer)) {
            if (line.size() >= queueSize)
                turnaways++;
            else {
                customers++;
                temp.set(cycle);
                line.push(temp);
            }
        }
        if (waitTime <= 0 && !line.empty()) {
            temp = line.front();
            line.pop();
            waitTime = temp.processTime();
            lineWait += cycle - temp.when();
            served++;
        }

        if (waitTime > 0)
            waitTime--;
        sumLine += line.size();
    }

    if (customers > 0) {
        std::cout << "Customers accepted: "  << customers << '\n'
                  << " - customers served: " << served    << '\n'
                  << " - turnaways: "        << turnaways << '\n'
                  << "Average queue size: " ;
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout << double(sumLine) / cycleLimit << '\n'
                  << " - average wait time: "
                  << double(lineWait) / served    << " minutes\n";
    }
    else
        std::cout << "No customers!\n";

    std::cout << "Done!\n";


    return 0;
}


inline bool newCustomer(double x) {
    return (std::rand() * x / RAND_MAX < 1);
}