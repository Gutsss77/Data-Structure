#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;

typedef vector<vector<int>> vvi;

// Prerequisites DAG (directed acyclic graph)
class Graph {
    int vertices;
    vvi adjList;

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(vertices);
    }

    void addEdge(int u, int v, bool directed = false) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cout << "Invalid edge! Vertex out of range.\n";
            return;
        }
        adjList[u].push_back(v);
        if (!directed) {
            adjList[v].push_back(u);
        }
    }

    void displayList() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < vertices; ++i) {
            cout << i << " → ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }

    void dfsTopoSort(int node, vector<bool>& visited, stack<int>& topoStack) {
        visited[node] = true;
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsTopoSort(neighbor, visited, topoStack);
            }
        }
        topoStack.push(node);
    }

    void topologicalSort() {
        vector<bool> visited(vertices, false);
        stack<int> topoStack;

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                dfsTopoSort(i, visited, topoStack);
            }
        }

        cout << "Topological Sort: ";
        while (!topoStack.empty()) {
            cout << topoStack.top() << " ";
            topoStack.pop();
        }
        cout << "\n";
    }


    void kahnsAlgo(){
        vector<int> inDegree(vertices, 0);
        queue<int> q;
        vector<int> kahnAns;

        for(int i = 0; i < vertices; i++){
            for(auto neighbour : adjList[i]){
                inDegree[neighbour]++;
            }
        }
        for(int i = 0; i < vertices; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            kahnAns.push_back(node);
            for(auto i : adjList[node]){
                inDegree[i]--;
                if(inDegree[i] == 0){
                    q.push(i);
                }
            }
        }

        cout << "Topological Sort (Kahn's Algorithm): ";
        for(int node : kahnAns){
            cout << node << " ";
        }
        cout << "\n";

        if (kahnAns.size() != vertices) {
            cout << "Cycle detected! Topological sort not possible.\n";
        }
    }

};

int main() {
    Graph g(6);

    g.addEdge(2, 3, true);
    g.addEdge(3, 1, true);
    g.addEdge(4, 0, true);
    g.addEdge(4, 1, true);
    g.addEdge(5, 0, true);
    g.addEdge(5, 2, true);

    g.displayList();
    g.topologicalSort();
    g.kahnsAlgo();

    return 0;
}
