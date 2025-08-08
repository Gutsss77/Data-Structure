//1695. Maximum Erasure Value
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> uni;
        int n = nums.size();
        int sum = INT_MIN;
        int i = 0, j = 1;
        int currSum = nums[i];
        uni.insert(nums[i]);
        while(j < n){
            if(uni.find(nums[j]) == uni.end()){
                uni.insert(nums[j]);
                currSum += nums[j];
                j++;
                sum = max(sum, currSum);
            }else{
                uni.erase(nums[i]);
                currSum -= nums[i];
                i++;
            }
        }
        return sum;
    }
};

int main(){
    vector<int> arr = {4,2,4,5,6};
    Solution s;
    int r = s.maximumUniqueSubarray(arr);
    cout << r;
    return 0;
}