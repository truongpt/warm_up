// problem: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3397/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static bool exist(vector<vector<char>> board, string word)
        {
            int r = board.size();
            int c = board[0].size();
            vector<vector<bool>> done(r, vector<bool>(c, false));
            
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if(dfs(board, i, j, done, word, 0)) {
                        return true;
                    }
                }
            }
            return false;
        }
    static bool dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& done, string word, int index)
        {

            int r = board.size();
            int c = board[0].size();

            if (index >= word.length()) {
                return true;
            }
            if (i >= r || i < 0 || j >= c || j < 0) {
                return false;
            }

            if (done[i][j]) {
                return false;
            }
            if (word[index] != board[i][j]) {
                return false;
            }

            vector<pair<int,int>> pos = vector<pair<int,int>> {{0,1},{1,0},{-1,0},{0,-1}};

            done[i][j] = true;
            for (auto p : pos) {
                if (dfs(board, i+p.first, j+p.second, done, word, index+1)) {
                    return true;
                }
            }

            done[i][j] = false;
            
            return false;
        }
};


int main(void)
{

    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCDE";

    cout << Solution::exist(board, word) << endl;
    return 0;
}
