// problem: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3450/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B)
        {
            int d = A.size();
            int max_o = 0;
            for (int i = -d+1; i < d ; i++) {
                for (int j = -d+1; j < d; j++) {
                    // calculate overlap
                    int o = 0;
                    for (int x = 0; x < d; x++) {
                        for (int y = 0; y < d; y++) {
                            int a = (x+i >= 0 && x+i < d && y+j >= 0 && y+j < d ? A[x+i][y+j] : 0);
                            o += a*B[x][y];
                        }
                    }
                    max_o = max(max_o, o);
                }
            }
            return max_o;
        }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> A = {{1,1,0},
                             {0,1,0},
                             {0,1,0}};
    vector<vector<int>>  B = {{0,0,0},
                              {0,1,1},
                              {0,0,1}};

    cout << sol.largestOverlap(A,B) << endl;

}
