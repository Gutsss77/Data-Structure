// InBuild Priority-queue
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    //default is max Heap
    priority_queue<int>  pq;
    pq.push(20);
    pq.push(50);
    pq.push(10);
    pq.push(5);
    pq.push(40);

    cout << pq.top() << "\n";

    priority_queue<int, vector<int>, greater<int>> min;
    min.push(20);
    min.push(50);
    min.push(10);
    min.push(5);
    min.push(40);

    cout << min.top() << "\n";

    return 0;
}