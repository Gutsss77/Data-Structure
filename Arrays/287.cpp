// 287. Find the Duplicate Number
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        int found = -1;
        for (const int num : nums) {
            if (seen.count(num) != 0) {
                found = num;
                break;
            }
            seen.insert(num);
        }
        return found;
    }
};

int main() {
    std::vector<int> nums = {3, 1, 3, 4, 2};
    Solution solution;
    const int ans = solution.findDuplicate(nums);
    std::cout << "Duplicate is: " << ans << '\n';
    return 0;
}

//Java Code : Two approaches : 
/*

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Solution {

    int findDuplicate(int[] nums){
        Set<Integer> seen = new HashSet<>();
        for(int i : nums){
            if(seen.contains(i)){
                return i;
            }
            seen.add(i);
        }
        return -1;
    }

    // int findDuplicate(int[] nums){
    //     Arrays.sort(nums);
    //     for(int i = 0; i < nums.length; i++){
    //         if(nums[i] == nums[i+1]) return nums[i];
    //     }
    //     return -1;
    // }

    public static void main(String[] args){
        int[] nums = {3, 1, 3, 4, 2};
        Solution solution = new Solution();
        int dp = solution.findDuplicate(nums);
        System.out.println("Duplicate element is : " + dp);
    }
}

*/