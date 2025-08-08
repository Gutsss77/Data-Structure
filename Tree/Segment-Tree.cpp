#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

class SegmentTree{
    int n;
    vi maxTree;
    vi minTree;
    vi sumTree;
    
    void buildTree(const vi& st){
        n = st.size();
        maxTree.resize(2 * n);
        minTree.resize(2 * n);
        sumTree.resize(2 * n);

        for(int i = 0; i < n; i++){
            maxTree[n + i] = st[i]; //maxTree = {0, 0 ,0, 0, 0, 4, 6, 1, 10, 2} indices (5 - 9) are leaves
            minTree[n + i] = st[i];
            sumTree[n + i] = st[i];
        }

        for(int i = n - 1; i > 0; i--){
            maxTree[i] = max(maxTree[2 * i], maxTree[2 * i + 1]); // maxTree = {0, 10, 10, 6, 10, 4, 6, 1, 10, 2}
            minTree[i] = min(minTree[2 * i], minTree[2 * i + 1]); // minTree = {0, 1, 2, 1, 2, 4, 6, 1 ,10, 2}
            sumTree[i] = sumTree[2 * i] + sumTree[2 * i + 1]; // sumTree = {0, 23, 16, 7, 12, 4, 6, 1, 10, 2}
        }
    }
public:
    SegmentTree(vi& st){
        buildTree(st);
    }

    int rangeMaxQuery(int l, int r){
        int res = INT_MIN;
        l += n;
        r += n;
        while(l < r){
            if(l % 2 == 1) res = max(res, maxTree[l++]);
            if(r % 2 == 1) res = max(res, maxTree[--r]);
            l /= 2;
            r /= 2;
        }
        return res;
    }

    int rangeMinQuery(int l, int r){
        int res = INT_MAX;
        l += n;
        r += n;
        while(l < r){
            if(l % 2 == 1) res = min(res, minTree[l++]);
            if(r % 2 == 1) res = min(res, minTree[--r]);
            l /= 2;
            r /= 2;
        }
        return res;
    }

    int rangeSumQuery(int l, int r){
        int res = 0;
        l += n;
        r += n;
        while(l < r){
            if(l % 2 == 1) res += sumTree[l++];
            if(r % 2 == 1) res += sumTree[--r];
            l /= 2;
            r /= 2;
        }
        return res;
    }

    void updateQuery(int idx, int val){

    }

};

int main(){
    vi st = {4, 6, 1, 10, 2};
    SegmentTree SegTree(st);

    cout << "Max between 1 - 4 : " << SegTree.rangeMaxQuery(1, 4) << "\n";
    cout << "Min between 0 - 4 : " << SegTree.rangeMinQuery(0, 4) << "\n";
    cout << "Sum between 0 - 4 : " << SegTree.rangeSumQuery(0, 4) <<"\n";
    return 0;
}