/*
  - Problem: https://leetcode.com/problems/shortest-path-in-binary-matrix/
  - Solution:
  - Thinking the problem as graph
  - Using BSF to find the sortest path.
  - Time and space complexity
  - TC: O(n)  // n is number cell of matrix
  - SC: O(n)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int N = grid.size();
        
    if (grid[0][0]) {
        return -1;
    }
    queue<pair<int,int>> q;
    vector<pair<int,int>> pos = {{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
        
    q.push({0,0});
    vector<vector<bool>> done(N, vector<bool>(N, false));
        
    done[0][0] = true;
    int level = 0;
    while (!q.empty()) {
        int n = q.size();
        level++;
        for (int i = 0; i < n; i++) {
            auto cur = q.front();
            q.pop();        
            if (cur.first == N-1 && cur.second == N-1) {
                return level;
            }
            for (auto p : pos) {
                if (cur.first + p.first >= 0 &&
                    cur.first + p.first < N &&
                    cur.second + p.second >= 0 &&
                    cur.second + p.second < N &&
                    grid[cur.first + p.first][cur.second + p.second] == 0 &&
                    !done[cur.first + p.first][cur.second + p.second]) {
                    done[cur.first + p.first][cur.second + p.second] = true;
                    q.push({cur.first+p.first, cur.second + p.second});
                }
            }
        }
            
    }
        
        
    return -1;
        
}

int main(void)
{
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
    cout << shortestPathBinaryMatrix(grid) << endl;    
}
