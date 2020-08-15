// problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> prices)
{
    int n = prices.size();
    vector<int> pre(n,0);
    vector<int> post(n+1,0);

    int buy = prices[0];
    for (int i = 1; i < n; i++) {
        buy = min(buy, prices[i]);
        pre[i] = max(pre[i-1], prices[i]-buy);
    }

    int sell = prices[n-1];
    for (int i = n-2; i >= 0; i--) {
        sell = max(sell, prices[i]);
        post[i] = max(post[i+1], sell - prices[i]);
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, pre[i]+post[i+1]);
    }
    return res;
}

int main(void)
{
    cout << maxProfit({1,2,3,4,5}) << endl;
    cout << maxProfit({3,1,0,3,1,1,4}) << endl;
}
