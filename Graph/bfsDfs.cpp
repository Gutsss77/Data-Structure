//Breadth first search
#include <iostream>
#include <queue>
#include <set>
#include <vector>

/*

    A
   / \
  B   C
 /   / \
D   E   F

Bfs = a b c d e f (from selected vertex how many vertex we can visit)
Dfs = a b d c e f (go as deep as possible)

    0
   / \
  1   2
 /   / \
3   4   5

ajdList : 0 : 1,2
          1 : 3
          2 : 4 5
          3 : 
          4 : 
          5 : 

bfs = 0 1 2 3 4 5
*/

class Traversal{

public:
    // void bfs(std::unordered_map<int, std::vector<int>> &adjList, int start)
    void bfs(std::vector<std::vector<int>> &adjList, int start){
        std::queue<int> vertices;
        std::set<int> visited; //vertex which are visited are stored here

        vertices.push(start);
        visited.insert(start);

        while(!vertices.empty()){
            int curr = vertices.front();
            vertices.pop();
            std::cout << curr << " ";
            for(const auto& joints : adjList[curr]){
                if(visited.find(joints) == visited.end()){
                    vertices.push(joints);
                    visited.insert(joints);
                }
            }
        }
    }

    void dfs(std::vector<std::vector<int>> &adjList, int start){

    }
};

int main(){
    // std::unordered_map<int, std::vector<int>> adjList = { {0, {1, 2}}, {1, {3}} , {2, {4, 5}}, {3, {}}, {4 , {}}, {5, {}}};
    std::vector<std::vector<int>> adjList = { {0, 1, 2}, {1, 3}, {2, 4, 5}, {3}, {4}, {5}};
    Traversal t;
    t.bfs(adjList, 0);
    return 0;
}