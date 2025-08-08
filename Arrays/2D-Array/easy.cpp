//Matrix implementation and its problem
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

//class to create matrix and display it
class Matrix{
private:
    int row;
    int col;
    vector<vector<int>> matrix;
public:
    Matrix(int row, int col) : row(row), col(col), matrix(row, vector<int>(col)) {}

    vector<vector<int>> createMatrix(){
        return matrix; //initialize a matrix filled with zeros
    }

    vector<vector<int>> insertIntoMatrix(){
        for(int i = 0; i < row; i++){
            cout << "Enter row " << i + 1 << " : ";
            for(int j = 0; j < col; j++){
                cin >> matrix[i][j];
            }
        }
        return matrix;
    }

    void displayMatrix(){
        cout << "Matrix is : " << endl;
        for(const auto &rowVec : matrix){
            for(int i : rowVec){
                cout << i << " ";
            }
            cout << endl;
        }
    }
};

//Different problems on matrix
class Problem{
public:
    //Sum of matrix elements
    int sumOfElements(vector<vector<int>> &matrix){
        int sum = 0;
        for(auto &row : matrix){
            for(int i : row){
                sum += i;
            }
        }
        return sum;
    }
};

int main(){
    Matrix m(3,3);
    Problem p;
    // m.createMatrix();
    vector<vector<int>> matrix = m.insertIntoMatrix();
    m.displayMatrix();
    cout << "Sum of matrix element is : " << p.sumOfElements(matrix) << endl;
    return 0;
}