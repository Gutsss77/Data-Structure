#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Struct to represent an edge
struct Edge {
    int v;      // destination vertex
    int flow;   // current flow
    int cap;    // capacity
    int rev;    // index of reverse edge
};

typedef vector<vector<Edge>> vvEdge;
typedef vector<int> vi;
typedef queue<int> qi;

class Graph {
    int vertex;
    vvEdge adjList;

public:
    Graph(int n) {
        vertex = n;
        adjList.resize(n);
    }

    // Add edge to graph with residual edge
    void addEdge(int u, int v, int capacity) {
        Edge a{v, 0, capacity, (int)adjList[v].size()}; // forward edge
        Edge b{u, 0, 0, (int)adjList[u].size()};        // reverse edge
        adjList[u].push_back(a);
        adjList[v].push_back(b);
    }

    bool bfs(int s, int t, vi &parent, vi &edgeIndex) {
        vector<bool> visited(vertex, false);
        qi q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < adjList[u].size(); i++) {
                Edge &e = adjList[u][i];
                if (!visited[e.v] && e.flow < e.cap) {
                    parent[e.v] = u;
                    edgeIndex[e.v] = i;
                    visited[e.v] = true;
                    q.push(e.v);
                    if (e.v == t)
                        return true;
                }
            }
        }
        return false;
    }

    int fordFulkersonWithBFS(int src, int sink) {
        int maxFlow = 0;
        vi parent(vertex);
        vi edgeIndex(vertex);

        while (bfs(src, sink, parent, edgeIndex)) {
            int pathFlow = INT_MAX;

            // Find bottleneck capacity
            for (int v = sink; v != src; v = parent[v]) {
                int u = parent[v];
                Edge &e = adjList[u][edgeIndex[v]];
                pathFlow = min(pathFlow, e.cap - e.flow);
            }

            // Update flow along the path
            for (int v = sink; v != src; v = parent[v]) {
                int u = parent[v];
                Edge &e = adjList[u][edgeIndex[v]];
                e.flow += pathFlow;
                adjList[e.v][e.rev].flow -= pathFlow;
            }

            maxFlow += pathFlow;
        }

        return maxFlow;
    }

    void displayGraph() {
        for (int u = 0; u < vertex; ++u) {
            cout << "Node " << u << " connects to:\n";
            for (auto &edge : adjList[u]) {
                cout << "  → Node " << edge.v
                     << " | Flow: " << edge.flow
                     << " | Capacity: " << edge.cap
                     << " | Reverse Edge: " << edge.rev << "\n";
            }
        }
    }
};

int main() {
    Graph g(4);  // 0:S, 1:A, 2:B, 3:T

    g.addEdge(0, 1, 10); // S -> A
    g.addEdge(0, 2, 5);  // S -> B
    g.addEdge(1, 3, 8);  // A -> T
    g.addEdge(1, 2, 3);  // A -> B
    g.addEdge(2, 3, 7);  // B -> T

    g.displayGraph();
    cout << "Maximum flow : " << g.fordFulkersonWithBFS(0, 3) << endl;
    cout << "\nGraph after flow:\n";
    g.displayGraph();

    return 0;
}
