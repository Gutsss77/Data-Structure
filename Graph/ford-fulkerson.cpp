//Network flow theory : Maximum flow

#include <iostream>
#include <vector>
#include <stack>
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
typedef vector<bool> vb;
typedef stack<int> si;

class Graph {
    int vertices;
    vvEdge adjList;

public:
    Graph(int vertex) {
        this->vertices = vertex;
        adjList.resize(vertex);
    }

    // Add edge to graph with residual edge
    void addEdge(int u, int v, int capacity) {
        Edge a{v, 0, capacity, (int)adjList[v].size()}; // forward edge
        Edge b{u, 0, 0, (int)adjList[u].size()};        // reverse edge
        adjList[u].push_back(a);
        adjList[v].push_back(b);
    }

    bool dfsHelper(int u, int t, vb &visited, vi &parent) {
        si st;
        st.push(u);

        visited[u] = true;
        parent[u] = -1;

        while(!st.empty()){
            int current = st.top();
            st.pop();

            for(Edge &e : adjList[current]){
                if(!visited[e.v] && e.flow < e.cap){
                    parent[e.v] = current;
                    if(e.v == t) return true;
                    visited[e.v] = true;
                    st.push(e.v);
                }
            }
        }

        return false;
    }

    // Ford-Fulkerson using DFS
    int fordFulkersonDFS(int src, int sink) {
        int maxFlow = 0;
        vi parent(vertices);
        vb visited(vertices);

        while (true) {
            fill(visited.begin(), visited.end(), false);
            if (!dfsHelper(src, sink, visited, parent)) break;

            int pathFlow = INT_MAX;

            // Find minimum capacity in the path
            for (int v = sink; v != src; v = parent[v]) {
                int u = parent[v];
                for (Edge& e : adjList[u]) {
                    if (e.v == v) {
                        pathFlow = min(pathFlow, e.cap - e.flow);
                        break;
                    }
                }
            }

            // Update flow along the path
            for (int v = sink; v != src; v = parent[v]) {
                int u = parent[v];
                for (Edge &e : adjList[u]) {
                    if (e.v == v) {
                        e.flow += pathFlow;
                        adjList[v][e.rev].flow -= pathFlow;
                        break;
                    }
                }
            }

            maxFlow += pathFlow;
        }

        return maxFlow;
    }

    // Print adjacency list with flow/capacity info
    void displayGraph() {
        for (int u = 0; u < vertices; ++u) {
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

    cout << "Maximum flow: " << g.fordFulkersonDFS(0, 3) << endl;

    cout << "\nGraph after flow:\n";
    g.displayGraph();

    return 0;
}
