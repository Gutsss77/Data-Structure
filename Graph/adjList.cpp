#include <iostream>
#include <vector>
#include <unordered_map>

class Graph{
    std::unordered_map<int, std::vector<int>> adj;

    //using metrix with 2d vector
    // int vertices;
    // std::vector<std::vector<int,int>> adjList;
public:
    // Graph(int vertex){
    //     this->vertices = vertex;
    //     adjList.resize(vertices, std::vector<int>(vertices, 0));
    // }

    void addEdge(int u, int v, bool directed = false){
        adj[u].push_back(v);
        if(!directed){
            adj[v].push_back(u);
        }
    }

    void printGraph() {
        for (auto& pair : adj) {
            std::cout << pair.first << " → ";
            for (const int& i : pair.second) {
                std::cout << i << " ";
            }
            std::cout << "\n";
        }
    }
};

int main(){
    Graph g;
    g.addEdge(1, 2, true);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    g.printGraph();
    return 0;
}