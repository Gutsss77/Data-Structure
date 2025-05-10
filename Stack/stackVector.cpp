// Stack Implementation using Vector (size is dynamic)
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
#include <vector>
#include <stdexcept> //for errors

using std::cout;
using std::vector;
using std::runtime_error;
using std::endl;

template <typename T>
class Stack {
private:
    int top = -1;
    vector<T> stack;

public:
    void push(T data) {
        stack.push_back(data);
        top++;
    }

    T peek() {
        if (top <= -1) {
            throw runtime_error("Stack is empty!");
        }
        return stack[top];
    }

    T pop() {
        if (top <= -1) {
            throw runtime_error("Stack is empty!");
        }
        T value = stack[top];
        stack.pop_back();
        top--;
        return value;
    }

    void display(){
        int i = top;
        for(i = top; i > -1; i--){
            cout << stack[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty() const {
        return top == -1;
    }
};

int main() {
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    cout << "Top element is : " << s.peek() << endl;
    cout << "Popped element : " << s.pop() << endl;
    cout << "Current Top element : " << s.peek() << endl;
    cout << "All elements of stack : ";
    s.display();

    return 0;
}
