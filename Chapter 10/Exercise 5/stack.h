#ifndef STACK_H_
#define STACK_H_

namespace Customer
{
    struct Customer
    {
        char fullname[35];
        double payment;
    };
}

typedef Customer::Customer Item;

class Stack
{
    public :
        Stack() { top_ = 0; }

        bool isEmpty() const { return 0 == top_; }
        bool isFull()  const { return MAX == top_; }

        bool push(const Item& item);
        bool pop(Item& item);

    private :
        enum { MAX  = 10 };
        Item items_[MAX];
        int top_;
};

#endif
