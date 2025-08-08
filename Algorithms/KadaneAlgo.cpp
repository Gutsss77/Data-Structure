//Kadane Algorithm :
/*
It efficiently finds the maximum sum of any contiguous subarray.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    //Kadane's algorithm
    int maxSubArraySum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int currSum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
            if (currSum < 0) {
                currSum = 0;  //reset if the current sum is negative
            }
        }
        return maxSum;
    }

    pair<int, vector<int>> subArraySum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {0, {}};
        
        int currMax = nums[0];
        int maxOverall = nums[0];
        int start = 0;
        int end = 0;
        int tempStart = 0;  // For tracking the starting of subarrays

        for (int i = 1; i < n; i++) {
            if (nums[i] > currMax + nums[i]) {
                currMax = nums[i];
                tempStart = i;
            } else {
                currMax += nums[i];
            }

            if (currMax > maxOverall) {
                maxOverall = currMax;
                start = tempStart;
                end = i;
            }
        }

        // Extracting the maximum sum subarray
        vector<int> maxSubArray(nums.begin() + start, nums.begin() + end + 1);
        return {maxOverall, maxSubArray};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, -1, 5, 4, -1, 7, -8};
    
    int maxSum = solution.maxSubArraySum(nums);
    cout << "Maximum Subarray Sum: " << maxSum << endl;
    
    auto result = solution.subArraySum(nums);
    cout << "Maximum Subarray Sum: " << result.first << endl;
    cout << "Max Subarray: ";
    for (int num : result.second) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
