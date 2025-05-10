// In-Build stack in STL

#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Current Top of stack : " << s.top() << endl;
    s.pop();
    cout << "Current top after popping : " << s.top() << endl;
}
