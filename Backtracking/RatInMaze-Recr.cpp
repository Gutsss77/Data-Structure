//Rat in a Maze problem 
/*
    Recursive solution : the mouse can move only right and down.
*/

/*
    Given N x N grid there is a mouse at (0, 0) it has to reach (N-1, N-1) column
    find the path in the grid.

    -> Block with '0' means the path is blocked and '1' means path is open.
    -> If the start or end is blocked no possible solution exists.

    ex : 4x4 grid
                    1 0 1 1
                    1 1 0 0
                    0 1 0 1
                    1 1 1 1

    Possible solution is : 
                    1 x x x 
                    1 1 x x
                    x 1 x x
                    x 1 1 1 
*/

#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;

class Maze{
    vvi maze; //Given maze
    vvi visited; //track the visited
    vvi solution; //solution path

    int n; //size of grid

    //Should i go or should i not
    bool isSafe(int i, int j){
        return (i >= 0 &&
                i < n &&
                j >= 0 &&
                j < n &&
                maze[i][j] == 1 &&
                !visited[i][j]);
    }

    bool resultSolution(int i, int j){
        if((i == n - 1) && (j == n - 1)){
            solution[i][j] = 1;
            return true;
        }

        visited[i][j] = 1;
        solution[i][j] = 1;

        //for right move
        if(isSafe(i, j + 1) && resultSolution(i, j + 1)){
            return true;
        }

        //for down move
        if(isSafe(i + 1, j) && resultSolution(i + 1, j)){
            return true;
        }

        return false;
    }

    //print the resultant route of the maze
    void printSolution(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << solution[i][j] << " ";
            }
            cout << "\n";
        }
    }

public:

    Maze(vvi maze) : maze(maze), n(maze.size()){
    visited = vvi(n, vector<int>(n, 0)); // creates a 2D vector of n x n filled with '0'
    solution = vvi(n, vector<int>(n, 0)); // same as above
    }

    void solve(){
        //Edge case where starting or ending block is blocked!
        if(maze[0][0] == 0 || maze[n - 1][n - 1] == 0){
            cout << "Start / End is blocked!\n";
            return;
        }

        if(resultSolution(0, 0)){ //Checks if solution exists(starts from (0, 0)) or not if yes,
            printSolution();  //print the solution
        }else{
            cout << "No solution exists!\n"; //if no, no possible solution exists
        }
    }

};

// Input maze
void inputMaze(vvi& maze, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> maze[i][j];
        }
    }
}

int main(){
    int n;
    cin >> n;
    vvi maze(n, vector<int>(n)); // n x n grid

    inputMaze(maze, n);
    Maze m(maze);
    m.solve();

    // vvi maze = {{1, 0, 1, 1}, 
    //             {1, 1, 0, 0}, 
    //             {0, 1, 0, 1}, 
    //             {1, 1, 1 ,1 }};

    // Maze m(maze);
    // m.solve();
    
    return 0;
}