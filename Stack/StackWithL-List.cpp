#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::runtime_error;

template <typename T>
class Stack {
private:
    T data;
    Stack* next;
    Stack* top = nullptr;

public:
    Stack(T data = T()) : data(data), next(nullptr) {}

    void push(T data) {
        Stack* s = new Stack(data);
        if (top == nullptr) {
            top = s;
        } else {
            s->next = top;
            top = s;
        }
    }

    T peek() {
        if (top == nullptr) {
            throw runtime_error("Stack is empty!");
        }
        return top->data;
    }

    T pop() {
        if (top == nullptr) {
            throw runtime_error("Stack is empty!");
        }
        Stack* temp = top;
        T popped = temp->data;
        top = temp->next;
        delete temp;
        return popped;
    }

    void display() {
        Stack* curr = top;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (top != nullptr) {
            Stack* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack<int> ss;
    ss.push(22);
    ss.push(33);
    ss.push(44);
    ss.push(55);
    ss.push(66);
    ss.push(77);
    ss.push(88);
    ss.push(99);
    
    cout << "Top element is : " << ss.peek() << endl;
    cout << "Popped element is : " << ss.pop() << endl;
    ss.display();

    return 0;
}
