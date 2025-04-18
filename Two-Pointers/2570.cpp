// Merge Two 2D Arrays by Summing Values
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int i = 0, j = 0;
            int n = nums1.size(), m = nums2.size();
            vector<vector<int>> arr;
            
            while(i < n && j < m) {
                if(nums1[i][0] < nums2[j][0]) {
                    arr.push_back(nums1[i]);
                    i++;
                } else if(nums1[i][0] > nums2[j][0]) {
                    arr.push_back(nums2[j]);
                    j++;
                } else {
                    arr.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                    i++;
                    j++;
                }
            }
            while(i < n) {
                arr.push_back(nums1[i]);
                i++;
            }
            while(j < m) {
                arr.push_back(nums2[j]);
                j++;
            }
    
            return arr;
        }
    };
    

int main() { 
    vector<vector<int>> arr1 = {{1, 2},{2, 3},{4, 5}};
    vector<vector<int>> arr2 = {{1, 4}, {3, 2}, {4, 1}};

    Solution s;
    vector<vector<int>> ans;
    ans = s.mergeArrays(arr1, arr2);
    for(auto &i : ans){
        for(int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
   
    return 0;
}