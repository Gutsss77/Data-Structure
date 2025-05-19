// 26. Remove Duplicates from Sorted Array
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int> &nums){
        int i = 0;
        int n = nums.size();
        for(int j = 1; j < n; j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main(){
    vector<int> vec = {0,0,1,1,1,2,2,3,3,4};
    Solution s;
    int k = s.removeDuplicates(vec);
     cout << k << "\n";
    for(int i : vec){
        cout << i << " ";
    }
    return 0;
}