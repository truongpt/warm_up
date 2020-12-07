/*
- Problem: https://leetcode.com/problems/spiral-matrix-ii/solution/
- Solution:
  - Straigh forward scan matrix with spiral order.
  - Time & Space complexity
    - TC : O(n^2)
    - SC : O(1) 
*/


#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> res(n, vector<int>(n,0));
    int r0 = 0, r1 = n-1;
    int c0 = 0, c1 = n-1;
    int d = 0;
    int val = 1;
    while (true) {
        d = d % 4;

        if (d == 0) {
            for (int i = r0; i <= r1; i++) {
                res[c0][i] = val++;
            }
            c0++;
        } else if (d == 1) {
            for (int i = c0; i <= c1; i++) {
                res[i][r1] = val++;
            }
            r1--;
        } else if (d == 2) {
            for (int i = r1; i >= r0; i--) {
                res[c1][i] = val++;
            }
            c1--;
        } else if (d == 3) {
            for (int i = c1; i >= c0; i--) {
                res[i][r0] = val++;
            }
            r0++;
        }

        d++;
        if (r0 > r1 && c0 > c1) {
            break;
        }
    }
    return res;
}


int main(void)
{
    int n = 5;
    vector<vector<int>> res = generateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << ",";
        }
        cout << endl;
    }

}
