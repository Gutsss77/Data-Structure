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
                break; // Exit early once the duplicate is found
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
    std::cout << "Duplicate is: " << ans << '\n'; // Use '\n' instead of std::endl
    return 0;
}
