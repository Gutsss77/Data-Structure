#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::vector;

class Square {
public:
    int getSquareRoot(int n){
        int result = 0;
        for(int i = 1; i <= n/2; i++){
            if(i * i <= n){
                result = i;
            }
        }  
        return result;   
    }

    pair<int, int> twoSum(vector<int> &nums, int k){
        if(nums.size() < 2){
            return {-1, -1};
        }
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == k){
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

    int getMissingAP(vector<int> &nums){
        if(nums.size() < 2){
            return -1;
        }
        int diff = (nums.back() - nums.front()) / nums.size();
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i+1] - nums[i] != diff){
                return nums[i] + diff;
            }
        }
        return -1;
    }

    void reverseArray(vector<int> &nums){
        int i = 0, j = nums.size() - 1;
        while(i < j){
            std::swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};

int main(){
    int n = 37;
    Square s;
    int r = s.getSquareRoot(n);
    cout << r << " is the square root of " << n << "\n";

    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 9;
    pair<int, int> nr = s.twoSum(nums, k);
    cout << "Index are : " << nr.first << " " << nr.second << "\n";

    vector<int> vec = {1,2,3,4,6};
    int ss = s.getMissingAP(vec);
    cout << "Missing number : " << ss << "\n";

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    for(int i : arr){
        cout << i << " ";
    }
    cout << "\n";
    s.reverseArray(arr);
    for(int i : arr){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
