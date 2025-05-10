#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::runtime_error;

template <typename T>
class Node{
public:
    T data;
    Node* next;

    Node(T data){
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class Queue{
private:
    Node<T> *front = nullptr;
    Node<T> *rear = nullptr;

public:
    void enqueue(T data){
        Node<T>* node = new Node(data);
        if(rear == nullptr){
            front = rear = node;
            return;
        }else{
            rear->next = node;
            rear = node;
        }
    }

    T dequeue(){
        if(front == nullptr){
            throw runtime_error("Queue is empty!");
        }
        T reData = front->data;
        Node<T>* temp = front;
        front = front->next;
        if (front == nullptr) {
            // Queue is now empty
            rear = nullptr;
        }
        delete temp;
        return reData;
    }    

    void display() const{
        Node<T>* curr = front;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    T getFront() const{
        if(front == nullptr){
            throw runtime_error("Queue is empty!");
        }
        return front->data;
    }

    T getRear() const{
        if(rear == nullptr){
            throw runtime_error("Queue is empty!");
        }
        return rear->data;
    }

    bool isEmpty() const{
        return rear == nullptr;
    }

    ~Queue() {
        while (front != nullptr) {
            dequeue();
        }
    }    

};

int main(){
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);
    cout << "Element at front is : " << queue.getFront() << endl;
    cout << "Element at rear is : " << queue.getRear() << endl;
    queue.dequeue();

    queue.display();

    return 0;
}