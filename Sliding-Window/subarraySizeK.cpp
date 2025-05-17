#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class SubArray {
public:
    // //brute force (O(n * k))
    // long long maximumSubarraySum(vector<int> &nums, int k) {
    //     long long maxSum = 0;
    //     int n = nums.size();

    //     for (int i = 0; i <= n - k; i++) {
    //         long long subSum = 0;
    //         for (int j = i; j < i + k; j++) {
    //             subSum += nums[j];
    //         }
    //         maxSum = std::max(maxSum, subSum);
    //     }

    //     return maxSum;
    // }

    //optimized force (O(n))
    long long maximumSubarraySum(vector<int> &nums, int k) {
        long long maxSum = 0;
        long long subSum = 0;
        int start = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            subSum += nums[i];
            if(i >= k - 1){
                maxSum = std::max(maxSum, subSum);
                subSum -= nums[start];
                start++;
            }
        }
        return maxSum;
    }
  
};


int main(){
    vector<int> vec = {2, 1, 5, 1, 3, 2};
    SubArray sa;
    long long abc = sa.maximumSubarraySum(vec, 3);
    cout << abc << "\n";
    return 0;
}