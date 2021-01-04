/*
- Problem: https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/769/
- Solution:
  - check all row, colum & subsquare
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool isValidSodoku(vector<vector<char>>& board)
{
    int N = board.size();
    vector<char> num(10,0);
    // valid colum
    for (auto it : board) {
        memset(num.data(), 0x00, num.size()*sizeof(char));
        for (int i = 0; i < N; i++) {
            if (it[i] != '.' && ++num[it[i]-'0'] > 1) {
                return false;
            };
        }
    }

    for (int j = 0; j < N; j++) {
        memset(num.data(), 0x00, num.size()*sizeof(char));
        for (int i = 0; i < N; i++) {
            if (board[i][j] != '.' && ++num[board[i][j] - '0'] > 1) {
                return false;
            }
        }
    }

    for (int i = 0; i < N; i += 3) {
        for (int j = 0; j <N; j+= 3) {
            // subsquare
            memset(num.data(), 0x00, num.size()*sizeof(char));
            for (int k = i; k < i+3; k++) {
                for (int l = j; l < j+3; l++) {
                    if (board[k][l] != '.' && ++num[board[k][l] - '0'] > 1) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main(void)
{

}
