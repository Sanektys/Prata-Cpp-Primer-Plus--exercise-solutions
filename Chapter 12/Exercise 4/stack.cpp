#include "stack.h"


Stack::Stack(int number) {
    size_ = number;
    top_ = 0;
    items_ = new Item[size_];
}

Stack::Stack(const Stack& anotherStack) {
    items_ = new Item[anotherStack.size_]{};
    size_ = anotherStack.size_;
    top_ = anotherStack.top_;
    for (int i{0}; i < top_; i++)
        items_[i] = anotherStack.items_[i];
}

Stack::~Stack() {
    delete[] items_;
}

bool Stack::isEmpty() const { return top_ == 0; }
bool Stack::isFull() const { return top_ == size_; }

bool Stack::push(const Item& item) {
    if (!Stack::isFull()) {
        items_[top_++] = item;

        return true;
    }
    else
        return false;
}

bool Stack::pop(Item& item) {
    if (!Stack::isEmpty()) {
        item = items_[--top_];

        return true;
    }
    else
      return false;
}

const Stack& Stack::operator=(const Stack& anotherStack) {
    if (this == &anotherStack)
        return *this;
    delete[] items_;
    items_ = new Item[anotherStack.size_]{};
    size_ = anotherStack.size_;
    top_ = anotherStack.top_;
    for (int i{0}; i < top_; i++)
        items_[i] = anotherStack.items_[i];

    return *this;
}
