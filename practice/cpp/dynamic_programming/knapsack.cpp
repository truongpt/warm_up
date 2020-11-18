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
  - From solution 2 -> max profit of (knapsack, index) problem is repeated as subproblem.
  - dp[knapsack][index] is max profit of knapsack with index item.
  - dp[knapsack][index] = max(select index, not select index);
    - dp[knapsack][index] =  max(dp[knapsack - weight[index]][index-1] + profit[index], dp[knapsack][index-1]);
  - Time & memmory
    - TC: O(m*n) // m  is knapsack capacity.
    - SC: O(m*n)

- Solution 4 = solution 3 + optimize
  - From solition 3: dp[knapsack][index] is calculated from previous index -> dp[knapsack][index-1]
  - Consider reduce size of dp[knapsack][index].
    - dp[knapsack][index % 2] =  max(dp[knapsack - weight[index]][(index-1)%2] + profit[index], dp[knapsack][(index-1)%2]);
  - Time & memmory
    - TC: O(m*n) // m  is knapsack capacity.
    - SC: O(m)

- Performance.
  - Use case at main function.
  - Result
    - Solution 1:  565.083 (second)
    - Solution 2:  0.0007568 (second)
    - Solution 3:  0.0004755 (second)
    - Solution 4:  0.0004258 (second)

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include "../utility/perf.h"

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
    vector<vector<int>> dp (knapsack+1, vector<int>(weight.size(), -1));
    return getMaxProfitSubTP(weight, profit, dp, knapsack, 0);
}

// Solution 3 - dynamic programming - bottom up
int getMaxProfitBU (vector<int>& weight, vector<int>& profit, int knapsack)
{
    vector<vector<int>> dp (knapsack+1, vector<int>(weight.size(), 0));

    for (int c = 1; c <= knapsack; c++) {
        for (int i = 0; i < weight.size(); i++) {
            int d1 = (c >= weight[i] ? (profit[i] + dp[c - weight[i]][i-1]) : 0);
            int d2 = (i > 0 ? dp[c][i-1] : 0);
            dp[c][i] = max(d1, d2);
        }
    }

    
    return dp[knapsack][weight.size()-1];
}

// Solution 3 + optimize memory
int getMaxProfitBUO (vector<int>& weight, vector<int>& profit, int knapsack)
{
    vector<vector<int>> dp (knapsack+1, vector<int>(2, 0));
    for (int i = 0; i < weight.size(); i++) {
        for (int c = 1; c <= knapsack; c++) {
            int d1 = (c >= weight[i] ? (profit[i] + dp[c - weight[i]][i%2]) : 0);
            int d2 = (i > 0 ? dp[c][i%2] : 0);
            dp[c][(i+1)%2] = max(d1, d2);
        }
    }   
    return max(dp[knapsack][0], dp[knapsack][1]);
}

int main(void)
{

    int num = 70;

    vector<int> weight; // 1 - 50
    vector<int> profit; // 1 - 10
    int knapsack = 25 * num / 10;

    int min_value = 1, max_value = 50, rand_value = 0;
    for (int i = 0; i < num; i++) {
        rand_value = min_value + (rand() % static_cast<int>(max_value - min_value + 1));
        weight.push_back(rand_value);
    }

    min_value = 1, max_value = 10, rand_value = 0;
    for (int i = 0; i < num; i++) {
        rand_value = min_value + (rand() % static_cast<int>(max_value - min_value + 1));
        profit.push_back(rand_value);
    }

    {
        TIME_SCOPE("getMaxProfitBF");
        cout << getMaxProfitBF(weight, profit, knapsack) << endl;
    }

    {
        TIME_SCOPE("getMaxProfitTP");
        cout << getMaxProfitTP(weight, profit, knapsack) << endl;
    }

    {
        TIME_SCOPE("getMaxProfitBU");
        cout << getMaxProfitBU(weight, profit, knapsack) << endl;
    }

    {
        TIME_SCOPE("getMaxProfitBUO");
        cout << getMaxProfitBUO(weight, profit, knapsack) << endl;
    }    
    return 0;
}
