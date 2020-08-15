// problem: https://leetcode.com/problems/stone-game/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool stoneGame(vector<int> piles)
{
    int n = piles.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));

    for (int d = 1; d <= n; d++) {
        for (int i = 0, j = d-1; j < n; i++,j++) {
            if (d % 2) {
                dp[i][j] = min(-piles[i]+dp[i+1][j], -piles[i]+ (j>0 ? dp[i][j-1] : 0) );
            } else {
                dp[i][j] = max(piles[i]+dp[i+1][j], piles[i]+ (j>0 ? dp[i][j-1] : 0) );
            }
        }
    }

    return dp[0][n-1] > 0;

}

int main(void)
{
    cout << stoneGame({5,4,3,5}) << endl;
}
