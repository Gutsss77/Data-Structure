#include<iostream>
using namespace std;

/*
space complexity : O(1)
time complexity : O(log n)
for both the solution
*/

// long long trailingZeros(long long n) {
//     long long count = 0;
//     for (long long i = 5; n / i >= 1; i *= 5) {
//         count += n / i;
//     }
//     return count;
// }

long long trailingZeros(long long n) {
    long long sum = 0;
    long long power = 5;
    
    while (n / power > 0) {
        sum += n / power;
        power *= 5;
    }

    return sum;
}


int main(){
    long long n;
    cout << "Enter a factorial number to find its trailing zeros : ";
    cin >> n;
    long long result = trailingZeros(n);

    cout << "Number of trailing zeros in " << n << "! are : " << result << endl;
    return 0;

}