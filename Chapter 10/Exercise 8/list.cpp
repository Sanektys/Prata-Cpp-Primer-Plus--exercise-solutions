#include "list.h"


List::~List() {
    Node* delPrev = nullptr;
    while (!isEmpty()) {
        delPrev = head_;
        head_ = head_->nextItem;
        delete delPrev;
        size_--;
    }
}

void List::add(const Item& item) {
    if (nullptr == head_)
        head_ = new Node{item, nullptr};
    else if (!isFull()) {
        Node* current = head_;
        while (nullptr != current->nextItem)
            current = current->nextItem;
        current->nextItem = new Node{item, nullptr};
        size_++;
    }
}

void List::visit(void (*func)(Item&)) {
    Node* current = head_;
    while (nullptr != current) {
        func(current->item);
        current = current->nextItem;
    }
}

void List::visit(void (*func)(const Item&)) const {
    Node* current = head_;
    while (nullptr != current) {
        func(current->item);
        current = current->nextItem;
    }
}
