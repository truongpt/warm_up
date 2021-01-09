/*
- Problem: https://leetcode.com/problems/climbing-stairs
- Solution:
  - Liner Dynamic Programming
  - d[i] is number way to go to step i
  - d[i] = d[i-1] + d[i-2]
  - At each time, i only depend on i-1, i-2 -> optimize memory
  - Time and space complexity
    - TC: O(n)
    - SC: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n)
{
    int d0 = 0, d1 = 1;
    int d = 0;
    for (int i = 1; i <= n; i++) {
        d = d0 + d1;
        d0 = d1, d1 = d;
    }

    return d;
}

int main(void)
{
    cout << climbStairs(10) << endl;
}
