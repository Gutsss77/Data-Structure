#include <iostream>
using namespace std;

/*
Iterative Factorial
Space Complexity: O(1)
Time Complexity: O(n)
*/
long long iterativeFactorial(long long n) {
    long long product = 1;
    for (long long i = 2; i <= n; i++) {
        product *= i;
    }
    return product;
}

/*
Recursive Factorial
Space Complexity: O(n)
Time Complexity: O(n)
*/
long long recursiveFactorial(long long n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * recursiveFactorial(n - 1);
}

int main(){
    long long n;
    cout << "Enter a number : ";
    cin >> n;
    long long result1 = iterativeFactorial(n);
    cout << "Iterative Factorial trick gives : " << result1 << endl;
    long long result2 = recursiveFactorial(n);
    cout << "Recursive Factorial trick gives : " << result2 << endl;
    return 0;
}