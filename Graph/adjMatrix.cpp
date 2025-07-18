#include <iostream>
#include <vector>

class Graph {
    int vertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int vertex) : vertices(vertex) {
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    void insertInGraph() {
        int edge;
        std::cout << "Enter total number of edges in the graph: ";
        std::cin >> edge;

        for (int i = 1; i <= edge; i++) {
            int u, v, d;
            std::cout << "Enter edge " << i << " (from to) and direction (0 for undirected, 1 for directed): ";
            std::cin >> u >> v >> d;

            if (d != 0 && d != 1) {
                std::cout << "Invalid direction. Please enter 0 or 1.\n";
                i--;
                continue;
            }

            if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
                std::cout << "Invalid edge! Vertices should be between 0 and " << vertices - 1 << ".\n";
                i--;
                continue;
            }

            adjMatrix[u][v] = 1;
            if (d == 0) {
                adjMatrix[v][u] = 1;
            }
        }
    }

    void printGraph() {
        std::cout << "\nAdjacency Matrix:\n";
        for (const auto& row : adjMatrix) {
            for (int val : row) {
                std::cout << val << "\t";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    int vertex;
    std::cout << "Enter number of vertices: ";
    std::cin >> vertex;

    Graph g(vertex);
    g.insertInGraph();
    g.printGraph();

    return 0;
}
