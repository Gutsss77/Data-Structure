#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int u, v, weight;

    Edge(int src, int des, int w) : u(src), v(des), weight(w) {}
};

class DisjointSet {
private:
    vector<int> parent;
public:
    DisjointSet(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i; // Initially, each node is its own parent
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int xLeader = find(x);
        int yLeader = find(y);
        if (xLeader != yLeader) {
            parent[yLeader] = xLeader; // Union by leader
        }
    }
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

void kruskalAlgorithm(vector<Edge> &graph, int V) {
    sort(graph.begin(), graph.end(), compare);

    vector<Edge> mst;
    DisjointSet djs(V);
    int totalWeight = 0;

    for (Edge& e : graph) {
        if (djs.find(e.u) != djs.find(e.v)) {
            djs.unionSets(e.u, e.v);
            mst.push_back(e);
            totalWeight += e.weight;
        }
    }

    cout << "The MST is:\n";
    for (Edge& e : mst) {
        cout << e.u << " -- " << e.v << " : " << e.weight << "\n";
    }
    cout << "Total weight: " << totalWeight << endl;
}

int main() {
    int V = 4, E = 5;

    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalAlgorithm(edges, V);

    return 0;
}
