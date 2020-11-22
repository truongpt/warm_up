/*
- Problem: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
- Consider
  - Input: "eceba"
  - Output: 3
  - Explanation: t is "ece" which its length is 3.

- Solution
  - Sliding windown -> keep maintain max windows

*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int getLongestSubString(string s)
{
    int l = 0, r = 0;
    unordered_map<char, int> m;

    for (r = 0; r < s.length(); r++) {
        m[s[r]]++;
        if (m.size() > 2) {
            if (--m[s[l]] == 0) {
                m.erase(s[l]);
            }
            l++;
        }
    }

    return r - l;
}

int main(void)
{
    cout << getLongestSubString("eceba") << endl;
    cout << getLongestSubString("aabbb") << endl;
}
