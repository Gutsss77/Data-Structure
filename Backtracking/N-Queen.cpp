//N-Queen Problem

/*
    Place queen such that no queen attack each other.
    Queen can move in five directions right, left, up, down and diagonally as well

    ex : for 4 queens in 4x4 grid there are two possible combination
        solution 1: 
            . Q . .
            . . . Q
            Q . . .
            . . Q .

        solution 2:
            . . Q .
            Q . . .
            . . . Q
            . Q . .
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<vector<string>> vvs;
typedef vector<string> vs;

class Queen {
    int n;
    int queen;
    vs board;
    vvs solutions;

    bool isValid(int row, int col) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // Check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int row) {
        // base case
        if (row == queen) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            //checks valid position
            if (isValid(row, col)) {
                board[row][col] = 'Q';
                solve(row + 1); //Recursive call
                board[row][col] = '.';
            }
        }
    }

    void printSolutions() {
        int count = 1;
        for (const auto &sol : solutions) {
            cout << "Solution " << count++ << ":\n";
            for (const auto &row : sol) {
                cout << row << "\n";
            }
            cout << "\n";
        }
    }


public:
    Queen(int n, int q) : n(n), queen(q) {
        board = vs(n, string(n, '.'));
    }

    void run() {
        solve(0);
        printSolutions();
    }
};

int main() {
    int n, q; // grid size and no. of queens
    cin >> n >> q;

    if (q > n) {
        cout << "Number of queens cannot exceed board size.\n";
        return 1;
    }

    Queen queen(n, q);
    queen.run();

    return 0;
}
