/*
- Problem:
- Solve: O(n^4) by brute force.
- Good solution at: https://leetcode.com/problems/making-a-large-island/discuss/127015/C%2B%2B-with-picture-O(n*m)
*/

#include <iostream>
#include <vector>
#include <queue>

int largestIsland(std::vector<std::vector<int>>& grid) {

  int row = grid.size(), col = grid[0].size();

  std::vector<std::pair<int,int>> pos = {{1,0},{0,1},{-1,0},{0,-1}};

  int res = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int island = 0;
      std::vector<std::vector<bool>> done(row, std::vector<bool>(col, false));
      std::queue<std::pair<int,int>> q;
      if (grid[i][j] == 0) {
        island = 1;
        q.push({i,j});
        done[i][j] = true;
        while (!q.empty()) {
          auto cur = q.front();
          q.pop();
          for (auto p : pos) {
            int x = cur.first + p.first;
            int y = cur.second + p.second;
            if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] && !done[x][y]) {
              q.push({x,y});
              done[x][y] = true;
              island++;
            }
          }
        }
      }
      res = std::max(island, res);
    }
  }

  return res == 0 ? row*col : res;
}

int main(void) {
  {
    std::vector<std::vector<int>> grid = {{1,0},{0,1}};
    std::cout << largestIsland(grid) << std::endl;
  }
  {
    std::vector<std::vector<int>> grid = {{1,1},{1,1}};
    std::cout << largestIsland(grid) << std::endl;
  }
  {
    std::vector<std::vector<int>> grid = {{0,0},{0,1}};
    std::cout << largestIsland(grid) << std::endl;
  }
}
