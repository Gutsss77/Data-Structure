//Journey to the moon (hackerRank)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DSU {
private:
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return;

        // Union by size
        if(size[px] < size[py]) {
            parent[px] = py;
            size[py] += size[px];
        } else {
            parent[py] = px;
            size[px] += size[py];
        }
    }

    unordered_map<int, int> getComponentSizes() {
        unordered_map<int, int> sizes;
        for(int i = 0; i < parent.size(); i++) {
            int p = find(i);
            sizes[p]++;
        }
        return sizes;
    }
};

int findValidPair(vector<vector<int>> &astronauts, int n) {
    DSU d(n);

    // Unite astronaut pairs
    for(auto &pair : astronauts) {
        d.unite(pair[0], pair[1]);
    }

    unordered_map<int, int> componentSizes = d.getComponentSizes();
    long long result = 0;
    long long sum = 0;

    for(auto &[_, size] : componentSizes) {
        result += sum * size;
        sum += size;
    }

    return result;
}

int main() {
    int n = 5;
    vector<vector<int>> astronaut = {{0,1}, {2,3}, {0,4}};

    cout << findValidPair(astronaut, n) << endl;

    return 0;
}
