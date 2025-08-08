//Min Heap
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

//Heaps : 
/*
    1. It should be complete binary tree
    2. Follows : -> Min heap : Root minimum < (Ls, Rs)
                    Max Heap : Root maximum > (Ls, Rs)

    Complete binary tree : 
        -> Left than right
        -> Follow binary tree property
        -> No incomplete level

    parent = (i-1)/2
    left = 2i + 1;
    right = 2i + 2;
*/

//Min Heap : root <= children
class Heap {
    // int index;
    vi heapArray;
    // int capacity;

    int parent(int idx){ return (idx - 1) / 2;}

    int leftChild(int idx){ return (2 * idx + 1);}

    int rightChild(int idx){return (2 * idx + 2);}

    void heapifyUp(int idx){
        while(idx > 0){
            int p = parent(idx);
            if(heapArray[idx] < heapArray[p]){
                swap(heapArray[idx], heapArray[p]);
                idx = p;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int idx){
        int small = idx;
        int l = leftChild(idx);
        int r = rightChild(idx);
        int size = heapArray.size();

        if(heapArray[l] < heapArray[small] && l < size){
            small = l;
        }
        if(heapArray[r] < heapArray[small] && r < size){
            small = r;
        }
        if(small != idx){
            swap(heapArray[small], heapArray[idx]);
            heapifyDown(small);
        }

    }
public:
    //Dyanmic growth
    // Heap(int idx = 0){
    //     this->index = idx;
    // }

    // Heap(int cap, int idx = 0){
    //     this->index = idx; //index can be 1 or 0
    //     this->capacity = cap;
    //     heapArray.resize(capacity);

    void insertHeap(int num){
        // if(index == capacity){
        //     cout << "Maximum capacity reached!";
        //     return;
        // }
        // heapArray[index] = num;
        // heapifyUp(index);
        // index++;
        heapArray.push_back(num); //dynamic
        heapifyUp(heapArray.size() - 1);
    }

    int top(){
        if(heapArray.size() == 0){
            return -1;
        }
        return heapArray[0];
    }

    void pop(){
        if(heapArray.size() == 0){
            cout << "Heap is empty\n";
            return;
        }
        swap(heapArray[0], heapArray[heapArray.size() - 1]);
        heapArray.pop_back();
        heapifyDown(0);
    }

    void printHeap(){
        cout << "Stored heap array is : \n";
        for(int i = 0; i < heapArray.size(); ++i){
            cout << heapArray[i] << " ";
        }
        cout << "\n";
    }

    //Remember : Heap cannot be traversed on main rather use another another ds for traversing
    // Make copy of heap and than display

    void displayHeap(){
        cout << "Display original heap : ";
        vi copyHeap = heapArray;
        int n = heapArray.size();
        for(int i = 0; i < n; i++){
            cout << heapArray[0] << " ";
            pop();
            heapifyDown(0);
        }
        cout << "\n";
        heapArray = copyHeap;
    }

};


int main(){
    Heap hp;
    hp.insertHeap(15);
    hp.insertHeap(10);
    hp.insertHeap(20);
    hp.insertHeap(17);
    hp.insertHeap(8);
    hp.pop();
    cout << "Current top is : " << hp.top() << "\n";
    hp.insertHeap(25);
    hp.insertHeap(5);
    hp.insertHeap(30);
    hp.insertHeap(12);
    hp.insertHeap(6);
    hp.pop();
    hp.printHeap();
    //Original heap
    hp.displayHeap();
    hp.printHeap();

    return 0;
}