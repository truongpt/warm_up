/*
- Problem: https://leetcode.com/problems/decoded-string-at-index
- Solution:
  - if alphabet && K % len == 0 -> current character is result.
  - if number character -> index of K is same as index K % len
  - Time and space complexity
    - TC: O(n)
    - SC: O(1)

- Note:
  - Always existence elegent solution for any problem.
*/

#include <iostream>
using namespace std;

string decodeAtIndex(string S, int K)
{
    long len = 0;
    for (auto c : S) {
        len = (isdigit(c) ? len*(c-'0') : len+1);
    }

    for (int i = S.length()-1; i >= 0; i--) {
        if (isdigit(S[i])) {
            len /= S[i]-'0';
            K %= len;
        } else {
            if (K % len == 0) {
                return string (1, S[i]);
            }
            len--;
        }
    }

    return "";
}

int main(void)
{
    cout << decodeAtIndex("leet2code3", 10) << endl;

}
