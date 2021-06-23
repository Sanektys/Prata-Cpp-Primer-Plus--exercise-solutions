#include <iostream>

#include "stack.h"


int main() {
    std::cout << "Enter information about several customers(their full name "
                 "and payment amount)\nFor terminate input type 'Q'\n\n";
    Stack customersList{};
    Customer::Customer customer{};
    short numberCustomers{0};
    while (!customersList.isFull()) {
        std::cout << "Enter customer's full name: ";
        bool cinGood{std::cin.get(customer.fullname, 35).good()};
        bool exitCondition{'\0' == customer.fullname[1]
                           && ('q' == customer.fullname[0]
                               || 'Q' == customer.fullname[0])};
        if (cinGood  && !exitCondition) {
            std::cin.get();
            std::cout << "Enter payment: $______\b\b\b\b\b\b";
            while (std::cin >> customer.payment && customer.payment <= 0.0)
                std::cout << "Payment amount can't be negative or zero!\n"
                          << "Enter payment again: $______\b\b\b\b\b\b";
            while (std::cin.good() && std::cin.get() != '\n');
        }
        if (!std::cin.good()) {
            if (std::cin.eof()) {
                std::cout << "Enter terminated by EOF\n\a";
                std::cin.clear();
                std::cin.putback('\n');
                break;
            }
            std::cout << "Incorrect entered data, try again or press 'Q'\n";
            std::cin.clear();
            while (std::cin.get() != '\n');
            continue;
        }
        else if (exitCondition)
            break;

        customersList.push(customer);
        numberCustomers++;
    }

    double totalIncome{0.0};
    char menuDecision{'\0'};
    while (!customersList.isEmpty()
           && ('q' != menuDecision && 'Q' != menuDecision)) {
        bool isPressP{'p' == menuDecision || 'P' == menuDecision};
        if (isPressP) {
            customersList.pop(customer);
            totalIncome += customer.payment;
            numberCustomers--;
        }
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout.precision(2);
        std::cout << "\n  ___~~~~~~~***** Orders summary *****~~~~~~~___\n";
        std::cout << " //        Current amount of orders: " << numberCustomers
                  << std::endl;
        std::cout << "||  Total income from all closed orders: "
                  << totalIncome << std::endl;
        if (isPressP) {
            std::cout << " \\\\\n  || You close follow order:\n";
            std::cout << "  ||  -> customer fullname: " << customer.fullname
                      << std::endl;
            std::cout << "  ||  -> deposit payment: " << customer.payment
                      << "\n //\n";
        }
        else
            std::cout << "||\n";
        std::cout << "|| --> Press 'Q' for exit or\n"
                  << "|| --> press 'P' for close last order\n"
                  << "|| ---> ";

        if (customersList.isEmpty())
            break;
        std::cin >> menuDecision;
        while ('p' != menuDecision && 'P' != menuDecision
               && 'q' != menuDecision && 'Q' != menuDecision) {
            if (!std::cin.good()) {
                if (std::cin.eof()) {
                    std::cin.clear();
                    std::cin.putback('\n');
                    std::cin.putback('\n');
                }
                else {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                }
            }
            std::cout << "|| Incorrect choise, press 'q' or 'p': "
                      << "|| ---> ";
            std::cin >> menuDecision;
        }
    }
    std::cout << "Terminate...\n";


    return 0;
}
