/*
- Problem: https://www.hackerrank.com/contests/srin-aadc03/challenges/classic-01-knapsack

- Solution 1 - brute force.
  - Find all combined case -> guaranteed total weight is not bigger than knapsack capacity.
  - For each element, we can select or not select.
  - Choose maximum combined case.
  - Time & memmory
    - TC: O(2^n)
    - SC: O(n)

- Solution 2 - dynamic programming - top down.
  - In solution 1, getMaxProfitSubBF is called a lot of time with same knapsack, index
  - Memoize result of getMaxProfitSubBF for each (knapsack, index)
  - Time & memmory
    - TC: O(m*n) // m  is knapsack capacity.
    - SC: O(m*n)

- Solution 3 - dynamic programming - bottom up.

*/

#include <iostream>
#include <algorithm>

using namespace std;

// Solution 1 - brute force
int getMaxProfitSubBF (vector<int>& weight, vector<int>& profit, int knapsack, int index)
{
    if (index >= weight.size()) {
        return 0;
    }

    int c1 = 0;
    if (knapsack >= weight[index]) {
        c1 = profit[index] + getMaxProfitSubBF(weight, profit, knapsack - weight[index], index+1);
    }

    int c2 = getMaxProfitSubBF(weight, profit, knapsack, index+1);

    return max(c1,c2);
}

int getMaxProfitBF (vector<int>& weight, vector<int>& profit, int knapsack)
{
    return getMaxProfitSubBF(weight, profit, knapsack, 0);
}

// Solution 2 - dynamic programming - top down
int getMaxProfitSubTP (vector<int>& weight,
                       vector<int>& profit,
                       vector<vector<int>>& dp,
                       int knapsack,
                       int index)
{
    if (index >= weight.size()) {
        return 0;
    }

    if (-1 != dp[knapsack][index]) {
        return dp[knapsack][index];
    }

    int c1 = 0;
    if (knapsack >= weight[index]) {
        c1 = profit[index] + getMaxProfitSubTP(weight, profit, dp, knapsack - weight[index], index+1);
    }

    int c2 = getMaxProfitSubTP(weight, profit, dp, knapsack, index+1);

    dp[knapsack][index] =  max(c1,c2);
    return dp[knapsack][index];
}

int getMaxProfitTP (vector<int>& weight, vector<int>& profit, int knapsack)
{
    int index = weight.size()-1;
    vector<vector<int>> dp (knapsack+1, vector<int>(index, -1));
    return getMaxProfitSubTP(weight, profit, dp, knapsack, 0);
}

// Solution 3 - dynamic programming - bottom up
int getMaxProfitBU (vector<int>& weight, vector<int>& profit, int knapsack)
{
    int index = weight.size()-1;
    vector<vector<int>> dp (knapsack+1, vector<int>(index, 0));

    for (int c = 1; c <= knapsack; c++) {
        for (int i = 0; i < index; i++) {
            int d1 = (c >= weight[i] ? dp[c - weight[i]][i-1] : 0);
            int d2 = (i > 0 ? dp[c][i-1] : 0);
            dp[c][i] = max(d1, d2);
        }
    }

    
    return dp[knapsack][index-1];
}

int main(void)
{
    vector<int> weight = {2, 3, 1, 4};
    vector<int> profit = {4, 5, 3, 7};
    int knapsack = 5;
    cout << getMaxProfitBF(weight, profit, knapsack) << endl;
    cout << getMaxProfitTP(weight, profit, knapsack) << endl;
    cout << getMaxProfitBU(weight, profit, knapsack) << endl;

    return 0;
}
