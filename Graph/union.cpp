#include <iostream>
#include <vector>
using namespace std;

class DisjointSet{
private:
    vector<int> leaders;
public:
    DisjointSet(int number = 5){
        leaders.resize(number); //For any vertex, the index is vertex and value at index is its leaders
        for(int i = 0; i < number; i++)
            leaders[i] = i; //Initial state
    }

    int find(int x){
        if( x == leaders[x]){
            return x;
        }
        return (leaders[x]);
    }

    void union_l(int x, int y){
        int xLeader = find(x);
        int yLeader = find(y);
        if(xLeader == yLeader){
            return;
        }else{ //y will be joint to x
            leaders[yLeader] = xLeader;
        }
    }

    void displayAllLeaders(){
        cout << "\n";
        for(int i = 0; i < leaders.size(); i++){
            cout << "Vertex " << i << " has leader : " << leaders[i] << "\n";
        }
    }
};


int main(){

    DisjointSet djs(3);
    djs.displayAllLeaders();
    djs.union_l(1, 2);
    djs.displayAllLeaders();
    cout << "Leader of " << 2 << " is : " << djs.find(2);

    return 0;
}