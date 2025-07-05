//Graph with Adjacency Matrix 
#include <iostream>
#include <vector>

// //Bidirectional
// void insertIntoGraph(std::vector<std::vector<int>> &graph, int &vertices){
//     int edge;
//     std::cout << "Enter number of edges : ";
//     std::cin >> edge;
//     for(int i = 0; i < edge; i++){
//         int u, v;
//         std::cout << "Enter edge " << i + 1 << " (from to) : ";
//         std::cin >> u >> v;
//         if(u >= vertices || v >= vertices || u < 0 || v < 0){
//             std::cout << "Invalid edge!\n";
//             i--;
//             continue;
//         }
//         graph[u][v] = 1;
//         graph[v][u] = 1;
//     }
// }

class Graph {
    int vertices;
    std::vector<std::vector<int>> adjMatrix;
public:
    Graph(int vertex){
        this->vertices = vertex;
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    void insertInGraph(){
        int edge;
        std::cout << "Enter total edges in graph : ";
        std::cin >> edge;
        for(int i = 1; i <= edge; i++){
            int u, v;
            std::cout << "Enter edge (from to) : ";
            std::cin >> u >> v;
            if(u < 0 || v < 0 || u >= vertices || v >= vertices){
                std::cout << "Invalid edge! Enter again.\n";
                i--;
                continue;
            }
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
    }

    void printGraph(){
        std::cout << "\tMatrix is : " << "\n";
        for(const auto& row : adjMatrix){
            for(int i : row){
                std::cout << "\t" << i << " ";
            }
            std::cout << "\n";
        }
    }
};

int main(){
    int vertex;
    std::cout << "Enter number of vertex : ";
    std::cin >> vertex;
    Graph g(vertex);
    g.insertInGraph();
    g.printGraph();
    std::vector<std::vector<int>> graph(vertex, std::vector<int>(vertex, 0)); //initialize a vector of VxV with zeros
    // insertIntoGraph(graph, vertex);
    // printGraph(graph);

}

