#include <iostream>
#include <queue>
#include <set>
#include <vector>

class Traversal {
public:
    // Breadth First Search
    void bfs(std::vector<std::vector<int>>& adjList, int start) {
        std::queue<int> q;
        std::set<int> visited;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            std::cout << curr << " ";

            for (const int& neighbor : adjList[curr]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }

    // Depth First Search helper (recursive)
    void dfsHelper(std::vector<std::vector<int>>& adjList, std::set<int>& visited, int curr) {
        std::cout << curr << " ";
        visited.insert(curr);

        for (const int& neighbor : adjList[curr]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsHelper(adjList, visited, neighbor);
            }
        }
    }

    // Depth First Search
    void dfs(std::vector<std::vector<int>>& adjList, int start) {
        std::set<int> visited;
        dfsHelper(adjList, visited, start);
    }
};

int main() {
    // Correct adjacency list for:
    //     0
    //    / \
    //   1   2
    //  /   / \
    // 3   4   5
    std::vector<std::vector<int>> adjList = {
        {1, 2},    // 0
        {3},       // 1
        {4, 5},    // 2
        {},        // 3
        {},        // 4
        {}         // 5
    };

    Traversal t;
    std::cout << "BFS: ";
    t.bfs(adjList, 0); std::cout << "\n";

    std::cout << "DFS: ";
    t.dfs(adjList, 0); std::cout << "\n";

    return 0;
}
