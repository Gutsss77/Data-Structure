//33. Search in Rotated Sorted Array
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Rotated {
public:
    //brute force (O(n))
    int search1(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                return i;
                break;
            }
        }
        return -1;
    }

    //optimized force (O(log(n)))
    //finding the smallest
    int findPivot(vector<int> &nums){
        int i = 0, j = nums.size() - 1;
        while(i < j){
            int mid = i + (j - i) / 2;
            if(nums[mid] > nums[j]){
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return i;
    }

    int binarySearch(vector<int> &nums, int left, int right, int target) {
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int search2(vector<int> &nums, int target){
        int n = nums.size();
        int pivot = findPivot(nums);

        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return binarySearch(nums, pivot, n - 1, target);
        } else {
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};

int main(){
    vector<int> vec = {4,5,6,7,0,1,2};
    Rotated r;
    int target = 0;
    int i = r.search1(vec, target);
    cout << i << "\n";

    int j = r.search2(vec, target);
    cout << j << "\n";

    return 0;
}