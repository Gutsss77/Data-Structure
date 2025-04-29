#include <iostream>

using std::cout;
using std::endl;

class Operation{
public:
    void mergeTwoSortedArrays(int nums1[], int nums2[], int n, int m){
        int arr[m+n];

        int i = 0, j = 0, k = 0;
        while(i < n && j < m){
            if(nums1[i] <= nums2[j]){
                arr[k] = nums1[i];
                i++;
                k++;
            }else{
                arr[k] = nums2[j];
                j++;
                k++;
            }
        }
        while(i < n){
            arr[k] = nums1[i];
            k++;
            i++;
        }
        while(j < m){
            arr[k] = nums2[j];
            j++;
            k++;
        }
        
        for(int h = 0; h < (m+n); h++){
            cout << arr[h] << " ";
        }
        cout << endl;
    }
};

int main(){
    int arr1[5] = {1,3,5,4,7};
    int arr2[5] = {0,2,4,6,8};
    int n = 5; int m = 5;
    Operation o;
    o.mergeTwoSortedArrays(arr1, arr2, n, m);

    return 0;
    
}