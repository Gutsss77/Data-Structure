#include <iostream>
using namespace std;


void counting(int n){
    if(n == 0){
        return;
    }
    counting(n - 1);
    std::cout << n << " ";
}

void reverseCounting(int n){
    if(n == 0){
        return;
    }
    std::cout << n << " ";
    reverseCounting(n - 1);
}

int main(){
    counting(9);
    cout << endl;
    reverseCounting(9);
    return 0;
}