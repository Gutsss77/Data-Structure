//Selection Sort Algorithm (With time comparison between small and large input)
#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <numeric>

using std::cout;
using std::endl;
using std::swap;
using namespace std::chrono;
using std::random_device;
using std::vector;

/*
Select the minimum and place it then repeat it
*/

class Sorting{
public:
    void selectionSort(vector<int> &nums){
        int n = nums.size();
        for(int i = 0; i < n - 2; i++){
            int min_idx = i;
            for(int j = i + 1; j < n; j++){
                if(nums[j] < nums[min_idx]){
                    min_idx = j;
                }
            }
            swap(nums[i], nums[min_idx]);
        }
    }

    void selectionSortDescending(vector<int> &nums){
        int n = nums.size();
        for(int i = 0; i < n - 2; i++){
            int max_idx = i;
            for(int j = i + 1; j < n; j++){
                if(nums[j] > nums[max_idx]){
                    max_idx = j;
                }
            }
            swap(nums[i], nums[max_idx]);
        }
    }

    void display(vector<int> nums){
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    vector<int> nums = {10,9,8,7,6,5,4,3,2,1};
    Sorting s;
    s.display(nums);


    auto startTime = high_resolution_clock::now();
    s.selectionSort(nums);
    auto endTime = high_resolution_clock::now();
    s.display(nums);
    auto duration = duration_cast<microseconds>(endTime - startTime);
    cout << "Time taken to sort : " << duration.count() << " microseconds" << endl;

    s.selectionSortDescending(nums);
    s.display(nums);


    vector<int> vec(10000);
    iota(vec.begin(), vec.end(), 0);

    random_device rd;
    std::mt19937 g(rd()); // Random number generator
    shuffle(vec.begin(), vec.end(), g); // Shuffle the array to make it unsorted

    auto start = high_resolution_clock::now();
    s.selectionSort(vec);
    auto stop = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop - start);

    cout << "Time taken by selectionSort for 10000 elements: " << duration2.count() << " microseconds" << endl;

    return 0;

}