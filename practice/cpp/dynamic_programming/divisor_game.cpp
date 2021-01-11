/*
- Problem: https://leetcode.com/problems/divisor-game/
- Solution 1:
  - Dynamic programming bottom up.
  - d[i] = !dp[i-j] || (!dp[i - i/j] && j != 1) with i % j == 0
  - Time and space complexity
    - TC: O(n sqrt n)
    - SC: O(n)

- Solution 2:
  - Resolve the problem by math
  - if N is even -> win
  - if N is odd -> lose
  - Prove
    - if N even, choose 1 -> the competitor will be odd.
    - if N odd
      - if N is 1 -> lose
      - if N != 1 -> all divisor is odd -> the competitor will be even
  - Solution : return N % 2
  - Time and space complexity
    - O(1)

*/

#include <iostream>
#include <vector>
using namespace std;

bool divisorGame(int N)
{
    vector<bool> dp (N+1, false);
    dp[1] = false;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j*j <= i; j++) {
            if (i % j == 0) {
                if (!dp[i-j] || (!dp[i - i/j] && j != 1)) {
                    dp[i] = true;
                }
            }
        }
    }

    return dp[N];
}

int main(void)
{
    cout << divisorGame(10) << endl;
}
