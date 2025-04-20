// 287. Find the Duplicate Number
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums){
        unordered_set<int> seen;
        int found = -1;
        for(int i : nums){
            if(seen.count(i)){
                found = i;
            }
            seen.insert(i);
        }
        return found;
    }
};

int main(){
    vector<int> nums = {3,1,3,4,2};
    Solution solution;
    int ans = solution.findDuplicate(nums);
    cout << "Dupliate is : " << ans << endl;

    return 0;
}