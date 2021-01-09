/*
- Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
- Solution:
  - Using 2 state BUY and SELL, and result is max value at SELL state 
  - Find max value for each state.
    - for BUY: comparing buy and NOT buy
    - for SELL: comparing sell and NOT sell with pre state must be buy
  - Time and space complexity
    - TC: O(n)
    - SC: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int sell = 0, buy = INT_MIN;
    for (auto price : prices) {
        buy = max(buy, -price);
        sell = max(sell, buy + price);
    }

    return sell;
}

int main(void)
{
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;
}
