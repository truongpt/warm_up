#include <iostream>
#include <algorithm>

using namespace std;

int getMaxProfitSub (vector<int>& weight, vector<int>& profit, int knapsack, int index)
{
    if (index >= weight.size()) {
        return 0;
    }

    int c1 = 0;
    if (knapsack >= weight[index]) {
        c1 = profit[index] + getMaxProfitSub(weight, profit, knapsack - weight[index], index+1);
    }

    int c2 = getMaxProfitSub(weight, profit, knapsack, index+1);

    return max(c1,c2);
}

int getMaxProfit (vector<int>& weight, vector<int>& profit, int knapsack)
{
    return getMaxProfitSub(weight, profit, knapsack, 0);
}


int main(void)
{
    vector<int> weight = {2, 3, 1, 4};
    vector<int> profit = {4, 5, 3, 7};
    int knapsack = 5;
    cout << getMaxProfit(weight, profit, knapsack) << endl;

    return 0;
}
