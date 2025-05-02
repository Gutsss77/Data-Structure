#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::swap;
using std::pair;

class Problem {
public:
    pair<vector<int>, int> findPivot(vector<int>& nums, int pivot) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] < pivot) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == pivot) {
                mid++;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }

        int newPivotIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == pivot) {
                newPivotIndex = i;
                break;
            }
        }

        return {nums, newPivotIndex};
    }
};

int main() {
    Problem p;
    vector<int> vec = {12, 3, 7, 5, 6, 0, 9};

    pair<vector<int>, int> ans = p.findPivot(vec, vec.back());

    cout << "Index of pivot : " << ans.second << endl;
    for (int i : ans.first) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
