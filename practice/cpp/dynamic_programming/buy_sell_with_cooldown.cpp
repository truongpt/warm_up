/*
- Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
- Solution:
  - Dynamic programming
    - IDEA: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
  - Add optimize memmory
  - Time and space complexity
    - TC: O(n)
    - SC: O(1)
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
/*
- REST: rest 
- SELL: can sell state
- BUY:  can buy state
*/

int MaxProfit1(vector<int>& p)
{
    if (p.empty()) {
        return 0;
    }
    int n = p.size();
    vector<int> rest(n,0), sell(n,0), buy(n,0);
    rest[0] = 0;
    sell[0] = -p[0];
    buy[0] = 0;

    for (int i = 1; i < p.size(); i++) {
        rest[i] = sell[i-1] + p[i];
        buy[i] = max(buy[i-1], rest[i-1]);
        sell[i] = max(sell[i-1], buy[i-1] - p[i]);
    }

    return max(rest.back(), buy.back());
}

int MaxProfit(vector<int>& p)
{
    if (p.empty()) {
        return 0;
    }

    int rest = 0;
    int sell = -p[0];
    int buy = 0;

    for (int i = 1; i < p.size(); i++) {
        int pre_rest = rest;
        rest = sell + p[i];
        sell = max(sell, buy - p[i]);
        buy = max(buy , pre_rest);
    }

    return max(rest, buy);
}

int main(void)
{
    string p_str, out;
    getline(cin, p_str);
    vector<int> p;
    stringstream ss;
    ss << p_str;
    while (ss >> out) {
        p.push_back(stoi(out));
    }

    for (auto it : p) {
        cout << it << ",";
    }
    cout << endl;

    cout <<"max profit: " << MaxProfit(p) << endl;
    return 0;
}
