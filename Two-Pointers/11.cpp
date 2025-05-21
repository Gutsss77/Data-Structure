//11. Container With Most Water
#include <iostream>
#include <vector>

using std::cout;
using std::min;
using std::max;
using std::vector;

class Solution {
public: 
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxArea = 0;
        while(i < j){
            int h = min(height[i], height[j]);
            int w = j - i;
            maxArea = max(maxArea, (h*w));
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxArea;
    }
};

int main(){
    vector<int> vec = {1,8,6,2,5,4,8,3,7};
    Solution s;
    int k = s.maxArea(vec);
    cout << k << "\n";
    return 0;
}