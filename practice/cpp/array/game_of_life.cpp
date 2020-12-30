/*
- Problem: https://leetcode.com/problems/game-of-life/
- Solution: 
  - Brute force to check each element with rule to decide next generate is live or die
  - Reduce memmory by still keep current status by above strategy.
    - live -> die  : 01b
    - live -> live : 11b
    - die  -> live : 10b
    - die  -> die  : 00b
  - Time and space complexity
    - TC : O(n)
    - SC : O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int getNeibough(vector<vector<int>>& board, int x, int y) {
    int live = 0;
    int R = board.size();
    int C = board[0].size();
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            if (0 <= x+i && x+i < R && 0 <= y+j && y+j < C) {
                if (board[x+i][y+j] & 1) {
                    live++;
                }
            }
        }
    }
    return live;
}

void gameOfLife(vector<vector<int>>& board) {
    if (board.empty() || board[0].empty()) {
        return;
    }

    int R = board.size();
    int C = board[0].size();
    /*
      Any live cell with fewer than two live neighbors dies as if caused by under-population.
      Any live cell with two or three live neighbors lives on to the next generation.
      Any live cell with more than three live neighbors dies, as if by over-population.
      Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
    */
    int live = 0;
    for (int x = 0; x < R; x++ ) {
        for (int y = 0; y < C; y++) {
            live = getNeibough(board, x , y);
            if (board[x][y]) {
                board[x][y] = 3;
                if (live < 2 || live > 3) {
                    board[x][y] = 1;
                }
            } else {
                if (live == 3) {
                    board[x][y] = 2;
                }
            }
        }
    }

    for (int x = 0; x < R; x++ ) {
        for (int y = 0; y < C; y++) {
            board[x][y] = board[x][y] >> 1;
        }
    }
}

int main(void)
{
    vector<vector<int>> arr = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    cout << "-----cur-----" << endl;
    for (auto a : arr) {
        for (auto it : a) {
            cout << it << ",";
        }
        cout << endl;
    }
    cout << "-----next------" << endl;
    gameOfLife(arr);

    for (auto a : arr) {
        for (auto it : a) {
            cout << it << ",";
        }
        cout << endl;
    }
}
