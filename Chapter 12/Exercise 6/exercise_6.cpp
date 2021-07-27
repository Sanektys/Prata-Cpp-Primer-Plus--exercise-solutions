#include <iostream>
#include <ctime>

#include "queue.h"


const int MINUTES_PER_HOUR{60};

inline bool newCustomer(double x);


int main() {
    std::srand(std::time(nullptr));

    std::cout << "Case Study: Bank of Heather Automatic Teller\n";
    std::cout << "Enter maximum size of queues: ";
    int queueSize{};
    std::cin >> queueSize;
    Queue line[2]{{queueSize}, {queueSize}};
    std::cout << "Enter the number of simulation hours: ";
    int hours{};
    std::cin >> hours;

    long cycleLimit = MINUTES_PER_HOUR * hours;    //Количество циклов эмуляции
    std::cout << "Enter the average number of customers per hour: ";
    double perHour;
    std::cin >> perHour;
    double minutesPerCustomers = MINUTES_PER_HOUR / perHour;   //среднее время
                                            //между появлениями новых клиентов

    Item temp{};           //Данные нового клиента
    long turnaways{};      //Не допущенных в полную очередь
    long customers{};      //Присоединенные к очереди
    long served{};         //Обслужено во время эмуляции
    long sumLine{};        //Общая длина очереди
    int waitTime[2]{};     //Время до освобождения банкомата
    long lineWait[2]{};    //Общее время в очереди

    for (int cycle{}; cycle < cycleLimit; cycle++) {
        //Выбор наименее заполненной очереди
        int smallerLine{line[0].queueCount() <= line[1].queueCount() ? 0 : 1};
        //Добавление клиента
        if (newCustomer(minutesPerCustomers)) { //Появление клиента
            if (line[smallerLine].isFull())
                turnaways++;
            else {
                customers++;
                temp.set(cycle);    //Заполнение данных клиента
                                    //(на каком цикле пришёл
                                    // и сколько займёт времени)
                line[smallerLine].enQueue(temp);   //Добавление клиента в очередь
            }
        }
        //Обработка очередей
        for (int i{}; i < 2; i++) {
            //Если время клиента вышло и очередь не пуста:
            if (waitTime[i] <= 0 && !line[i].isEmpty()) {
                line[i].deQueue(temp); //Клиент выходит из очереди
                                       //к банкомату
                waitTime[i] = temp.processTime();
                lineWait[i] += cycle - temp.when();
                served++;
            }
            if (waitTime[i] > 0)
                waitTime[i]--;
            sumLine += line[i].queueCount();
        }
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
                  << (double)(lineWait[0] + lineWait[1]) / served
                  << " minutes\n";
    }
    else
        std::cout << "No customers!\n";

    std::cout << "Done!\n";


    return 0;
}

//x = среднее время в минутах мужду клиентами
//возвращается значение true, если в эту минуту появляется клиент
bool newCustomer(double x) { return std::rand() * x / RAND_MAX < 1; }
