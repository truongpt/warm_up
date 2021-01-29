/*
- Problem: https://leetcode.com/problems/coin-change/
- Solution:
  - Dynamic programming.
    - d[amount] is result coresponding to amount
    - d[i] = min(d[i - coin]+1, d[i]) with coin is all element of coins.
  - Time and space complexity
    - TC: O(n * m), n is amount, m is size of coins.
    - SC: O(n)
  
*/

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
