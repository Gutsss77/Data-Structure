#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// Function to read a file into a string
std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << "\n";
        return "";
    }

    std::string content, line;
    while (std::getline(file, line)) {
        content += line + '\n';
    }

    return content;
}

// Basic LCS algorithm to compare two strings
int longestCommonSubsequence(const std::string& a, const std::string& b) {
    int m = a.size(), n = b.size();
    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1));

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);

    return dp[m][n];
}

// Main logic
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./plagiarism_checker file1.cpp file2.cpp\n";
        return 1;
    }

    std::string code1 = readFile(argv[1]);
    std::string code2 = readFile(argv[2]);

    if (code1.empty() || code2.empty()) {
        return 1;
    }

    int lcsLen = longestCommonSubsequence(code1, code2);
    int maxLen = std::max(code1.length(), code2.length());

    double similarity = (double)lcsLen / maxLen * 100;

    std::cout << "Similarity: " << similarity << "%\n";
    return 0;
}
