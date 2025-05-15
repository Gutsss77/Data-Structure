//153. Find Minimum in Rotated Sorted Array
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Rotated {
public:
    //brute force (O(n))
    // int findMin(vector<int> &nums){
    //     int n = nums.size();
    //     int min = INT_MAX;
    //     for(int i : nums){
    //         if(i < min){
    //             min = i;
    //         }
    //     }
    //     return min;
    // }

    //optimized force (O(log(n)))
    int findMin(vector<int> &nums){
        int low = 0, high = nums.size() - 1;
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] >  nums[high]){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return nums[low];
    }
};

int main(){
    vector<int> vec = {4,5,6,7,0,1,2};
    Rotated r;
    int min = r.findMin(vec);
    cout << min << "\n";
    return 0;
}