// problem: https://leetcode.com/problems/coin-change/

#include <iostream>
#include <vector>

using namespace std;

int coinChange(const vector<int>& coins, int amount) {
    vector<int> exchange(amount+1, amount+1);
        
    exchange[0] = 0;
    for (int i = 0; i <= amount; i++) {
        for (auto c : coins) {
            if (i >= c) {
                exchange[i] = min(exchange[i-c] + 1,  exchange[i]);
            }
        }
    }
        
    return exchange[amount] > amount ? -1 :  exchange[amount];
}


int main(void)
{
    cout << coinChange({1,2,5},11) << endl;
}
