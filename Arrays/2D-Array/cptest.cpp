#include <iostream>
#include <vector>
#define loop(i, a, b) for(int i = a; i < b; i++)

using namespace std;
typedef vector<int> vi;


int main(){
    vector<vi> arr;
    arr.resize(4, vi(4, 0));
    loop(i, 0, arr.size()){
        loop(j, 0, arr.size()){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}