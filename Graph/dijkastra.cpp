#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<vector<pair<int, int>>> vvpi;

class Graph {
public:
    void dfsHelper(vvi& adjList, set<int>& visited, int curr) {
        cout << curr << " ";
        visited.insert(curr);

        for (const int& neighbor : adjList[curr]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsHelper(adjList, visited, neighbor);
            }
        }
    }

    void dfs(vvi& adjList, int start) {
        set<int> visited;
        dfsHelper(adjList, visited, start);
    }

    // Dijkstra’s Algorithm using std::set
    void dijkstra(vvpi& adj, int src, int vertices) {
        set<pair<int, int>> s; // (distance, node)
        vector<int> dist(vertices, INT_MAX); // Initialize all distances to infinity
        dist[src] = 0;

        s.insert({0, src}); // Start from source

        while (!s.empty()) {
            auto it = s.begin(); // Node with minimum distance
            int u = it->second;
            s.erase(it);

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    // Remove old entry if it exists
                    if (dist[v] != INT_MAX) {
                        s.erase({dist[v], v});
                    }

                    // Update and insert new distance
                    dist[v] = dist[u] + weight;
                    s.insert({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i < vertices; i++) {
            if (dist[i] == INT_MAX)
                cout << "Node " << i << " is unreachable\n";
            else
                cout << "To node " << i << " = " << dist[i] << "\n";
        }
    }
};

int main() {
    int V = 4; // Number of vertices
    vvpi adj(V); // Adjacency list: vector of vectors of (neighbor, weight)

    adj[0].push_back({1, 2}); // 0 → 1 (weight 2)
    adj[0].push_back({3, 4}); // 0 → 3 (weight 4)
    adj[1].push_back({2, 1}); // 1 → 2 (weight 1)
    adj[2].push_back({3, 3}); // 2 → 3 (weight 3)

    Graph g;
    g.dijkstra(adj, 0, V); // Source = node 0

    return 0;
}
