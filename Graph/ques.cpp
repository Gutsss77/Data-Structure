#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<vector<int>> vvi;

// To check if an undirected graph is connected from a given source
bool isConnected(vvi &adjList, int src, int vertices) {
    queue<int> q;
    vector<bool> visited(vertices, false);
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : adjList[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    for (bool nodeVisited : visited) {
        if (!nodeVisited) return false;
    }

    return true;
}

// To simulate strong connectivity (directed graphs)
bool isStronglyConnected(vvi &adjList) {
    for (int i = 0; i < adjList.size(); i++) {
        if (!isConnected(adjList, i, adjList.size())) {
            return false;
        }
    }
    return true;
}

// DFS helper
void helperDFS(vvi &adjList, int src, vector<bool> &visited) {
    visited[src] = true;
    for (int neighbor : adjList[src]) {
        if (!visited[neighbor]) {
            helperDFS(adjList, neighbor, visited);
        }
    }
}

// Check if src can reach des in an undirected graph
bool sourceToDestinationUG(vvi &adjList, int src, int des) {
    vector<bool> visited(adjList.size(), false);
    helperDFS(adjList, src, visited);
    return visited[des];
}

// Check if src can reach des in directed graph
bool sourceToDestinationD(vvi &adjList, int src, int des){
    vector<bool> visited(adjList.size(), false);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr == des) return true;
        for(auto neighbour : adjList[curr]){
            if(visited[neighbour] == false){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    return false;
}

bool haveCycle(vvi &adjListWithCycle, int src){
    vector<int> inDegree(adjListWithCycle.size(), 0);
        queue<int> q;
        vector<int> kahnAns;

        for(int i = 0; i < adjListWithCycle.size(); i++){
            for(auto neighbour : adjListWithCycle[i]){
                inDegree[neighbour]++;
            }
        }
        for(int i = 0; i < adjListWithCycle.size(); i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            kahnAns.push_back(node);
            for(auto i : adjListWithCycle[node]){
                inDegree[i]--;
                if(inDegree[i] == 0){
                    q.push(i);
                }
            }
        }
        return adjListWithCycle.size() != kahnAns.size();
}

int main() {
    vvi adjListUG = {
        {1, 2},     // 0
        {2, 3},     // 1
        {0, 3, 4},  // 2
        {0, 2},     // 3
        {3, 5},        // 4
        {}          // 5
    };

    // Directed graph (edges go one-way)
    vvi adjListD = {
        {1, 2},     // 0 → 1, 2
        {3},        // 1 → 3
        {4},        // 2 → 4
        {5},        // 3 → 5
        {},         // 4
        {}          // 5
    };

    vvi adjWithCycle = {
        {1},
        {2},
        {0}
    };


    cout << boolalpha;
    cout << "Reachable from node 0: " << isConnected(adjListUG, 0, adjListUG.size()) << endl;
    cout << "Graph is strongly connected: " << isStronglyConnected(adjListD) << endl;
    cout << "Source to destination for 0 to 4(undircted) : " << sourceToDestinationUG(adjListUG, 0, 4) << endl;
    cout << "Source to destination for 0 to 5(directed) : " << sourceToDestinationD(adjListD, 0, 5) << endl;
    cout << "Have cycle : " << haveCycle(adjWithCycle, 0) << endl;

    return 0;
}
