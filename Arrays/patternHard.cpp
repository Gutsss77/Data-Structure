#include <iostream>
using namespace std;

void patternHard(int n){
    for(int i = 0; i < (2 * n - 1); i++){
        if(i == 0){
            for(int j = 0; j < (2 * n - 1); j++){
                cout << n << " ";
            }
        }
        if(i == (2 * n - 2)){
            for(int j = 0; j < (2 * n - 1); j++){
                cout << n << " ";
            }
        }
        cout << "\n";
    }
}

int main(){
    patternHard(7);
    return 0;
}