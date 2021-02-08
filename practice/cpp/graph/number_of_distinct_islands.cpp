/*
  - Problem: https://leetcode.com/problems/number-of-distinct-islandsư
  - Solution:
  - Using bfs (or dfs) find sharp of island
  - Move all island to same relative position.
  - Using hash table to remove duplicate
  - Time and space complexity.
  - TC: O(m*n)  // height * width of matrix
  - SC: O(m*n)
*/

#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& id) {
    queue<pair<int,int>> q;
    q.push({i,j});
    grid[i][j] = 0;
        
    vector<pair<int,int>> pos = {{1,0},{-1,0}, {0,1}, {0,-1}};
    int R = grid.size(), C = grid[0].size();
    id.push_back({0,0});

    while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        for (auto p : pos) {
            if (cur.first + p.first >= 0 && cur.first + p.first < R &&
                cur.second + p.second >= 0 && cur.second + p.second < C &&
                grid[cur.first + p.first][cur.second + p.second]) {
                    
                id.push_back({cur.first + p.first-i,cur.second + p.second-j});
                grid[cur.first + p.first][cur.second + p.second] = 0;
                q.push({cur.first + p.first, cur.second + p.second});
            }
        }
            
    }
}
int numDistinctIslands(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }
        
    set<vector<vector<int>>> s;
    int R = grid.size(), C = grid[0].size();
    for (int i = 0; i < R; i++) {
            
        for (int j = 0; j < C; j++) {
            if (grid[i][j]) {
                vector<vector<int>> id = {};
                bfs(grid, i,j, id);
                s.insert(id);
            }
        }
    }
        
    return s.size();
}

int main(void)
{

    vector<vector<int>> grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    cout << numDistinctIslands(grid) << endl;
}
