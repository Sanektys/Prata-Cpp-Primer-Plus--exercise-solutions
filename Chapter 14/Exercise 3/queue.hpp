#pragma once


template <typename T>
class Queue
{
    public :
				Queue(int qs = Q_SIZE);
				~Queue();

		    bool isEmpty() const { return 0 == items; }
    		bool isFull() const { return qsize == items; }
    		int queueCount() const { return items; }
				bool enqueue(const T& item);
				bool dequeue(T& item);

    private :
        struct Node
        {
            T item;
            struct Node* next;
        };
        enum { Q_SIZE = 10 };
				Node* front;
				Node* rear;
				int items;
				const int qsize;

    private :
				Queue(const Queue&) = delete;
				Queue& operator=(const Queue&) = delete;
};


template <typename T>
Queue<T>::Queue(int qs) : qsize(qs) {
    front = rear = nullptr;
 	 	items = 0;
}

template <typename T>
Queue<T>::~Queue() {
 		 Node* temp;
		 while (front != nullptr) {
				 temp = front;
				 front = front->next;
				 delete temp;
		 }
}

template <typename T>
bool Queue<T>::enqueue(const T& item) {
		if (isFull())
				return false;
		Node* add = new Node;

		add->item = item;
		add->next = nullptr;
		items++;
		if (nullptr == front)
				front = add;
		else
				rear->next = add;
		rear = add;

		return true;
}

template <typename T>
bool Queue<T>::dequeue(T& item) {
		if (nullptr == front)
				return false;
		item = front->item;
		items--;
		Node* temp = front;
		front = front->next;
		delete temp;
		if (items == 0)
				rear = nullptr;

		return true;
}
