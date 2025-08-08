#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    vector<int> arr = {1,5,9,10,11,20,13,13,15};
    int k = 7;
    priority_queue<int> pq;

    for(int i : arr){
        pq.push(i);
        if(pq.size() > k) pq.pop();
    }
    int ans = pq.top();
    cout << ans << "\n";
    
    return 0;
}