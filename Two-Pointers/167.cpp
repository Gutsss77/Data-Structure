//167. Two Sum II - Input Array Is Sorted
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Array {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        vector<int> ans;
        while(i < j){
            if(numbers[i] + numbers[j] == target){
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                break;
            }else if(numbers[i] + numbers[j] > target){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> vec = {2,7,11,15};
    int target = 18;
    Array a;
    vector<int> ans = a.twoSum(vec, target);
    for(int i : ans){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}