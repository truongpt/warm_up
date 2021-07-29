/*
- Problem: https://leetcode.com/problems/01-matrix/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
  int r = mat.size(), c = mat[0].size();
  std::vector<std::vector<int>> res(r, std::vector<int>(c, INT_MAX));
  std::vector<std::pair<int,int>> pos = {{1,0},{0,1},{-1,0},{0,-1}};

  std::queue<std::pair<int,int>> q;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (mat[i][j] == 0) {
        q.push({i,j});
        res[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (auto p : pos) {
      int next_x = cur.first + p.first;
      int next_y = cur.second + p.second;              
      if (next_x >= 0 && next_x < r && next_y >= 0 && next_y < c) {
        if (res[next_x][next_y] > res[cur.first][cur.second]+1) {
          res[next_x][next_y] = res[cur.first][cur.second]+1;
          q.push({next_x, next_y});
        }
      }
    }
  }

  return res;
}

int main(void) {
  std::vector<std::vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
  auto res = updateMatrix(mat);
  for (auto row : res) {
    for (auto elem : row) {
      std::cout << elem << ",";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

}
