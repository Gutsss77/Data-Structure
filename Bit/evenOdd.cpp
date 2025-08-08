#include <iostream>
using namespace std;

void evenOdd(int n){
    if(!(n & 1)) cout << "Even";
    else cout << "Odd";
}

void newTrick(int n){
    int i = n/2;
    int j = i*2;
    if(j == n) cout << "Even";
    else cout << "Odd";
}

void newTrick2(int n){
    if((n^1) == (n+1)){
        cout << "Even";
    }else cout << "Odd";
}

int main(){
    int n; 
    cin >> n;
    evenOdd(abs(n));
    newTrick(n);
    newTrick2(n);
    return 0;
}