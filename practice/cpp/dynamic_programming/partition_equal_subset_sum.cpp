/*
- Problem: https://leetcode.com/problems/partition-equal-subset-sum/
Given a non-empty array nums containing only positive integers, find 
if the array can be partitioned into two subsets such that the sum 
of elements in both subsets is equal.

 
- Example 1:
  - Input: nums = [1,5,11,5]
  - Output: true
  - Explanation: The array can be partitioned as [1, 5, 5] and [11].

- Clarify:
  - target = 1/2 sum all elements -> find set elements, which sum of them == target.
  - Brute force -> find all set of elements -> check existence sum of them == target or not.
  - Top-down -> use memoization approach
  - Bottom-up

- Solution bottom-up
  - bool dp[index][target] -> true if existence set of elem 0 ~ index, sum of them == target.
  - Initialize dp[0][target], d[index][0]
  - dp[index][target] = dp[index-1][target] || dp[index-1][target - arr[i]]
  - Optimize memory.

*/
#include <iostream>
#include <vector>
using namespace std;

bool canPartitionEqual(vector<int>& arr)
{
    int sum = 0;
    for (auto it : arr) {
        sum += it;
    }

    if (sum % 2) return false;
    sum /= 2;

    vector<vector<bool>> dp(2, vector<bool>(sum+1, false));
    dp[0][0] = dp[1][0] = true;

    for (int i = 1; i <= arr.size(); i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i%2][j] = dp[(i-1) % 2][j] || (j >= arr[i-1] ? dp[(i-1)%2][j - arr[i-1]] : false);
        }
    }
    return dp[arr.size() % 2][sum];
}

int main(void)
{
    {
        vector<int> arr = {1,5,11,5};
        cout << canPartitionEqual(arr) << endl;
    }
}

