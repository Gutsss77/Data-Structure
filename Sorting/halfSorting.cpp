#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

using std::cout;
using std::endl;
using std::sort;
using std::vector;

class HalfSorting{
public:
    vector<int> halfSort(vector<int> &nums){
        int mid = nums.size()/2;
        vector<int> ans;
        ans = nums;
        sort(ans.begin(), (ans.begin() + mid));
        
        return ans;
    }

    void display(vector<int> nums){
        for(int &i : nums){
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(){
    vector<int> nums = {5,4,3,2,1};
    HalfSorting hs;
    hs.display(nums);
    vector<int> ans = hs.halfSort(nums);
    hs.display(ans);
    return 0;
}