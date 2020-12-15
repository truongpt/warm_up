/*
- Problem: https://leetcode.com/problems/palindrome-partitioning/
- Solution:
  - Using dynamic programming to store all position with can be make pardindome string.
  - Backtracking to get all combination.
  - Time & space complexity
    - https://stackoverflow.com/questions/24591616/whats-the-time-complexity-of-this-algorithm-for-palindrome-partitioning
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void parlindromePartition(string s, vector<vector<bool>>& dp, int start_index,
                          vector<string> elem, vector<vector<string>>& res)
{
    if (start_index >= s.length()) {
        res.push_back(elem);
    }

    for (int i = start_index; i < s.length(); i++) {
        if (dp[start_index][i]) {
            elem.push_back(s.substr(i, i - start_index + 1));
            parlindromePartition(s, dp, i+1, elem, res);
            elem.pop_back();
        }
    }
}

vector<vector<string>> parlindromePartition(string s)
{
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = i+1; j < n; j++) {
            if (s[i] == s[j]) {
                if (j == i+1 || dp[i+1][j-1]) {
                    dp[i][j] = true;
                }
            }
        }
    }
    vector<vector<string>> res = {};
    vector<string> elem = {};

    parlindromePartition(s, dp, 0, elem, res);
    return res;
}


int main(void)
{
    vector<vector<string>> res = parlindromePartition("aab");
    for (auto v : res) {
        for (auto elem : v) {
            cout << elem << ",";
        }
        cout << endl;
    }
}
