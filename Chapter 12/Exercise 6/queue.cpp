#include <cstdlib>

#include "queue.h"


Queue::Queue(int queueSize) : qsize_(queueSize) {}

Queue::~Queue() {
    Node* temp;
    while (nullptr != front_) {
        temp = front_;
        front_ = front_->next;
        delete temp;
    }
}


bool Queue::enQueue(const Item& item) {
    if (isFull())
        return false;
    Node* add = new Node;
    add->item = item;
    add->next = nullptr;
    items_++;
    if (nullptr == front_)
        front_ = add;
    else
        rear_->next = add;
    rear_ = add;

    return true;
}

bool Queue::deQueue(Item& item) {
    if (nullptr == front_)
        return false;
    item = front_->item;
    items_--;
    Node* temp = front_;
    front_ = front_->next;
    delete temp;
    if (0 == items_)
        rear_ = nullptr;

    return true;
}

//////////////////////////////////////////
// Customer

void Customer::set(long when) {
    processTime_ = std::rand() % 3 + 1;
    arrive_ = when;
}
