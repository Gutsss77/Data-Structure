//344. Reverse String
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Solution{
public:
    void reverseString(vector<string> &s){
        int start = 0, end = s.size() - 1;
        while(start < end){
            std::swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};

int main(){
    vector<string> s = {"h", "e", "l", "l", "o"};
    for(string i : s){
        cout << i << " ";
    }
    Solution ss; ss.reverseString(s);
    for(string i : s){
        cout << i << " ";
    }
    return 0;
}