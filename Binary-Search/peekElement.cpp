/*
Problem 3: Find Peak Element
A peak element in an array is an element that is strictly greater than its neighbors.

Given an array nums, find a peak element and return its index.
You may assume that nums[-1] = nums[n] = -∞, so edge elements can also be peaks.
*/
#include <iostream>
#include <vector>

using std::vector;
using std::cout;

class Element {
public:
    //brute force
    // int peekElement(vector<int> &nums) {
    //     int n = nums.size();
    //     if (n == 1) return 0;
    //     if (nums[0] > nums[1]) return 0;
    //     if (nums[n - 1] > nums[n - 2]) return n - 1;

    //     for (int i = 1; i < n - 1; ++i) {
    //         if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
    //             return i;
    //     }
    //     return -1;
    // }

    //optimized force
    int peekElement(vector<int> &nums){
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[mid + 1]){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }

};


int main(){
    vector<int> vec = {1,2,1,3,5,6,4};
    Element e;
    int n = e.peekElement(vec);
    cout << n;
    return 0;
}