#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::swap;
using std::vector;
using std::endl;

class Problem{
private:
    int countZerosHelper(int n, int count){
        int i = n % 10;
        if(i == 0) count++;
        n = n / 10;
        if(n == 0) return count;
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

    int maxElement(vector<int> nums, int n, int element){
        if(n == nums.size()){
            return element;
        }
        if(nums[n] > element){
            element = nums[n];
        }

        return maxElement(nums, n + 1, element);
    }

    string reverseString(string s, string newS, int i){
        if(i == -1){
            return newS;
        }
        newS += s[i];
        return reverseString(s, newS, i - 1);
    }

    void reverseArray(vector<int> &nums, int l, int r){
        if(l > r){
            return;
        }
        swap(nums[l], nums[r]);
        return reverseArray(nums, l + 1, r - 1);
    }

    int factorial(int n){
        if(n <= 1) return 1;
        return n * factorial(n - 1);
    }
};

int main(int argc, char* argv[]){
    Problem p;
    int fact = p.factorial(5);
    cout << "The factorial is : " << fact << endl; 
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

    vector<int> vec = {1,2,6,4,5};
    int m = p.maxElement(vec, 0, -1);
    cout << "Max element is : " << m << endl;

    string word = "AnshSharma";
    string newWord = "";
    newWord = p.reverseString(word, newWord, word.length() - 1);
    cout << "Reverse is : " << newWord << endl;

    p.reverseArray(vec, 0, vec.size() - 1);
    for(int &i : vec){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
