#include <iostream>
#include <ostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class Problem{
private:
    int countZerosHelper(int n, int count){
        int i = n % 10;
        if(i == 0) count++;
        n = n / 10;
        if(n == 0){
            return count;
        }
        return countZerosHelper(n, count);
    }

public:
    bool checkPalindrome(string s, int start, int end){
        if(start > end){
            return true;
        }
        if(s[start] != s[end]){
            return false;
        }

        return checkPalindrome(s, start + 1, end - 1);
    }

    int sum(int n){
        if(n == 0) return 0;
        return n + sum(n - 1);
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
        if(i == 1){
            return n;
        }
        return n * power(n, i - 1);
    }

    void printCountingTail(int n){ //Represent Tail Recursion 
        if(n < 0) return;
        cout << n << " ";
        printCountingTail(n - 1);
    }

    void printCountingHead(int n){ //Represent Head Recursion
        if(n < 0) return;
        printCountingHead(n - 1);
        cout << n << " ";
    }

    int countZeros(int n){
        if(n == 0) return 1;
        return countZerosHelper(n, 0);
    }
};

int main(int argc, char* argv[]){
    Problem p;
    if(p.checkPalindrome("abbbba", 0, 5)){
        cout << "Palindrome!" << endl;
    }else{
        cout << "Not Palindrome!" << endl;
    }
    int sum = p.sum(10);
    cout << "Sum is : " << sum << endl;

    cout << "Fibonocci  series : ";
    p.fibonacciSeries(0, 1, 50);
    cout << "\n";

    cout << "Power of 2 : " << p.power(2, 9) << endl;

    p.printCountingHead(7);
    cout << endl;
    p.printCountingTail(7);
    cout << endl;
    int countz = p.countZeros(101010100);
    cout << "NO. of zeros : " <<countz << endl;

    return 0;
}
