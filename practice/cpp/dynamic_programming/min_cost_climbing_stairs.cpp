/*
- Problem: https://leetcode.com/problems/min-cost-climbing-stairs/
- Solution:
  - Dynamic programming bottom up
  - d[i] = min(d[i-1] + cost[i-1], d[i-2] + cost[i-2])
  - Optimize memory
  - Time and space complexity
    - TC: O(n)
    - SC: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int d0 = 0, d1 = 0;
    int d = 0;
    for (int i = 2; i <= cost.size(); i++) {
        d = min(d0 + cost[i-2], d1 + cost[i-1]);
        d0 = d1;
        d1 = d;
    }
        
    return d;
}

int main(void)
{
    vector<int> cost = {10,15,20};
    cout << minCostClimbingStairs(cost) << endl;
}
