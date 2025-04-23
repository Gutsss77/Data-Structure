// Stack Implementation using Array (size is fixed)
/*
working: 
ex : push(1), pus(2), push(3), push(4)
stack(internally) : 
        4
        3
        2
        1
peek() -> 4
pop() -> 4 after
new stack is : 
                3
                2
                1
*/

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::runtime_error;

template <typename T>
class Stack {
private:
    int top = -1;
    T arr[100];

public:
    void push(T data) {
        if (top >= 99) {
            throw runtime_error("Stack is full!");
        }
        arr[++top] = data;
    }

    T peek() {
        if (top <= -1) {
            throw runtime_error("Stack is empty!");
        }
        return arr[top];
    }

    T pop() {
        if (top <= -1) {
            throw runtime_error("Stack is empty!");
        }
        return arr[top--];
    }

    void display(){
        int i = top;
        for(i = top; i > -1; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);

    cout << "Top element: " << stack.peek() << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Top element: " << stack.peek() << endl;
    cout << "All stack elements : ";
    stack.display();

    return 0;
}
