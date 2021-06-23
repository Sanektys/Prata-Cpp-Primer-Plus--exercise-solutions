#include "stack.h"


bool Stack::push(const Item& item) {
    if (top_ < MAX) {
        items_[top_++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item& item) {
    if (top_ > 0) {
        item = items_[--top_];
        return true;
    }
    else
        return false;
}
