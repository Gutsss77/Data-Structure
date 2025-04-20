// Binary Search :
/*
Binary Search is an efficient algorithm used to find an element in a sorted array by repeatedly
dividing the search interval in half. It works by comparing the target value to the middle element,
eliminating half of the search space with each iteration, achieving a time complexity of O(log n).
*/

//Linear Search : 
/*
Linear Search is a simple algorithm that sequentially checks each element in an array
until the target is found or the entire array is traversed. It has a time complexity of O(n),
making it inefficient for large datasets compared to more advanced searching algorithms.
*/

#include <algorithm>
#include<iostream>
#include<vector>

using std::cout;
using std::vector;

class Serching{
public:
    bool linearSearch(vector<int> &vec, int key){
        for(int &i : vec){
            if(i == key){
                return true;
            }
        }
        return false;
    }

    bool binarySearch(vector<int> &vec, int key){
        std::sort(vec.begin(), vec.end());
        int left = 0;
        int right = vec.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(vec[mid] == key){
                return true;
            }else if(key > vec[mid]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return false;
    }

};

int main(){
    vector<int> vec = {3, 12, 56, 78, 9, 34, 45, 89, 21, 67, 54, 32, 19, 76, 43, 18, 61, 88, 37, 92,
                        60, 29, 51, 80, 14, 48, 55, 39, 66, 27, 72, 41,
                        84, 5, 62, 98, 23, 69, 30, 47, 10, 33, 25, 71, 59, 50, 68, 74, 85, 2};
    int key = 23;
    Serching search;
    if(search.linearSearch(vec, key)){
        cout << "Found! (using Linear search)" << "\n";
    }else{
        cout << "Not found!" << "\n";
    }

    if(search.binarySearch(vec, key)){
        cout << "Found! (using Binary search)" << "\n";
    }else{
        cout << "Not found!" << "\n";
    }
    return 0;
}

//💀 heavy comparision

//Time comparison here
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <chrono>  // for timing
// #include <random>

// using namespace std;
// using namespace std::chrono;

// class Serching {
// public:
//     bool linearSearch(const vector<int> &vec, int key) {
//         for (int i : vec) {
//             if (i == key)
//                 return true;
//         }
//         return false;
//     }

//     bool binarySearch(vector<int> vec, int key) {
//         int left = 0;
//         int right = vec.size() - 1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (vec[mid] == key)
//                 return true;
//             else if (key > vec[mid])
//                 left = mid + 1;
//             else
//                 right = mid - 1;
//         }
//         return false;
//     }
// };

// int main() {
//     vector<int> vec(1'000'000);
//     std::iota(vec.begin(), vec.end(), 1); // Fill with 1 to 1,000,000
//     int key = 1'000'000;


//     Serching search;

//     // Shuffle for linear fairness
//     std::random_device rd;
//     std::mt19937 g(rd());
//     std::shuffle(vec.begin(), vec.end(), g);

//     // Linear Search Timing
//     auto start1 = high_resolution_clock::now();
//     bool linearResult = search.linearSearch(vec, key);
//     auto end1 = high_resolution_clock::now();
//     auto duration1 = duration_cast<microseconds>(end1 - start1);

//     if (linearResult) {
//         cout << "Found! (Linear search)\n";
//     }
//     cout << "Linear Search Time: " << duration1.count() << " µs\n";

//     // Sort and Binary Search
//     std::sort(vec.begin(), vec.end());

//     auto start2 = high_resolution_clock::now();
//     bool binaryResult = search.binarySearch(vec, key);
//     auto end2 = high_resolution_clock::now();
//     auto duration2 = duration_cast<microseconds>(end2 - start2);

//     if (binaryResult) {
//         cout << "Found! (Binary search)\n";
//     }
//     cout << "Binary Search Time: " << duration2.count() << " µs\n";

//     return 0;
// }