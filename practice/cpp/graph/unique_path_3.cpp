// problem: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3466/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x = 0, y = 0, all_zero_square = 0;
        int max_r = grid.size();
        int max_c = grid[0].size();
        vector<vector<bool>> done(max_r, vector<bool>(max_c, false));

        // O(m*n)
        for (int i = 0; i < max_r; i++) {
            for (int j = 0; j < max_c; j++) {
                if (1 == grid[i][j]) {
                    x = i, y = j;
                } else if (0 == grid[i][j]) {
                    all_zero_square++;
                }
            }
        }
        int path_cnt = 0;
        dfs(x,y, grid, done, all_zero_square, path_cnt);
        return path_cnt;
    }
    
    void dfs(int x, int y,  vector<vector<int>>& grid, vector<vector<bool>> done, int remain, int& path_cnt) {
        int max_r = grid.size();
        int max_c = grid[0].size();
        if (x < 0 || x >= max_r || y < 0 || y >= max_c) {
            return;
        }
        if (-1 == grid[x][y] || done[x][y]) {
            return;
        }
        if (grid[x][y] == 2 && remain == 0) {
            path_cnt++;
            return;
        }
        done[x][y] = true;

        if (1 != grid[x][y]) remain--;

        dfs(x-1,y,grid,done, remain, path_cnt);
        dfs(x+1,y,grid,done, remain, path_cnt);
        dfs(x,y-1,grid,done, remain, path_cnt);
        dfs(x,y+1,grid,done, remain, path_cnt);
    }
};

int main(void)
{
    vector<vector<int>> v = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    Solution sol;
    cout << sol.uniquePathsIII(v) << endl;
}
