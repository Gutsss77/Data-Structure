//17. Letter Combinations of a Phone Number
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {

    void solution(string &digits, int index, const unordered_map<char, string> &phoneMap, string &current, vector<string> &result){
        //Base case
        if(index == digits.size()){
            result.push_back(current);
            return;
        }

        char digit = digits[index];

        const string &letter = phoneMap.at(digit);

        for(char i : letter){
            current.push_back(i);
            solution(digits, index + 1, phoneMap, current, result);
            current.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        unordered_map<char, string> phoneMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> result;
        string current = "";

        solution(digits, 0, phoneMap, current, result);

        return result;


    }
};

int main(){
    string digit;
    cin >> digit;

    Solution s;
    vector<string> ans = s.letterCombinations(digit);

    for(auto s : ans){
        cout << s << " ";
    }
    cout << "\n";
    return 0;
}