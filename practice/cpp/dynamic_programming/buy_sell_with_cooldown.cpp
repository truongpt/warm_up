// problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// IDEA: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
int MaxProfit(vector<int>& p)
{
    int n = p.size();
    int rest = 0, buy = -p[0], sell = INT_MIN;
    for (int i = 1; i < n; i++) {
        int pre_buy = buy;
        buy = max(rest-p[i], buy);
        rest = max(rest, sell);
        sell = pre_buy + p[i];
    }

    return max(sell, rest);
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
