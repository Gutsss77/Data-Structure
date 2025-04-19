//2563. Count the Number of Fair Pairs
// binary search and sorting
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//Brute force : 
// class Solution {
//     public:
//         long long countFairPairs(vector<int>& nums, int lower, int upper) {
//             int n = nums.size();
//             int count = 0;
//             for(int i = 0; i < n; i++){
//                 for(int j = i+1; j < n; j++){
//                     if((nums[i] + nums[j] >= lower) && (upper >= nums[i] + nums[j])){
//                         count++;
//                     }
//                 }
//             }
//             return count;
//         }
//     };

class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin(), nums.end());
            long long count = 0;
            int n = nums.size();
            
            for (int i = 0; i < n; ++i) {
                int left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
                int right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
                count += (right - left);
            }
    
            return count;
        }
    };
    

int main(){
    vector<int> nums = {0,1,7,4,4,5};
    int lower = 3, upper = 6;
    Solution solution;
    int ans = solution.countFairPairs(nums, lower, upper);
    cout << "Total fair pairs : " << ans << endl;

    return 0;
}