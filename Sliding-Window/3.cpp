//3. Longest Substring Without Repeating Characters
#include <iostream>
#include <string>
#include <unordered_set>

using std::cout;
using std::max;
using std::string;
using std::unordered_set;

class SubString {
public:

    //brute force (O(n * n))
    // int lengthOfLongestSubstring(string s) {
    //     int n = s.length();
    //     int maxLen = 0;

    //     for (int i = 0; i < n; i++) {
    //         unordered_set<char> seen;
    //         for (int j = i; j < n; j++) {
    //             if (seen.count(s[j])) break;
    //             seen.insert(s[j]);
    //             maxLen = max(maxLen, j - i + 1);
    //         }
    //     }
    //     return maxLen;
    // }

    //optimized force O(n)
    int lengthOfLongestSubstring(string s){
        int n = s.length();
        int start = 0, end = 0;
        int maxLen = 0;
        unordered_set<char> seen;
        while(end < n){
            if(!seen.count(s[end])){
                seen.insert(s[end]);
                maxLen = max(maxLen, end - start + 1);
                end++;
            }else{
                seen.erase(s[start]);
                start++;
            }
        }
        return maxLen;
    }
};


int main(){
    string s = "abcabcbb";
    SubString ss;
    int k = ss.lengthOfLongestSubstring(s);
    cout << k;
    return 0;
}