// problem: https://leetcode.com/problems/score-after-flipping-matrix/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// brute force
class Solution {
public:
    int calcScore(vector<vector<int>>& A)
        {
            int r = A.size(), c = A[0].size();
            int score = r*(1 << (c-1));
            for (int i = 1; i < c; i++) {
                int cur = 0;
                for (int j = 0; j < r; j++) {
                    cur += (A[j][0] == A[j][i] ? 1 : 0);
                }
                cur = max(cur, r-cur);
                score += cur*(1 << (c-1-i));
            }
            return score;
        }
};

int main(void)
{
    {
        Solution sol;
        vector<vector<int>> m = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
        cout << sol.calcScore(m) << endl;
    }

    {
        Solution sol;
        vector<vector<int>> m = {{1,1,1,1,0},{0,1,0,1,1},{1,0,0,1,1}};
        cout << sol.calcScore(m) << endl;
    }
}
