// Merge Sorted Array
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            if (m == 0) {
                nums1 = nums2;
                return;
            }
            if (n == 0) {
                return;
            }
    
            int i = 0, j = 0;
            vector<int> newArr;
            while (i < m && j < n) {
                if (nums1[i] <= nums2[j]) {
                    newArr.push_back(nums1[i]);
                    i++;
                } else {
                    newArr.push_back(nums2[j]);
                    j++;
                }
            }
    
            while (i < m) {
                newArr.push_back(nums1[i]);
                i++;
            }
    
            while (j < n) {
                newArr.push_back(nums2[j]);
                j++;
            }
            nums1 = newArr;
        }
    };

    
int main() { 
    vector<int> arr1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> arr2 = {2,5,6};
    int n = 3;

    Solution s;
    s.merge(arr1, m, arr2, n);
    for(int &i : arr1){
        cout << i << " ";
    }
    cout << endl;

   
    return 0;
}