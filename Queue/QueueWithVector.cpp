#include <iostream>
#include <vector>
#include <stdexcept>

using std::cout;
using std::runtime_error;
using std::vector;
using std::endl;

template <typename T>
class Queue{
private:
    vector<T> que;
    int front = -1;
    int rear = -1;
    int size = 0;

public:
    void enqueue(T data){
        que.push_back(data);
        if(front == -1){ //for first element
            front++;
        }
        size++;
        rear++;
    }

    T dequeue(){
        if(front <= -1 && rear <= -1){
            throw runtime_error("Queue is empty!");
        }
        T data = que[front++];
        size--;
        return data;
    }

    T getFront(){
        if(front == -1){
            throw runtime_error("Queue is empty!");
           
        }
        return que[front];
    }

    T getRear(){
        if(front == -1){
            throw runtime_error("Queue is empty!");
        }
        return que[rear];
    }
    
    bool isEmpty(){
        return front <= -1;
    }

    void display(){
        if(front == -1 ){
            throw runtime_error("Queue is empty!");
        }
        for(int i = front; i <= rear; i++){
            cout << que[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    cout << "Element at front is : " << q.getFront() << endl;
    cout << "Element at rear is : " << q.getRear() << endl;
    q.display();
    return 0;
}