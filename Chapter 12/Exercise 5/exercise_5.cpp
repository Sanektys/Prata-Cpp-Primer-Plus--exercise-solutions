#include <iostream>
#include <ctime>

#include "queue.h"


const int MINUTES_PER_HOUR{60};

inline bool newCustomer(double x);


int main() {
    std::srand(std::time(nullptr));

    std::cout << "Case Study: Bank of Heather Automatic Teller\n";
    std::cout << "Enter maximum size of queue: ";
    int queueSize{};
    std::cin >> queueSize;
    Queue line(queueSize);
    std::cout << "Enter the number of simulation hours: ";
    int hours{};
    std::cin >> hours;

    long cycleLimit = MINUTES_PER_HOUR * hours;    //Количество циклов эмуляции
    std::cout << "Enter the average number of customers per hour: ";
    double perHour;
    std::cin >> perHour;
    double minutesPerCustomers = MINUTES_PER_HOUR / perHour;   //среднее время
                                            //между появлениями новых клиентов

    Item temp{};         //Данные нового клиента
    long turnaways{};    //Не допущенных в полную очередь
    long customers{};    //Присоединенные к очереди
    long served{};       //Обслужено во время эмуляции
    long sumLine{};      //Общая длина очереди
    int waitTime{};      //Время до освобождения банкомата
    long lineWait{};     //Общее время в очереди

    for (int cycle{}; cycle < cycleLimit; cycle++) {
        if (newCustomer(minutesPerCustomers)) {    //Появление клиента
            if (line.isFull())
                turnaways++;
            else {
                customers++;
                temp.set(cycle);       //Заполнение данных клиента                                   //(на каком цикле пришёл и сколько займёт времени)
                line.enQueue(temp);    //Добавление клиента в очередь
            }
        }
        //Если время клиента вышло и очередь не пуста:
        if (waitTime <= 0 && !line.isEmpty()) {
            line.deQueue(temp);   //Клиент выходит из очереди к банкомату
            waitTime = temp.processTime();
            lineWait += cycle - temp.when();
            served++;
        }
        if (waitTime > 0)
            waitTime--;
        sumLine += line.queueCount();
    }

    if (customers > 0) {
        std::cout << "customers accepted: "   << customers
                  << "\n customers served: "  << served
                  << "\n turnaways: "         << turnaways
                  << "\naverage queue size: ";
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout << (double)sumLine / cycleLimit
                  << "\n average wait time: "
                  << (double)lineWait / served << " minutes\n";
    }
    else
        std::cout << "No customers!\n";

    std::cout << "Done!\n";


    return 0;
}

//x = среднее время в минутах мужду клиентами
//возвращается значение true, если в эту минуту появляется клиент
bool newCustomer(double x) { return std::rand() * x / RAND_MAX < 1; }
