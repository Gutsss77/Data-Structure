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
    return 0;
}