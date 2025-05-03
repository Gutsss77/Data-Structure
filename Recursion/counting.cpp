//Counting using Recursion
#include <iostream>
using std::cout;

int sum(int n){
    if(n == 1){
        return 1;
    }
    return n + sum(n-1);
}

// void print(int n){
//     if( n == 0){
//         return;
//     }
//     cout << n << " recursive ";
//     print(n-1);
//     cout << n << " backtarcking ";
// }

int main(){
    int s;
    s = sum(10);
    cout << s;
    cout << "\n";
    return 0;

}

