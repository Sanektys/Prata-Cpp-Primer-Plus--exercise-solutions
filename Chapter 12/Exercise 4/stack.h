#ifndef STACK_H
#define STACK_H

typedef unsigned long Item;

class Stack
{
    public :
        Stack(int n = 10);
        Stack(const Stack&);
        ~Stack();

        bool isEmpty() const;
        bool isFull() const;

        bool push(const Item&);
        bool pop(Item&);

        const Stack& operator=(const Stack&);

    private :
        enum { MAX = 10 };
        Item* items_;
        int size_;
        int top_;
};

#endif
