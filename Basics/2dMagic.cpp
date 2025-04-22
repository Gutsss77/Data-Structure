#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void normalTraverse(vector<vector<int>> &vec){
    for(auto i : vec){
        for(auto j : i){
            cout << j << " ";
        }
        cout << "\n";
    }
}

void traverseDiagonal(vector<vector<int>> &vec){
    int i = 0;
    for(int i = 0 ; i < vec.size(); i++){
        cout << vec[i][i] << " ";
    }
}

void traverseReverseDiagonal(vector<vector<int>> &vec){
    int i = 0;
    int j = vec.size() - 1;
    while((i < vec.size()) && (j >= 0)){
        cout << vec[i][j] << " ";
        i++;j--;
    }
}

void zigZagTraverse(vector<vector<int>> &vec){
    
}

int main(){
    vector<vector<int>> vec = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3}, 
        {4, 5, 6, 7}
    };
    cout << "Normal traverse : " << "\n";
    normalTraverse(vec);
    cout << "The diagonal element : ";
    traverseDiagonal(vec);
    cout << "\nThe alternate diagonal : ";
    traverseReverseDiagonal(vec);
    cout << "\nZig Zag traversal : ";
    zigZagTraverse(vec);

}


