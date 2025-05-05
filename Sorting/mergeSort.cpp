//Merge Sort Algorithm (With time comparison between small and large input)
#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <random> 
// Note : 1 microsecond (µs) = 1/1,000,000 of a second
//Total recursive stack are : 3 * n - 2
/*
mergeSort calls : 2 * n - 1
merge call : n - 1
total = 3 * n - 2

--> Stack calls : 
mergeSort(0, 9)                       -> Split into [10, 9, 8, 7, 6] and [5, 4, 3, 2, 1]
    ├── mergeSort(0, 4)               -> Split into [10, 9, 8] and [7, 6]
    │   ├── mergeSort(0, 2)           -> Split into [10, 9] and [8]
    │   │   ├── mergeSort(0, 1)       -> Split into [10] and [9]
    │   │   │   ├── mergeSort(0, 0)   -> Base case [10]
    │   │   │   └── mergeSort(1, 1)   -> Base case [9]
    │   │   │   └── merge(0, 0, 1)    -> Merge [10] and [9] -> [9, 10]
    │   │   └── mergeSort(2, 2)       -> Base case [8]
    │   │   └── merge(0, 1, 2)        -> Merge [9, 10] and [8] -> [8, 9, 10]
    │   └── mergeSort(3, 4)           -> Split into [7] and [6]
    │   │   ├── mergeSort(3, 3)       -> Base case [7]
    │   │   └── mergeSort(4, 4)       -> Base case [6]
    │   │   └── merge(3, 3, 4)        -> Merge [7] and [6] -> [6, 7]
    │   └── merge(0, 2, 4)            -> Merge [8, 9, 10] and [6, 7] -> [6, 7, 8, 9, 10]
    └── mergeSort(5, 9)               -> Split into [5, 4, 3] and [2, 1]
        ├── mergeSort(5, 7)           -> Split into [5, 4] and [3]
        │   ├── mergeSort(5, 6)       -> Split into [5] and [4]
        │   │   ├── mergeSort(5, 5)   -> Base case [5]
        │   │   └── mergeSort(6, 6)   -> Base case [4]
        │   │   └── merge(5, 5, 6)    -> Merge [5] and [4] -> [4, 5]
        │   └── mergeSort(7, 7)       -> Base case [3]
        │   └── merge(5, 6, 7)        -> Merge [4, 5] and [3] -> [3, 4, 5]
        └── mergeSort(8, 9)           -> Split into [2] and [1]
            ├── mergeSort(8, 8)       -> Base case [2]
            └── mergeSort(9, 9)       -> Base case [1]
            └── merge(8, 8, 9)        -> Merge [2] and [1] -> [1, 2]
        └── merge(5, 7, 9)            -> Merge [3, 4, 5] and [1, 2] -> [1, 2, 3, 4, 5]
    └── merge(0, 4, 9)                -> Merge [6, 7, 8, 9, 10] and [1, 2, 3, 4, 5] -> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

*/
using std::vector;
using std::cout;
using namespace std::chrono;
using std::random_device;
using std::iota;
using std::shuffle;
using std::endl;

/*
Complexity :
O(nlogn) for all three cases
*/

class Sorting {
private:
    void merge(vector<int>& nums, int start, int mid, int end) {
        int n = mid - start + 1;
        int m = end - mid;

        vector<int> L(n), R(m);

        for (int i = 0; i < n; i++)
            L[i] = nums[start + i];
        for (int j = 0; j < m; j++)
            R[j] = nums[mid + 1 + j];

        int i = 0, j = 0, k = start;

        while (i < n && j < m) {
            if (L[i] <= R[j]) {
                nums[k++] = L[i++];
            } else {
                nums[k++] = R[j++];
            }
        }

        while (i < n) {
            nums[k++] = L[i++];
        }
        while (j < m) {
            nums[k++] = R[j++];
        }
    }

public:
    void mergeSort(vector<int>& nums, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;

            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);

            merge(nums, start, mid, end);
        }
    }
};

int main() {
    vector<int> nums = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "Array Unsorted: ";
    for (int i : nums)
        cout << i << " ";
    cout << endl;

    Sorting s;
    auto startTime = high_resolution_clock::now();
    s.mergeSort(nums, 0, nums.size() - 1);
    auto endTime = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(endTime - startTime);

    cout << "Array After Sorted: ";
    for (int i : nums)
        cout << i << " ";
    cout << endl;
    cout << "Time taken : " << duration.count() << " microseconds" << "\n";


    vector<int> vec(10000);
    iota(vec.begin(), vec.end(), 0);

    random_device rd;
    std::mt19937 g(rd()); // Random number generator
    shuffle(vec.begin(), vec.end(), g); // Shuffle the array to make it unsorted

    auto start = high_resolution_clock::now();
    s.mergeSort(vec, 0, vec.size() - 1);
    auto stop = high_resolution_clock::now();

    auto duration2 = duration_cast<microseconds>(stop - start);

    // Output the time taken
    cout << "Time taken by mergeSort for 10000 elements: " << duration2.count() << " microseconds" << endl;

    return 0;
}
