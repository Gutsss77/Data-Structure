/*
Problem 2: Square Root (Integer Part)
Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
Do not use any built-in square root function like sqrt().
*/
#include <iostream>
using std::cout;

class SquareRoot{
public:
    long long sqrtX(int x){
        int i = 1, j = x;
        long long ans = -1;
        while(i <= j){
            long long mid = i + (j-i)/2;
            if(mid * mid == x) {
                return mid;
            }
            else if(mid * mid < x) {
                ans = mid;
                i = mid + 1;
            }
            else{ 
                j = mid -1;
            }
        }
        return ans;
    }
};

int main(){
    int x = 50;
    SquareRoot sr;
    long long rootx = sr.sqrtX(x);
    cout << "Square Root of x is : " << rootx << "\n";
    return 0;
}