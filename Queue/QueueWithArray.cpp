//Queue implementation using Array(size is limited)
/*
ex : 
front element->1 2 3 4 5 6 7<-rear element
insertion at rear/back
deletion from front
*/

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::runtime_error;

template <typename T>
class Queue {
private:
    int front = -1;
    int rear = -1;
    int size = 0;
    T arr[100];

public:
    void enqueue(T data) {
        if (rear >= 99) {
            throw runtime_error("Queue is Full!");
        }
        arr[++rear] = data;
        size++;
        if (rear == 0) { // added first element
            front = 0;
        }
    }

    T dequeue() {
        if (front < 0 || front > rear) {
            throw runtime_error("Queue is Empty!");
        }
        T deq = arr[front++];
        size--;
        return deq;
    }

    T getFront() {
        if (front < 0 || front > rear) {
            throw runtime_error("Queue is Empty!");
        }
        return arr[front];
    }

    T getRear() {
        if (rear < 0 || front > rear) {
            throw runtime_error("Queue is Empty!");
        }
        return arr[rear];
    }

    bool isFull() {
        return rear == 99;
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout << "Element at front is : " << q.getFront() << endl;
    cout << "Element at rear is : " << q.getRear() << endl;
    cout << "Removing the front of queue: " << q.dequeue() << endl;
    cout << "All elements in queue: ";
    q.display();

    return 0;
}
