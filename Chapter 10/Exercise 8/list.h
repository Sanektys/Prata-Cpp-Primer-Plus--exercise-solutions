typedef long long Item;

class List {
    public :
        List() : head_(nullptr), size_(0) {}
       ~List();

        void add(const Item&);
        bool isEmpty() const { return head_ == nullptr; }
        bool isFull() const { return size_ >= SIZE ? true : false; }
        void visit(void (*pf)(Item&));
        void visit(void (*pf)(const Item&)) const;

    private :
        struct Node {
            Item item;
            Node* nextItem;
        } *head_;

        static const short SIZE = 8;
        short size_;
};
