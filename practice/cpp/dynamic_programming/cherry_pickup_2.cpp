/*
- Problem: https://leetcode.com/problems/cherry-pickup-ii/
- Solution:
  - For each robot, he will be next row with 3 position of col-1, col, col+1
  - Brute force by recursion to check all possible cases.
  - Remove overlap by memoization -> dynamic programming top down
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> vvi;
typedef unordered_map<int, unordered_map<int,int>> mmi;

#define COL_MAX 70

int pickup(vvi& grid, mmi& dp, int row, int col1, int col2)
{
    if (row >= grid.size() ||
        col1 < 0 || col1 >= grid[0].size() ||
        col2 < 0 || col2 >= grid[0].size()) {
        return 0;
    }

    if (dp[row*COL_MAX + col1][row*COL_MAX + col2]) {
        return dp[row*COL_MAX + col1][row*COL_MAX + col2];
    }

    int cur_cherry = 0;
    if (col1 == col2) {
        cur_cherry = grid[row][col1];
    } else {
        cur_cherry = grid[row][col1] + grid[row][col2];
    }

    int next_cherry = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            next_cherry = max(next_cherry, pickup(grid, dp, row+1, col1+i, col2+j));
        }
    }

    dp[row*COL_MAX + col1][row*COL_MAX + col2] = cur_cherry + next_cherry;
    return dp[row*COL_MAX + col1][row*COL_MAX + col2];
}

int cherryPickup(vvi& grid)
{
    if (grid.empty()) {
        return 0;
    }
    mmi dp;
    return pickup(grid, dp, 0, 0, grid[0].size()-1);
}

int main(void)
{
    vvi grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout << cherryPickup(grid) << endl;

}
