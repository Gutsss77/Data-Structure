#include <algorithm>
#include <iostream>
#include <string>

using std::cout;
using std::rotate;
using std::string;

class Solution {
public:
    int minRotation(string s, char c, int k, int f) {
        int rotateCount = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            int charf = 0;
            for (int j = 0; j < k && j < n; ++j) {
                if (s[j] == c) {
                    charf++;
                }
            }

            if (charf == f) {
                rotateCount++;
            }
            rotate(s.rbegin(), s.rbegin() + 1, s.rend());
        }
        return rotateCount;
    }
};

int main() {
    string s = "nikhil";
    int k = 4;
    char c = 'i';
    int freq = 2;

    Solution obj1;
    int result = obj1.minRotation(s, c, k, freq);
    cout << result << "\n";

    return 0;
}
