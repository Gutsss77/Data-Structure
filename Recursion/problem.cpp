#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class Problem{
public:
    bool checkPalidrome(string s, int start, int end){
        if(start >= end){
            return true;
        }
        if(s[start] != s[end]){
            return false;
        }
        return checkPalidrome(s, start + 1, end - 1);
    }

    void fibonacciSeries(int first, int second, int end){
        if(first > end){
            return;
        }
        int n;
        cout << first << " ";
        n = first;
        first = second;
        second = n + first;
        fibonacciSeries(first, second, end);
    }

    long long power(long long n, int i){
        if(i == 0){
            return n;
        }
        return n * power(n, i - 1);
    }
};

int main(int argc, char* argv[]){
    Problem p;
    if(p.checkPalidrome("abbbba", 0, 5)){
        cout << "Palindrome!" << endl;
    }else{
        cout << "Not Palindrome!" << endl;
    }
    cout << "Fibonocci  series : ";
    p.fibonacciSeries(0, 1, 50);

    cout << "Power of 5 : " << p.power(5, 3);

    return 0;
}