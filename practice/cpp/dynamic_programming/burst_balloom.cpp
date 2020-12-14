/*
- Problem: https://leetcode.com/problems/burst-balloons/
- Intuition
  ```
  1. [3,1,5,8] -> add 1 to start and end [1,3,1,5,8,1]
  2. Scan from index 1 to index size()-2
     [1,3,1,5,8,1]  = arr[0]*arr[1]*arr[2]  +   [1,3]  + [3,1,5,8,1]
        ^
  ```
- Solution:
  - Bust each elem -> separate left side  & right side

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxCoinsRecursion(vector<int>& arr, vector<vector<int>>& dp, int left, int right)
{
    if (left+1 == right) {
        return 0;
    }

    if (dp[left][right] > 0) {
        return dp[left][right];
    }

    int ans = 0;
    for (int i = left+1; i < right; i++) {
        ans = max(ans, arr[left]*arr[i]*arr[right]
                  + maxCoinsRecursion(arr, dp, left, i)
                  + maxCoinsRecursion(arr, dp, i, right));

    }
    dp[left][right] = ans;
    return ans;
}

int maxCoins(vector<int>& nums)
{
    int n = nums.size()+2;
    vector<int> arr(n, 1);
    for (int i = 0; i < nums.size(); i++) {
        arr[i+1] = nums[i];
    }
    vector<vector<int>> dp (n,vector<int>(n,0));

    return maxCoinsRecursion(arr, dp, 0, n-1);
}

int main(void)
{
    vector<int> nums = {3,1,5,8};
    cout << maxCoins(nums) << endl;
}
