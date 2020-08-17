// problem: https://leetcode.com/problems/maximal-square/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// brute force : FUCK
int is_square (vector<vector<char>> m, int si, int sj, int l) {
    for (int i = si; i < l+si; i++) {
        for (int j = sj; j < l+sj; j++) {
            if (m[i][j] != '1') {
                return false;
            }
        }
    }

    return true;
}

int maxSquare(vector<vector<char>> m)
{
    int max_s = 0;
    int r = m.size(), c = m[0].size();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int l = max_s; l <= min(r-i, c-j); l++) {
                if (is_square(m, i,j,l)) {
                    max_s = l;
                }
            }
        }
    }
    return max_s*max_s;
}

//dp
int maxSquareDP(vector<vector<char>> m)
{
    int max_s = 0;
    int r = m.size(), c = m[0].size();
    vector<vector<int>> dp(r+1, vector<int>(c+1,0));

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (m[i-1][j-1] == '1') {
                dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])) + 1;
                max_s = max(max_s,dp[i][j]);
            }
        }
    }
    return max_s*max_s;
}

int main(void)
{
    vector<vector<char>> m = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << maxSquare(m) << endl;
    cout << maxSquareDP(m) << endl;
}
