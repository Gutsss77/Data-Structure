//1768. Merge Strings Alternately

#include <iostream>
#include <string>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2){
        int i = 0, j = 0;
        int n = word1.length(), m = word2.length();
        std::string merged;
        while(i < n && j < m){
            merged += word1[i++];
            merged += word2[j++];
        }
        while(i < n){
            merged += word1[i++];
        }
        while(j < m){
            merged += word2[j++];
        }
        return merged;
    }
};

int main(){
    std::string word1 = "abc";
    std::string word2 = "def";
    Solution s;
    std::string merged = s.mergeAlternately(word1, word2);

    std::cout << "Merged string is : " << merged << "\n";

    return 0;
}