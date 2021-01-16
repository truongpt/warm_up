/*
- Problem: https://leetcode.com/problems/perfect-squares/
- Solution:
  - Dynamic programming: d[i] = min(d[i - j*j] +1, d[i]) with j*j <= i
  - Time and space complexity
    - TC: O(n sqrt n)
    - SC: O(n)
*/

#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int numSquares(int n)
{
    vector<int> d(n+1,INT_MAX);
    d[1] = 1;
    d[0] = 0;
    for (int i = 2; i <= n ; i++) {
        for (int j = 1; j*j <= i; j++) {
            d[i] = min(d[i-j*j]+1, d[i]);
        }
    }

    return d.back();
}

int main(void)
{
    cout << numSquares(12) << endl;
    cout << numSquares(13) << endl;
    cout << numSquares(1) << endl;

}
