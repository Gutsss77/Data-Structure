#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Sorting {
    vector<int> giveFrequency(const vector<int> &nums){
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxVal + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        return freq;
    }
public:
    vector<int> countingSort(vector<int>& nums){
        vector<int> freq = giveFrequency(nums);
        vector<int> sort;
        for(int i = 0; i < freq.size(); i++){
            if(freq[i] >= 1){
                for(int j = 0; j < freq[i]; j++){
                    sort.push_back(i);
                }
            }
        }
        return sort;
    }
};


int main(){
    vector<int> nums = {1, 2, 3, 3, 4, 4, 4, 2, 2, 1, 1};
    Sorting s;
    vector<int> sorted = s.countingSort(nums);
    for(int i : sorted){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}