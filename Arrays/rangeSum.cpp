#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

void inputArray(vi &array, int n){
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
}

vi prefixSum(vi &array, int n){
    int currSum = 0;
    vi ansArray;
    for(int i = 0;i < n; i++){
        currSum += array[i];
        ansArray.push_back(currSum);
    }
    return ansArray;
}

int rangeBasedSum(vi& array, int l, int r, int n){
    if (l == 0) return array[r];
    if (r == n) return -1;
    return array[r] - array[l - 1];
}

void displayArray(vi &array){
    for(int &i : array){
        cout << i << " ";
    }
    cout << "\n";
}

int main(){
    vi array;
    int n;
    cin >> n;
    array.resize(n);
    inputArray(array, n);
    vi ans = prefixSum(array, n);
    cout << "Prefix Array is : ";
    displayArray(ans);
    cout << "Sum from " << rangeBasedSum(ans, 4, 8, n) << "\n";

    while(true){
        int idx;
        cin >> idx;
        if(idx == -1) break;
        cout << "New Array : ";
        int randomNo;
        cin >> randomNo;
        array[idx - 1] = randomNo;
        displayArray(array);
        cout << "New prefixSum : ";
        ans = prefixSum(array, n);
        displayArray(ans);
    }
    return 0;
}
