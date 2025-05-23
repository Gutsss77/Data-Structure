//209. Minimum Size Subarray Sum
#include <cerrno>
#include <climits>
#include <iostream>
#include <vector>

using std::cout;
using std::min;
using std::vector;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = 0;
        int minLength = INT_MAX;
        int sum = 0;
        while(end < n){
            sum += nums[end];

            while(sum >= target){
                minLength = min(minLength , i - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return (minLength == INT_MAX)? 0 : minLength;
    }
};

int main(){
    vector<int> vec = {2,3,1,2,4,3};
    int target = 7;
    Solution s;
    int k = s.minSubArrayLen(target, vec);
    cout << k << "\n";
    return 0;
}