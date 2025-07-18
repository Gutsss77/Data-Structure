#include <iostream>
#include <vector>

class Graph {
    int vertices;
    std::vector<std::vector<int>> adjList;

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(vertices); //Each index represents a vertex
    }

    void addEdge(int u, int v, bool directed = false) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            std::cout << "Invalid edge! Vertex out of range.\n";
            return;
        }

        adjList[u].push_back(v);
        if (!directed) {
            adjList[v].push_back(u);
        }
    }

    void printGraph() {
        std::cout << "Adjacency List:\n";
        for (int i = 0; i < vertices; ++i) {
            std::cout << i << " → ";
            for (int neighbor : adjList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(1, 2, true);// directed edge
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

    g.printGraph();

    return 0;
}
