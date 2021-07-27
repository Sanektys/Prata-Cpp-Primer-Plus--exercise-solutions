#pragma once


class Customer
{
    public :
        Customer() {}

        void set(long when);
        long when() const { return arrive_; }
        int processTime() const { return processTime_; }

    private :
        long arrive_{0L};
        int processTime_{0};
};


typedef Customer Item;

class Queue
{
    public :
        Queue(int queueSize = Q_SIZE);
        ~Queue();

        bool isEmpty() const { return items_ == 0; };
        bool isFull() const { return items_ == qsize_; };
        int queueCount() const { return items_; };
        bool enQueue(const Item& item);
        bool deQueue(Item& item);

    private :
        struct Node
        {
            Item item;
            struct Node* next;
        };
        enum { Q_SIZE = 10 };

        Node* front_{nullptr};
        Node* rear_{nullptr};
        int items_{0};
        const int qsize_{Q_SIZE};

     private :
        Queue(const Queue&) = delete;
        Queue& operator=(const Queue&) = delete;
};
