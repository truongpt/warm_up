/*
- Problem: https://leetcode.com/problems/decode-ways/
- Solution 1:
  - Dynamic programming bottom up.
  - d[i] = if (s[i] valid) d[i-1] + if (s[i-1]+s[i] valid) d[i-2]
  - Time & space complexity
    - TC: O(n)
    - SC: O(n)

- Solution 2:
  - Base on solution 1 + optimize memory.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDecoding1(string s)
{
    if (s.empty() || s[0] == '0') {
        return 0;
    }

    vector<int> dp(s.length(), 0);
    dp[0] = 1;

    for (int i = 1; i < dp.size(); i++) {
        if (s[i] != '0') {
            dp[i] = dp[i-1];
        }

        int elem2 = (s[i-1] - '0')*10 + (s[i] - '0');

        if (s[i-1] != '0' && elem2 <= 26) {
            dp[i] += (i == 1 ? 1 : dp[i-2]);
        }
    }

    return dp[s.length()-1];

}

int numDecoding2(string s)
{
    if (s.empty() || s[0] == '0') {
        return 0;
    }

    int num1 = 1, num2 = 1;
    for (int i = 1; i < s.length(); i++) {
        int cur_num = 0;
        if (s[i] != '0') {
            cur_num = num1;
        }

        int elem2 = (s[i-1] - '0')*10 + (s[i] - '0');

        if (s[i-1] != '0' && elem2 <= 26) {
            cur_num += num2;  
        }

        num2 = num1;
        num1 = cur_num;
    }

    return num1;

}


int main(void)
{
    cout << numDecoding2("226") << endl;
    cout << numDecoding2("0226") << endl;
    cout << numDecoding2("2206") << endl;
}
